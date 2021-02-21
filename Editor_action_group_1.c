#include "header.h"

void		ft_map_editor_group_action_select_group(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->group_select, 1, MAX_GROUPS - 1);
}

void		ft_map_editor_group_action_switch_group(variable_list *l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->me.group_switch_value, 1, MAX_GROUPS - 1);
		if (l->i.state[40] || l->i.state[88])
		{
			i = 0;
			while (i < l->triangle_number)
			{
				if (l->t.group[i] == l->group_select)
					l->t.group[i] = l->me.group_switch_value;
				i++;
			}
			l->group_select = l->me.group_switch_value;
			l->i.state[40] = 0;
			l->i.state[88] = 0;
			l->me.group_switch_value = 1;
		}
	}
}

void		ft_map_editor_group_action_position_x_up(variable_list *l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.x1[i] += l->me.mult / 100;
			l->t.x2[i] += l->me.mult / 100;
			l->t.x3[i] += l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_group_action_position_x_down(variable_list *l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.x1[i] -= l->me.mult / 100;
			l->t.x2[i] -= l->me.mult / 100;
			l->t.x3[i] -= l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_group_action_position_x(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_group_action_position_x_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_group_action_position_x_down(l);
	}
}
