/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:06 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_item_0_animation_2(t_variable_list *l)
{
	l->u.tex = 362;
	l->u.tsy = 583;
	l->u.tey = 749;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_0_animation_3(t_variable_list *l)
{
	if (l->p.animation_timer == 15 && l->pixels_triangle[WDW2][WDH2] > 11
		&& l->g.npc[l->t.group[l->pixels_triangle[WDW2][WDH2]]] &&
		l->pixels_distance[WDW2][WDH2] < 60)
	{
		l->g.npc_hp[l->t.group[l->pixels_triangle[WDW2][WDH2]]] = 0;
	}
	l->u.tex = 495;
	l->u.tsy = 768;
	l->u.tey = 1023;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_0_animation_4(t_variable_list *l)
{
	l->u.tex = 362;
	l->u.tsy = 583;
	l->u.tey = 749;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_0_animation_5(t_variable_list *l)
{
	l->u.tex = 270;
	l->u.tsy = 436;
	l->u.tey = 575;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_0(t_variable_list *l)
{
	l->u.colors = l->texture_colors[35];
	l->u.wsx = 0;
	l->u.tsx = 0;
	l->u.size = 1.5;
	if (l->p.animation_timer == 0)
		ft_hud_play_item_0_animation_1(l);
	else if (l->p.animation_timer > 15)
		ft_hud_play_item_0_animation_2(l);
	else if (l->p.animation_timer > 10)
		ft_hud_play_item_0_animation_3(l);
	else if (l->p.animation_timer > 5)
		ft_hud_play_item_0_animation_4(l);
	else if (l->p.animation_timer > 0)
		ft_hud_play_item_0_animation_5(l);
	ft_put_texture(l);
}
