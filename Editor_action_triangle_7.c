#include "header.h"

void		ft_map_editor_triangle_action_texture_light(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_light[l->triangle_select],
			0, 100);
}

void		ft_map_editor_triangle_action_texture_opacity(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_opacity[l->triangle_select],
			10, 100);
}

void		ft_map_editor_triangle_action_texture_size_x(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_size_x[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_texture_size_y(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_size_y[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_texture_size_stretch(variable_list* l)
{
	double dist12;
	double dist13;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		l->t.texture_size_y[ts] = 100 / (dist13 / 100);
		l->action_select[l->menu_select][l->action] = 0;
	}
}
