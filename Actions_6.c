#include "header.h"

void		ft_action_start_action_timer_negative_time(variable_list* l, int group, int c, char* str)
{
	int value;

	value = (int)ft_atoi(l, str, &c);
	if (value >= 0 && str[c] == ';')
	{
		l->g.action_timer[group] = value;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_start(variable_list* l, int group, int c, char* str)
{
	if (l->g.action_timer[group] >= 0)
		ft_action_start_action_timer_positive(l, group, c, str);
	else
	{
		if (ft_strings_compare(str, "!", c))
			if (str[++c] == ';')
			{
				if (l->g.action_statement[group] == 0 ||
					l->g.action_statement[group] == 2)
					l->g.action_statement[group] = 1;
				else if (l->g.action_statement[group] == 1 ||
					l->g.action_statement[group] == 3)
					l->g.action_statement[group] = 0;
				return;
			}
		if (ft_strings_compare(str, "KEY>", c))
			ft_action_start_action_timer_negative_key(l, group, &c, str);
		if (ft_strings_compare(str, "TIME>", c))
			ft_action_start_action_timer_negative_time(l, group, c, str);
	}
}

void		ft_action_enable(variable_list* l, int group)
{
	int c;

	c = 0;
	ft_action_start(l, group, c, l->g.action_enable[group]);
	if (l->g.action_timer[group] >= 0)
		if (--l->g.action_timer[group] < 0 &&
			(l->g.action_statement[group] == 1 ||
				l->g.action_statement[group] == 3))
			l->g.action_statement[group] = 0;
}

void		ft_action_disable(variable_list* l, int group)
{
	int c;

	c = 0;
	ft_action_start(l, group, c, l->g.action_disable[group]);
	if (l->g.action_timer[group] >= 0)
		if (--l->g.action_timer[group] < 0 &&
			(l->g.action_statement[group] == 0 ||
				l->g.action_statement[group] == 2))
			l->g.action_statement[group] = 1;
}

void		ft_action(variable_list* l)
{
	int group;

	group = -1;
	while (++group < MAX_GROUPS)
		if (l->g.exist[group])
		{
			if (l->g.action_enable[group][0] != '\0' &&
				((l->g.action_statement[group] == 1 &&
					l->g.action_enable[group][0] == '!') ||
					l->g.action_statement[group] == 3))
				ft_action_enable(l, group);
			else if (l->g.action_disable[group][0] != '\0' &&
				((l->g.action_statement[group] == 0 &&
					l->g.action_disable[group][0] == '!') ||
					l->g.action_statement[group] == 2))
				ft_action_disable(l, group);
		}
}
