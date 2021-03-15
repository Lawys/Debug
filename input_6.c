/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:28 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_map_editor_mode_mouse_time_pressing_counter(
t_variable_list *l)
{
	if (l->i.mouse == 0)
		l->i.mouse_time_pressing = 0;
	else
		l->i.mouse_time_pressing++;
}

void		ft_event_map_editor_mode_select_triangle(t_variable_list *l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->triangle_select =
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2];
	if (l->triangle_select < 12)
		l->triangle_select = -1;
}

void		ft_event_map_editor_mode_select_area(t_variable_list *l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->area_select = l->t.area[
			l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2]];
	if (l->area_select == 0)
		l->area_select = -1;
}

void		ft_event_map_editor_mode_select_group(t_variable_list *l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->group_select = l->t.group[l->pixels_triangle[
			l->i.mouse_x / 2][l->i.mouse_y / 2]];
	if (l->group_select == 0)
		l->group_select = -1;
}

void		ft_event_map_editor_mode_select_on_click(t_variable_list *l)
{
	if (l->i.mouse == 1)
	{
		if (l->action_select[0][1] || l->action_select[0][7])
			ft_event_map_editor_mode_select_triangle(l);
		else if (l->action_select[0][2])
			ft_event_map_editor_mode_select_area(l);
		else if (l->action_select[0][3])
			ft_event_map_editor_mode_select_group(l);
	}
}
