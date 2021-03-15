/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:15 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_playing_mode_player_wallblock_move_while_2(
t_variable_list *l, t_player_move_list *tmp)
{
	tmp->vx = -10;
	tmp->vz = -10;
	tmp->vy = -l->p.player_size;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = -10;
	tmp->vz = 10;
	tmp->vy = -l->p.player_size;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = 10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = -10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = -10;
	tmp->vz = -10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = -10;
	tmp->vz = 10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
}

void		ft_event_playing_mode_player_wallblock_move_while_3(
t_variable_list *l, t_player_move_list *tmp)
{
	tmp->vx = -10;
	tmp->vz = 0;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 10;
	tmp->vz = 0;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 0;
	tmp->vz = -10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 0;
	tmp->vz = 10;
	tmp->vy = 0;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = 10;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
	tmp->vx = 0;
	tmp->vz = 0;
	tmp->vy = -l->p.player_size;
	ft_event_playing_mode_player_vector_intersection(l, tmp);
}

void		ft_event_playing_mode_player_wallblock_move(
t_variable_list *l, t_player_move_list *tmp)
{
	int	ts;

	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->g.no_block[l->t.group[ts]] == 0 &&
			l->g.npc[l->t.group[ts]] == 0 &&
			l->g.sprite[l->t.group[ts]] == 0 &&
			l->g.exist[l->t.group[ts]] == 1)
		{
			ft_event_playing_mode_triangle_init(l, tmp, ts);
			ft_event_playing_mode_player_wallblock_move_while_1(l, tmp);
			ft_event_playing_mode_player_wallblock_move_while_2(l, tmp);
			ft_event_playing_mode_player_wallblock_move_while_3(l, tmp);
		}
	}
}

void		ft_event_playing_mode_player_wallblock(t_variable_list *l)
{
	t_player_move_list	tmp;

	ft_event_playing_mode_player_wallblock_jump(l);
	ft_event_playing_mode_player_wallblock_gravity(l);
	ft_event_playing_mode_set_player_area(l, &tmp);
	ft_event_playing_mode_player_wallblock_size(l, &tmp);
	ft_event_playing_mode_player_wallblock_check_y(l, &tmp);
	ft_event_playing_mode_player_wallblock_init(l, &tmp);
	l->p.z += tmp.move_z * l->p.speed;
	l->p.x += tmp.move_x * l->p.speed;
	ft_event_playing_mode_player_wallblock_move(l, &tmp);
	if (tmp.angle)
	{
		l->p.x -= tmp.move_x * l->p.speed;
		l->p.z -= tmp.move_z * l->p.speed;
	}
}

void		ft_event_playing_mode_player(t_variable_list *l)
{
	int	group;

	l->p.speed = 2;
	if (l->i.state[225])
		l->p.speed = 2.5;
	if (l->i.state[26] + l->i.state[22] +
		l->i.state[7] + l->i.state[4] > 1)
		l->p.speed *= 0.75;
	ft_event_playing_mode_player_wallblock(l);
	l->p.interact = 0;
	if (l->i.state[8] &&
		l->pixels_distance[WDW2][WDH2] < 60)
	{
		l->i.state[8] = 0;
		group = l->t.group[l->pixels_triangle[WDW2][WDH2]];
		if (l->g.interact[group])
		{
			if (l->g.action_statement[group] == 0)
				l->g.action_statement[group] = 2;
			else if (l->g.action_statement[group] == 1)
				l->g.action_statement[group] = 3;
		}
	}
}
