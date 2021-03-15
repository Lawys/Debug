/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_9.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:35 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_texture_sides(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.texture_sides[l->triangle_select],
			-1, 1);
}

void		ft_map_editor_triangle_action_create_new_set_values(
t_variable_list *l)
{
	int	tn;

	tn = l->triangle_number++;
	l->t.area[tn] = 1;
	l->t.group[tn] = l->me.new_group;
	l->t.x1[tn] = (int)l->p.x;
	l->t.y1[tn] = (int)l->p.y;
	l->t.z1[tn] = (int)l->p.z;
	l->t.x2[tn] = (int)l->p.x;
	l->t.y2[tn] = (int)l->p.y + 10.;
	l->t.z2[tn] = (int)l->p.z;
	l->t.x3[tn] = (int)l->p.x + 10.;
	l->t.y3[tn] = (int)l->p.y;
	l->t.z3[tn] = (int)l->p.z;
	l->t.texture_size_x[tn] = 100;
	l->t.texture_size_y[tn] = 100;
	l->t.texture_light[tn] = 100;
	l->t.texture_shift_x[tn] = 0;
	l->t.texture_shift_y[tn] = 0;
	l->t.texture_id[tn] = 0;
	l->t.texture_opacity[tn] = 100;
	l->t.texture_sides[tn] = 0;
	l->triangle_select = tn;
}

void		ft_map_editor_triangle_action_create_new(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return ;
		ft_map_editor_group_action_check_free_group(l);
		if (l->me.new_group == MAX_GROUPS)
			return ;
		ft_map_editor_triangle_action_create_new_set_values(l);
	}
}

void		ft_map_editor_triangle_action_create_square_set_values_shift(
t_variable_list *l, int tn, int ts)
{
	l->t.texture_shift_x[tn] = -(l->t.texture_shift_x[ts] +
		sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts])) *
		l->t.texture_size_x[ts] / 100);
	l->t.texture_shift_y[tn] = -(l->t.texture_shift_y[ts] +
		sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts])) *
		l->t.texture_size_y[ts] / 100);
}

void		ft_map_editor_triangle_action_create_square_set_values(
t_variable_list *l, int tn)
{
	int	ts;

	ts = l->triangle_select;
	l->t.area[tn] = l->t.area[ts];
	l->t.group[tn] = l->t.group[ts];
	l->t.x1[tn] = l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]);
	l->t.y1[tn] = l->t.y2[ts] + (l->t.y3[ts] - l->t.y1[ts]);
	l->t.z1[tn] = l->t.z2[ts] + (l->t.z3[ts] - l->t.z1[ts]);
	l->t.x2[tn] = l->t.x3[ts];
	l->t.y2[tn] = l->t.y3[ts];
	l->t.z2[tn] = l->t.z3[ts];
	l->t.x3[tn] = l->t.x2[ts];
	l->t.y3[tn] = l->t.y2[ts];
	l->t.z3[tn] = l->t.z2[ts];
	l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
	l->t.texture_light[tn] = l->t.texture_light[ts];
	ft_map_editor_triangle_action_create_square_set_values_shift(l, tn, ts);
	l->t.texture_id[tn] = l->t.texture_id[ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
	l->t.texture_sides[tn] = l->t.texture_sides[ts];
}
