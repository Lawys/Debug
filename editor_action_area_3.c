/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_area_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:30 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_action_position_z(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_z_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_z_down(l);
	}
}

void		ft_map_editor_area_action_position_calculate_center(
t_variable_list *l)
{
	int	c;
	int	i;

	l->me.x = 0;
	l->me.y = 0;
	l->me.z = 0;
	c = 0;
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			c++;
			l->me.x += (l->t.x1[i] + l->t.x2[i] + l->t.x3[i]) / 3;
			l->me.y += (l->t.y1[i] + l->t.y2[i] + l->t.y3[i]) / 3;
			l->me.z += (l->t.z1[i] + l->t.z2[i] + l->t.z3[i]) / 3;
		}
		i++;
	}
	l->me.x = l->me.x / c;
	l->me.y = l->me.y / c;
	l->me.z = l->me.z / c;
}

void		ft_map_editor_area_action_position_h_up(t_variable_list *l)
{
	double	tmp;
	int		i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.x1[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z1[i] = -(l->t.x1[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x1[i] = tmp;
			tmp = (l->t.x2[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z2[i] = -(l->t.x2[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x2[i] = tmp;
			tmp = (l->t.x3[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z3[i] = -(l->t.x3[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x3[i] = tmp;
		}
}

void		ft_map_editor_area_action_position_h_down(t_variable_list *l)
{
	double	tmp;
	int		i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = -0;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.x1[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z1[i] = -(l->t.x1[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x1[i] = tmp;
			tmp = (l->t.x2[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z2[i] = -(l->t.x2[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x2[i] = tmp;
			tmp = (l->t.x3[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z3[i] = -(l->t.x3[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x3[i] = tmp;
		}
}

void		ft_map_editor_area_action_position_h(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_h_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_h_down(l);
	}
}
