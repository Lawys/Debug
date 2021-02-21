#include "header.h"

void		ft_action_on(variable_list *l, int group, int c, char *str)
{
	int value;

	value = (int)ft_atoi(l, str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		l->g.action_statement[value] = 2;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_off(variable_list *l, int group, int c, char *str)
{
	int value;

	value = (int)ft_atoi(l, str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		l->g.action_statement[value] = 3;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_area_end(variable_list *l)
{
	if (l->p.item[5] == 2)
		l->menu_mode = 4;
}

void		ft_action_area_loot(variable_list *l, int group, int c, char *str)
{
	int value;

	value = (int)ft_atoi(l, str, &c);
	if (str[c] == ';' && value >= 0 && value < 9)
	{
		l->p.item[value] = 1;
		l->g.exist[group] = 0;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_area_heal(variable_list *l, int group, int c, char *str)
{
	int value;

	value = (int)ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		l->p.hp += value;
		if (l->p.hp > 100)
			l->p.hp = 100;
		l->g.exist[group] = 0;
		ft_action_start(l, group, ++c, str);
	}
}
