/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_8.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:31 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_texture_size_repeat(
t_variable_list *l)
{
	int	ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		l->t.texture_size_x[ts] = 100;
		l->t.texture_size_y[ts] = 100;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_triangle_action_texture_size_adapt_y(
t_variable_list *l)
{
	double	dist12;
	double	dist13;
	int		ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts])
		+ (l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts])
		+ (l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		if (dist12 < dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist12 / 100);
			l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		}
		else if (dist12 > dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist13 / 100);
			l->t.texture_size_x[ts] = 100 / (dist13 / 100);
		}
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_triangle_action_texture_size_adapt_x(
t_variable_list *l)
{
	double	dist12;
	double	dist13;
	int		ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts])
		+ (l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts])
		+ (l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		if (dist12 < dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist13 / 100);
			l->t.texture_size_x[ts] = 100 / (dist13 / 100);
		}
		else if (dist12 > dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist12 / 100);
			l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		}
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_triangle_action_texture_shift_x(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_shift_x[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_texture_shift_y(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_shift_y[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}
