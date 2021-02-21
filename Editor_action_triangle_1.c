#include "header.h"

void		ft_map_editor_triangle_action_triangle(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->triangle_select, 12,
			l->triangle_number - 1);
}

void		ft_map_editor_triangle_action_area(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.area[l->triangle_select], 1,
			MAX_AREAS - 1);
}

void		ft_map_editor_triangle_action_group(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.group[l->triangle_select], 1,
			MAX_GROUPS - 1);
}

void		ft_map_editor_triangle_action_position_x_all(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.x1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}

void		ft_map_editor_triangle_action_position_y_all(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.y1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}
