/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_area_7.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:49 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_action_link6(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link6[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_delete_set_values(t_variable_list *l,
int ts)
{
	--l->triangle_number;
	l->t.area[ts] = l->t.area[l->triangle_number];
	l->t.group[ts] = l->t.group[l->triangle_number];
	l->g.npc[l->t.group[ts]] = 0;
	l->g.no_block[l->t.group[ts]] = 0;
	l->g.sprite[l->t.group[ts]] = 0;
	l->g.interact[l->t.group[ts]] = 0;
	l->t.x1[ts] = l->t.x1[l->triangle_number];
	l->t.y1[ts] = l->t.y1[l->triangle_number];
	l->t.z1[ts] = l->t.z1[l->triangle_number];
	l->t.x2[ts] = l->t.x2[l->triangle_number];
	l->t.y2[ts] = l->t.y2[l->triangle_number];
	l->t.z2[ts] = l->t.z2[l->triangle_number];
	l->t.x3[ts] = l->t.x3[l->triangle_number];
	l->t.y3[ts] = l->t.y3[l->triangle_number];
	l->t.z3[ts] = l->t.z3[l->triangle_number];
	l->t.texture_size_x[ts] = l->t.texture_size_x[l->triangle_number];
	l->t.texture_size_y[ts] = l->t.texture_size_y[l->triangle_number];
	l->t.texture_light[ts] = l->t.texture_light[l->triangle_number];
	l->t.texture_shift_x[ts] = l->t.texture_shift_x[l->triangle_number];
	l->t.texture_shift_y[ts] = l->t.texture_shift_y[l->triangle_number];
	l->t.texture_id[ts] = l->t.texture_id[l->triangle_number];
	l->t.texture_opacity[ts] = l->t.texture_opacity[l->triangle_number];
	l->t.texture_sides[ts] = l->t.texture_sides[l->triangle_number];
}

void		ft_map_editor_area_action_delete(t_variable_list *l)
{
	int	ts;

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
