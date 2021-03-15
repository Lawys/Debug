/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:20 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**ft_event_playing_mode_motion(l);
*/

void		ft_event_playing_mode(t_variable_list *l)
{
	ft_event_playing_mode_motion(l);
	ft_event_playing_mode_player(l);
}

void		ft_event_map_editor_mode_motion_right_click_on(t_variable_list *l)
{
	if (l->i.save_mouse_x == 0 && l->i.save_mouse_y == 0)
	{
		l->i.save_mouse_x = l->i.mouse_x;
		l->i.save_mouse_y = l->i.mouse_y;
	}
	else
	{
		l->p.h += ((double)l->i.save_mouse_x - l->i.mouse_x) / 360;
		l->p.v += ((double)l->i.save_mouse_y - l->i.mouse_y) / 360;
		l->i.save_mouse_x -= l->i.save_mouse_x - l->i.mouse_x;
		l->i.save_mouse_y -= l->i.save_mouse_y - l->i.mouse_y;
		if (l->p.v > M_PI / 2)
			l->p.v = M_PI / 2;
		else if (l->p.v < -M_PI / 2)
			l->p.v = -M_PI / 2;
		if (l->p.h > M_PI * 2)
			l->p.h -= M_PI * 2;
		else if (l->p.h < 0)
			l->p.h += M_PI * 2;
	}
}

void		ft_event_map_editor_mode_motion_right_click_off(t_variable_list *l)
{
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
}

void		ft_event_map_editor_mode_motion(t_variable_list *l)
{
	if (l->i.mouse == 4)
		ft_event_map_editor_mode_motion_right_click_on(l);
	else if (l->i.save_mouse_x != 0 || l->i.save_mouse_y != 0)
		ft_event_map_editor_mode_motion_right_click_off(l);
}

void		ft_event_map_editor_mode_moving(t_variable_list *l)
{
	if (l->i.state[26])
	{
		l->p.x -= sin(l->p.h) * l->p.speed;
		l->p.z += cos(l->p.h) * l->p.speed;
	}
	else if (l->i.state[22])
	{
		l->p.x += sin(l->p.h) * l->p.speed;
		l->p.z -= cos(l->p.h) * l->p.speed;
	}
	if (l->i.state[4])
	{
		l->p.x -= cos(l->p.h) * l->p.speed;
		l->p.z -= sin(l->p.h) * l->p.speed;
	}
	else if (l->i.state[7])
	{
		l->p.x += cos(l->p.h) * l->p.speed;
		l->p.z += sin(l->p.h) * l->p.speed;
	}
}
