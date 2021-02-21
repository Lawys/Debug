#include "header.h"

void		ft_map_editor_area_action_link6(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link6[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_delete_set_values(variable_list* l, int ts)
{
	int tn;

	tn = --l->triangle_number;
	l->t.area[ts] = l->t.area[tn];
	l->t.group[ts] = l->t.group[tn];
	l->t.x1[ts] = l->t.x1[tn];
	l->t.y1[ts] = l->t.y1[tn];
	l->t.z1[ts] = l->t.z1[tn];
	l->t.x2[ts] = l->t.x2[tn];
	l->t.y2[ts] = l->t.y2[tn];
	l->t.z2[ts] = l->t.z2[tn];
	l->t.x3[ts] = l->t.x3[tn];
	l->t.y3[ts] = l->t.y3[tn];
	l->t.z3[ts] = l->t.z3[tn];
	l->t.texture_size_x[ts] = l->t.texture_size_x[tn];
	l->t.texture_size_y[ts] = l->t.texture_size_y[tn];
	l->t.texture_light[ts] = l->t.texture_light[tn];
	l->t.texture_shift_x[ts] = l->t.texture_shift_x[tn];
	l->t.texture_shift_y[ts] = l->t.texture_shift_y[tn];
	l->t.texture_id[ts] = l->t.texture_id[tn];
	l->t.texture_opacity[ts] = l->t.texture_opacity[tn];
	l->t.texture_sides[ts] = l->t.texture_sides[tn];
}

void		ft_map_editor_area_action_delete(variable_list* l)
{
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		ts = -1;
		while (++ts < l->triangle_number)
			if (l->t.area[ts] == l->area_select)
			{
				ft_map_editor_area_action_delete_set_values(l, ts);
				ts--;
			}
		l->area_select = -1;
	}
}
