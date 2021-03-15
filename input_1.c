/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:56 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_playing_mode_motion(t_variable_list *l)
{
	l->p.h += (((double)WDW2) - l->i.mouse_x) / 360;
	l->p.v += (((double)WDH2) - l->i.mouse_y) / 360;
	SDL_WarpMouseInWindow(l->window, WDW2, WDH2);
	if (l->p.v > M_PI / 2 - M_PI / 45)
		l->p.v = M_PI / 2 - M_PI / 45;
	else if (l->p.v < -M_PI / 2 + M_PI / 45)
		l->p.v = -M_PI / 2 + M_PI / 45;
}

void		ft_event_playing_mode_player_line_plan_t(t_variable_list *l,
t_player_move_list *tmp)
{
	tmp->t =
		(tmp->nx * (l->p.x - tmp->p1x) +
			tmp->ny * (l->p.y - tmp->p1y) +
			tmp->nz * (l->p.z - tmp->p1z)) /
		(-tmp->vx * tmp->nx +
			-tmp->vy * tmp->ny +
			-tmp->vz * tmp->nz);
}

void		ft_event_playing_mode_player_line_plan_u(t_variable_list *l,
t_player_move_list *tmp)
{
	tmp->u =
		((-tmp->vy * tmp->p02z - -tmp->vz * tmp->p02y) *
			(l->p.x - tmp->p1x) +
			(-tmp->vz * tmp->p02x - -tmp->vx * tmp->p02z) *
			(l->p.y - tmp->p1y) +
			(-tmp->vx * tmp->p02y - -tmp->vy * tmp->p02x) *
			(l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}

void		ft_event_playing_mode_player_line_plan_v(t_variable_list *l,
t_player_move_list *tmp)
{
	tmp->v =
		((tmp->p01y * -tmp->vz - tmp->p01z * -tmp->vy) *
			(l->p.x - tmp->p1x) +
			(tmp->p01z * -tmp->vx - tmp->p01x * -tmp->vz) *
			(l->p.y - tmp->p1y) +
			(tmp->p01x * -tmp->vy - tmp->p01y * -tmp->vx) *
			(l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}

void		ft_event_playing_mode_player_vector_intersection(t_variable_list *l,
t_player_move_list *tmp)
{
	double	y;

	ft_event_playing_mode_player_line_plan_t(l, tmp);
	ft_event_playing_mode_player_line_plan_u(l, tmp);
	ft_event_playing_mode_player_line_plan_v(l, tmp);
	if (tmp->t >= 0 && tmp->t <= 1 &&
		tmp->u >= 0 && tmp->u <= 1 &&
		tmp->v >= 0 && tmp->v <= 1 &&
		tmp->u + tmp->v <= 1)
	{
		y = tmp->vy * tmp->t;
		if (fabs(tmp->nx) > fabs(tmp->ny) || fabs(tmp->nz) > fabs(tmp->ny))
			tmp->angle = 1;
		if (y > 0 && y < tmp->save_py && tmp->ny != 0)
			tmp->save_py = y;
		else if (y < 0 && y > tmp->save_ny && tmp->ny != 0)
			tmp->save_ny = y;
	}
}
