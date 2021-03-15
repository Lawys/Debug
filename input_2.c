/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:02 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_playing_mode_triangle_init(t_variable_list *l,
t_player_move_list *tmp, int ts)
{
	tmp->p1x = l->t.x1[ts];
	tmp->p2x = l->t.x2[ts];
	tmp->p3x = l->t.x3[ts];
	tmp->p1y = l->t.y1[ts];
	tmp->p2y = l->t.y2[ts];
	tmp->p3y = l->t.y3[ts];
	tmp->p1z = l->t.z1[ts];
	tmp->p2z = l->t.z2[ts];
	tmp->p3z = l->t.z3[ts];
	tmp->p01x = tmp->p2x - tmp->p1x;
	tmp->p02x = tmp->p3x - tmp->p1x;
	tmp->p01y = tmp->p2y - tmp->p1y;
	tmp->p02y = tmp->p3y - tmp->p1y;
	tmp->p01z = tmp->p2z - tmp->p1z;
	tmp->p02z = tmp->p3z - tmp->p1z;
	tmp->nx = tmp->p01y * tmp->p02z -
		tmp->p01z * tmp->p02y;
	tmp->ny = tmp->p01z * tmp->p02x -
		tmp->p01x * tmp->p02z;
	tmp->nz = tmp->p01x * tmp->p02y -
		tmp->p01y * tmp->p02x;
}

void		ft_event_playing_mode_player_wallblock_init(t_variable_list *l,
t_player_move_list *tmp)
{
	tmp->move_x = 0;
	tmp->move_z = 0;
	tmp->save_py = 10000000000;
	tmp->save_ny = -10000000000;
	tmp->angle = 0;
	if (l->i.state[26])
	{
		tmp->move_x -= sin(l->p.h) * l->p.speed;
		tmp->move_z += cos(l->p.h) * l->p.speed;
	}
	else if (l->i.state[22])
	{
		tmp->move_x += sin(l->p.h) * l->p.speed;
		tmp->move_z -= cos(l->p.h) * l->p.speed;
	}
	if (l->i.state[4])
	{
		tmp->move_x -= cos(l->p.h) * l->p.speed;
		tmp->move_z -= sin(l->p.h) * l->p.speed;
	}
	else if (l->i.state[7])
	{
		tmp->move_x += cos(l->p.h) * l->p.speed;
		tmp->move_z += sin(l->p.h) * l->p.speed;
	}
}

void		ft_event_playing_mode_player_wallblock_gravity(t_variable_list *l)
{
	l->gravity += 0.75 * l->coef_gravity;
	if (l->gravity > 30 * l->coef_gravity)
		l->p.hp = 0;
	l->p.y -= l->gravity;
}

void		ft_event_playing_mode_player_first_area_list_calculate(
t_variable_list *l, t_player_move_list *tmp, int ts)
{
	double	y;

	ft_event_playing_mode_player_line_plan_t(l, tmp);
	ft_event_playing_mode_player_line_plan_u(l, tmp);
	ft_event_playing_mode_player_line_plan_v(l, tmp);
	if (tmp->t >= -1 && tmp->t <= 1 &&
		tmp->u >= 0 && tmp->u <= 1 &&
		tmp->v >= 0 && tmp->v <= 1 &&
		tmp->u + tmp->v <= 1)
	{
		y = tmp->vy * tmp->t;
		if (y < 0 && y > tmp->save_ny)
		{
			tmp->save_ny = y;
			l->player_area = l->t.area[ts];
		}
		else if (y > 0 && y < tmp->save_py)
			tmp->save_py = y;
	}
}

void		ft_event_playing_mode_set_player_area_while(t_variable_list *l,
t_player_move_list *tmp, int ts)
{
	l->p.x += 10;
	l->p.z += 10;
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = 10000000000;
	ft_event_playing_mode_player_first_area_list_calculate(l, tmp, ts);
	l->p.x -= 20;
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = 10000000000;
	ft_event_playing_mode_player_first_area_list_calculate(l, tmp, ts);
	l->p.z -= 20;
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = 10000000000;
	ft_event_playing_mode_player_first_area_list_calculate(l, tmp, ts);
	l->p.x += 20;
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = 10000000000;
	ft_event_playing_mode_player_first_area_list_calculate(l, tmp, ts);
}
