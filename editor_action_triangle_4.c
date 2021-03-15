/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:12 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_position_vdown(t_variable_list *l)
{
	double	tmp;
	int		ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.z1[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.z1[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.z2[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.z2[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.z3[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.z3[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y3[ts] = tmp;
}

void		ft_map_editor_triangle_action_position_v(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action] == 1)
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_v_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_vdown(l);
	}
}

void		ft_map_editor_triangle_action_position_l_up(t_variable_list *l)
{
	double	tmp;
	int		ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x1[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x1[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x2[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x2[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x3[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x3[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y3[ts] = tmp;
}

void		ft_map_editor_triangle_action_position_l_down(t_variable_list *l)
{
	double	tmp;
	int		ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x1[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x1[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x2[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x2[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) +
		(l->t.x3[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) +
		(l->t.x3[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y3[ts] = tmp;
}

void		ft_map_editor_triangle_action_position_l(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action] == 1)
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_l_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_l_down(l);
	}
}
