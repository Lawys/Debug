/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:25 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_item_4(t_variable_list *l)
{
	l->u.colors = l->texture_colors[34];
	l->u.wsx = 35;
	l->u.size = 1;
	l->u.tsx = 329;
	l->u.tex = 685;
	l->u.tsy = 312;
	l->u.tey = 504;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	ft_put_texture(l);
	if (l->i.mouse == 1 && l->pixels_distance[WDW2][WDH2] < 60)
	{
		if (l->g.action_statement[48] == 0)
			l->g.action_statement[48] = 2;
		else if (l->g.action_statement[48] == 1)
			l->g.action_statement[48] = 3;
	}
}

void		ft_hud_play_item_5(t_variable_list *l)
{
	l->u.colors = l->texture_colors[34];
	l->u.wsx = 0;
	l->u.size = 1;
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 267;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	ft_put_texture(l);
}

void		ft_hud_play_animation_timer_zero(t_variable_list *l)
{
	if (l->i.state[SDL_SCANCODE_1] && l->p.item[0] == 1)
		ft_hud_play_set_item_select(l, 0);
	else if (l->i.state[SDL_SCANCODE_2] && l->p.item[1] == 1)
		ft_hud_play_set_item_select(l, 1);
	else if (l->i.state[SDL_SCANCODE_3] && l->p.item[2] == 1)
		ft_hud_play_set_item_select(l, 2);
	else if (l->i.state[SDL_SCANCODE_4] && l->p.item[3] == 1)
		ft_hud_play_set_item_select(l, 3);
	else if (l->i.state[SDL_SCANCODE_5] && l->p.item[4] == 1)
		ft_hud_play_set_item_select(l, 4);
	else if (l->i.state[SDL_SCANCODE_6] && l->p.item[5] == 1)
		ft_hud_play_set_item_select(l, 5);
	ft_hud_play_set_item_select_scroll(l);
}

void		ft_hud_play_item_select(t_variable_list *l)
{
	if (l->p.item[0] == 2)
		ft_hud_play_item_0(l);
	else if (l->p.item[1] == 2)
		ft_hud_play_item_1(l);
	else if (l->p.item[2] == 2)
		ft_hud_play_item_2(l);
	else if (l->p.item[3] == 2)
		ft_hud_play_item_3(l);
	else if (l->p.item[4] == 2)
		ft_hud_play_item_4(l);
	else if (l->p.item[5] == 2)
		ft_hud_play_item_5(l);
}

void		ft_hud_play_grenade_distance_positive(t_variable_list *l)
{
	l->gr.sx += l->gr.gx * 10;
	l->gr.sy += l->gr.gy * 10;
	l->gr.sz += l->gr.gz * 10;
	l->gr.gd -= 10;
	l->t.x1[l->gr.ts] = l->gr.sx - 10 * l->e.c_h;
	l->t.y1[l->gr.ts] = l->gr.sy - 10;
	l->t.z1[l->gr.ts] = l->gr.sz - 10 * l->e.s_h;
	l->t.x2[l->gr.ts] = l->gr.sx;
	l->t.y2[l->gr.ts] = l->gr.sy + 10;
	l->t.z2[l->gr.ts] = l->gr.sz;
	l->t.x3[l->gr.ts] = l->gr.sx + 10 * l->e.c_h;
	l->t.y3[l->gr.ts] = l->gr.sy - 10;
	l->t.z3[l->gr.ts] = l->gr.sz + 10 * l->e.s_h;
}
