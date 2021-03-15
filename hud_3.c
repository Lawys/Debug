/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:10 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_item_1_animation_1(t_variable_list *l)
{
	if (l->i.mouse == 1)
		l->p.animation_timer = 20;
	l->u.tsx = 448;
	l->u.tex = 601;
	l->u.tsy = 106;
	l->u.tey = 272;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
}

void		ft_hud_play_item_1_animation_2(t_variable_list *l)
{
	l->u.tsx = 231;
	l->u.tex = 443;
	l->u.tsy = 58;
	l->u.tey = 272;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_1_animation_3(t_variable_list *l)
{
	if (l->p.animation_timer == 15 && l->pixels_triangle[WDW2][WDH2] > 11 &&
		l->g.npc[l->t.group[l->pixels_triangle[WDW2][WDH2]]])
	{
		l->g.npc_statement[l->t.group[l->pixels_triangle[WDW2][WDH2]]] = 3;
		l->g.npc_timer[l->t.group[l->pixels_triangle[WDW2][WDH2]]] = -5;
		l->g.npc_hp[l->t.group[l->pixels_triangle[WDW2][WDH2]]]--;
	}
	l->u.tsx = 0;
	l->u.tex = 212;
	l->u.tsy = 0;
	l->u.tey = 271;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_1_animation_4(t_variable_list *l)
{
	l->u.tsx = 231;
	l->u.tex = 443;
	l->u.tsy = 58;
	l->u.tey = 272;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_1_animation_5(t_variable_list *l)
{
	l->u.tsx = 448;
	l->u.tex = 601;
	l->u.tsy = 106;
	l->u.tey = 272;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}
