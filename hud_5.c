/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:20 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_item_2_animation_3(t_variable_list *l)
{
	if (l->p.animation_timer == 15)
	{
		l->gr.gd = l->pixels_distance[WDW2][WDH2];
		if (l->gr.gd > 499)
			l->gr.gd = 499;
		l->gr.gx = -l->gr.gd * l->e.s_h;
		l->gr.gz = l->gr.gd * l->e.c_h;
		l->gr.gy = l->gr.gd * l->e.s_v;
		l->gr.gx /= l->gr.gd;
		l->gr.gy /= l->gr.gd;
		l->gr.gz /= l->gr.gd;
		l->gr.sx = l->p.x;
		l->gr.sy = l->p.y;
		l->gr.sz = l->p.z;
		ft_hud_play_item_2_animation_3_check_error(l);
		ft_hud_play_item_2_animation_3_create_grenade(l);
	}
	l->u.tsx = 553;
	l->u.tex = 1022;
	l->u.tsy = 744;
	l->u.tey = 1018;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_2_animation_4(t_variable_list *l)
{
	l->u.tsx = 553;
	l->u.tex = 1022;
	l->u.tsy = 744;
	l->u.tey = 1018 - 125;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_2_animation_5(t_variable_list *l)
{
	l->u.tsx = 553;
	l->u.tex = 1022;
	l->u.tsy = 744;
	l->u.tey = 1018 - 250;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_2(t_variable_list *l)
{
	l->u.colors = l->texture_colors[35];
	l->u.wsx = 39.5;
	l->u.size = 1.5;
	if (l->p.animation_timer == 0)
		ft_hud_play_item_2_animation_1(l);
	else if (l->p.animation_timer > 15)
		ft_hud_play_item_2_animation_2(l);
	else if (l->p.animation_timer > 10)
		ft_hud_play_item_2_animation_3(l);
	else if (l->p.animation_timer > 5)
		ft_hud_play_item_2_animation_4(l);
	else if (l->p.animation_timer > 1)
		ft_hud_play_item_2_animation_5(l);
	else if (l->p.animation_timer == 1)
	{
		ft_hud_play_item_2_animation_6(l);
		return ;
	}
	ft_put_texture(l);
}

void		ft_hud_play_item_3(t_variable_list *l)
{
	l->u.colors = l->texture_colors[34];
	l->u.wsx = 40;
	l->u.size = 1;
	l->u.tsx = 408;
	l->u.tex = 902;
	l->u.tsy = 754;
	l->u.tey = 1024;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	ft_put_texture(l);
	if (l->i.mouse == 1)
	{
		if (l->g.action_statement[48] == 0)
			l->g.action_statement[48] = 2;
		else if (l->g.action_statement[48] == 1)
			l->g.action_statement[48] = 3;
	}
}
