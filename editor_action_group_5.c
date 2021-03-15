/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_group_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:17 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_action_position_l(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_group_action_position_l_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_group_action_position_l_down(l);
	}
}

void		ft_map_editor_group_action_position_size_recall(t_variable_list *l)
{
	int		ts;
	double	p[3];

	p[0] = l->me.x;
	p[1] = l->me.y;
	p[2] = l->me.z;
	ft_map_editor_group_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
		if (l->t.group[ts] == l->group_select)
		{
			l->t.x1[ts] -= l->me.x - p[0];
			l->t.x2[ts] -= l->me.x - p[0];
			l->t.x3[ts] -= l->me.x - p[0];
			l->t.y1[ts] -= l->me.y - p[1];
			l->t.y2[ts] -= l->me.y - p[1];
			l->t.y3[ts] -= l->me.y - p[1];
			l->t.z1[ts] -= l->me.z - p[2];
			l->t.z2[ts] -= l->me.z - p[2];
			l->t.z3[ts] -= l->me.z - p[2];
		}
}

void		ft_map_editor_group_action_position_size_up(t_variable_list *l)
{
	int	ts;

	ft_map_editor_group_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
		if (l->t.group[ts] == l->group_select)
		{
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
		}
	ft_map_editor_group_action_position_size_recall(l);
}

void		ft_map_editor_group_action_position_size_down(t_variable_list *l)
{
	int	ts;

	ft_map_editor_group_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
		if (l->t.group[ts] == l->group_select)
		{
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
		}
	ft_map_editor_group_action_position_size_recall(l);
}

void		ft_map_editor_group_action_position_size(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_group_action_position_size_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_group_action_position_size_down(l);
	}
}
