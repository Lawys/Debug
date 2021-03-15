/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:03 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_position_z_all(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.z1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.z2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.z3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}

void		ft_map_editor_triangle_action_position_calculate_center(
t_variable_list *l)
{
	int	ts;

	ts = l->triangle_select;
	l->me.x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts]) / 3;
	l->me.y = (l->t.y1[ts] + l->t.y2[ts] + l->t.y3[ts]) / 3;
	l->me.z = (l->t.z1[ts] + l->t.z2[ts] + l->t.z3[ts]) / 3;
}

void		ft_map_editor_triangle_action_position_size_recall(
t_variable_list *l)
{
	int		ts;
	double	x;
	double	y;
	double	z;

	ts = l->triangle_select;
	x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts]) / 3 - l->me.x;
	y = (l->t.y1[ts] + l->t.y2[ts] + l->t.y3[ts]) / 3 - l->me.y;
	z = (l->t.z1[ts] + l->t.z2[ts] + l->t.z3[ts]) / 3 - l->me.z;
	l->t.x1[ts] -= x;
	l->t.x2[ts] -= x;
	l->t.x3[ts] -= x;
	l->t.y1[ts] -= y;
	l->t.y2[ts] -= y;
	l->t.y3[ts] -= y;
	l->t.z1[ts] -= z;
	l->t.z2[ts] -= z;
	l->t.z3[ts] -= z;
}

void		ft_map_editor_triangle_action_position_size_up(
t_variable_list *l)
{
	int	ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	ts = l->triangle_select;
	l->t.x1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.x2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.x3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_x[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_y[ts] /= 1 + 0.00001 * l->me.mult;
	ft_map_editor_triangle_action_position_size_recall(l);
}

void		ft_map_editor_triangle_action_position_size_down(
t_variable_list *l)
{
	int	ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	ts = l->triangle_select;
	l->t.x1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.x2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.x3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_x[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_y[ts] *= 1 + 0.00001 * l->me.mult;
	ft_map_editor_triangle_action_position_size_recall(l);
}
