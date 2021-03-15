/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:10 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_playing_mode_set_player_area(t_variable_list *l,
t_player_move_list *tmp)
{
	int	ts;

	tmp->save_ny = -10000000000;
	tmp->save_py = 10000000000;
	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->g.no_block[l->t.group[ts]] == 0 &&
			l->g.npc[l->t.group[ts]] == 0 &&
			l->g.sprite[l->t.group[ts]] == 0 &&
			l->g.exist[l->t.group[ts]] == 1)
		{
			ft_event_playing_mode_triangle_init(l, tmp, ts);
			ft_event_playing_mode_set_player_area_while(l, tmp, ts);
			l->p.x -= 10;
			l->p.z += 10;
		}
	}
}

void		ft_event_playing_mode_player_wallblock_jump(t_variable_list *l)
{
	if (l->i.state[44] && l->p.player_size == 50 &&
		l->p.jump_timer == 0 && l->gravity == 0)
	{
		l->p.jump_timer = 9.5;
	}
	else if (l->p.jump_timer > 0)
	{
		l->p.y += l->p.jump_timer;
		l->p.jump_timer -= l->coef_gravity;
		if (l->p.jump_timer < 0)
			l->p.jump_timer = 0;
	}
}

void		ft_event_playing_mode_player_wallblock_size(t_variable_list *l,
t_player_move_list *tmp)
{
	if (l->i.state[6] || tmp->save_py - tmp->save_ny <= 30)
	{
		l->p.player_size = 15;
		l->p.speed *= 0.5;
	}
	else if (l->i.state[224] || tmp->save_py - tmp->save_ny <= 45)
	{
		l->p.player_size = 25;
		l->p.speed *= 0.7;
	}
	else
		l->p.player_size = 50;
}

void		ft_event_playing_mode_player_wallblock_check_y(t_variable_list *l,
t_player_move_list *tmp)
{
	if (tmp->save_py <= 10 && tmp->save_ny >= -l->p.player_size)
	{
		l->p.y += l->gravity;
		l->p.jump_timer = 0;
	}
	else if (tmp->save_py <= 10)
	{
		l->p.y += tmp->save_py - 10;
		l->p.jump_timer = 0;
	}
	else if (tmp->save_ny >= -l->p.player_size)
	{
		l->p.y += tmp->save_ny + l->p.player_size;
		l->gravity = 0;
	}
}

void		ft_event_playing_mode_player_wallblock_move_while_1(
t_variable_list *l, t_player_move_list *tmp)
{
	tmp->vx = 10;
	tmp->vz = 10;
	tmp->vy = 10;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = -10;
	tmp->vy = 10;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = -10;
	tmp->vz = -10;
	tmp->vy = 10;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = -10;
	tmp->vz = 10;
	tmp->vy = 10;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = 10;
	tmp->vy = -l->p.player_size;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = -10;
	tmp->vy = -l->p.player_size;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
}
