/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:34 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_life(t_variable_list *l)
{
	l->u.colors = l->texture_colors[38];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 652;
	l->u.tey = 837;
	l->u.size = 0.33;
	l->u.wsx = 2.5;
	l->u.wsy = 90;
	ft_put_texture(l);
	l->u.tsx = 0;
	l->u.tex = (int)(1024. * (l->p.hp / 100.));
	l->u.tsy = 837;
	l->u.tey = 1024;
	l->u.size = 0.33;
	l->u.wsx = 2.5;
	l->u.wsy = 90;
	ft_put_texture(l);
	ft_itoa(l->p.hp, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx = 3.5;
	l->u.wsy = 91;
	l->u.size = 1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}

void		ft_hud_play_items_1(t_variable_list *l)
{
	l->u.tsx = 0;
	l->u.tex = 128;
	l->u.tsy = 0 + 129 * l->p.item[0];
	l->u.tey = 128 + 129 * l->p.item[0];
	l->u.wsx = 60.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
	l->u.tsx = 128;
	l->u.tex = 257;
	l->u.tsy = 0 + 129 * l->p.item[1];
	l->u.tey = 128 + 129 * l->p.item[1];
	l->u.wsx = 66.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
	l->u.tsx = 258;
	l->u.tex = 385;
	l->u.tsy = 0 + 129 * l->p.item[2];
	l->u.tey = 128 + 129 * l->p.item[2];
	l->u.wsx = 72.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
}

void		ft_hud_play_items_2(t_variable_list *l)
{
	l->u.tsx = 386;
	l->u.tex = 513;
	l->u.tsy = 0 + 129 * l->p.item[3];
	l->u.tey = 128 + 129 * l->p.item[3];
	l->u.wsx = 78.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
	l->u.tsx = 514;
	l->u.tex = 641;
	l->u.tsy = 0 + 129 * l->p.item[4];
	l->u.tey = 128 + 129 * l->p.item[4];
	l->u.wsx = 84.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
	l->u.tsx = 642;
	l->u.tex = 769;
	l->u.tsy = 0 + 129 * l->p.item[5];
	l->u.tey = 128 + 129 * l->p.item[5];
	l->u.wsx = 90.1;
	l->u.wsy = 91.1;
	ft_put_texture(l);
}

void		ft_hud_play(t_variable_list *l)
{
	if (l->p.hp <= 0)
	{
		l->menu_mode = 3;
		return ;
	}
	l->u.action = -1;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	if (l->p.animation_timer == 0)
		ft_hud_play_animation_timer_zero(l);
	ft_hud_play_item_select(l);
	ft_hud_play_grenade(l);
	ft_hud_play_life(l);
	l->u.colors = l->texture_colors[38];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 467;
	l->u.tey = 651;
	l->u.size = 0.40;
	l->u.wsx = 57.5;
	l->u.wsy = 90;
	ft_put_texture(l);
	ft_hud_play_items_1(l);
	ft_hud_play_items_2(l);
}

void		ft_hud_main_menu_display(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[32];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 0;
	l->u.wsy = 0;
	ft_put_texture(l);
}
