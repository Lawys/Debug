/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_10.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:38 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:39:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_create_square(variable_list *l)
{
	int	tn;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return ;
		tn = l->triangle_number++;
		ft_map_editor_triangle_action_create_square_set_values(l, tn);
		l->triangle_select = tn;
	}
}

void		ft_map_editor_triangle_action_duplicate_set_values(variable_list *l)
{
	int	tn;
	int	ts;

	tn = l->triangle_number++;
	ts = l->triangle_select;
	l->t.area[tn] = l->t.area[ts];
	l->t.group[tn] = l->t.group[ts];
	l->t.x1[tn] = l->t.x1[ts];
	l->t.y1[tn] = l->t.y1[ts];
	l->t.z1[tn] = l->t.z1[ts];
	l->t.x2[tn] = l->t.x2[ts];
	l->t.y2[tn] = l->t.y2[ts];
	l->t.z2[tn] = l->t.z2[ts];
	l->t.x3[tn] = l->t.x3[ts];
	l->t.y3[tn] = l->t.y3[ts];
	l->t.z3[tn] = l->t.z3[ts];
	l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
	l->t.texture_light[tn] = l->t.texture_light[ts];
	l->t.texture_shift_x[tn] = l->t.texture_shift_x[ts];
	l->t.texture_shift_y[tn] = l->t.texture_shift_y[ts];
	l->t.texture_id[tn] = l->t.texture_id[ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
	l->t.texture_sides[tn] = l->t.texture_sides[ts];
	l->triangle_select = tn;
}

void		ft_map_editor_triangle_action_duplicate(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return ;
		ft_map_editor_triangle_action_duplicate_set_values(l);
	}
}

void		ft_map_editor_triangle_action_delete_set_values(variable_list *l)
{
	int	tn;
	int	ts;

	tn = --l->triangle_number;
	ts = l->triangle_select;
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
	l->triangle_select = -1;
}

void		ft_map_editor_triangle_action_delete(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == 0)
			return ;
		ft_map_editor_triangle_action_delete_set_values(l);
	}
}
