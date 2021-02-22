/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:00 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 10:13:21 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_set_item_select(variable_list *l, int item)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (l->p.item[i] == 2)
		{
			l->p.item[i] = 1;
			break ;
		}
	l->p.item[item] = 2;
}

void		ft_hud_play_set_item_select_scroll_up(variable_list *l)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (l->p.item[i] == 2)
		{
			l->p.item[i++] = 1;
			if (i == 6)
				i = 0;
			while (l->p.item[i] == 0)
				if (++i == 6)
					i = 0;
			l->p.item[i] = 2;
		}
}

void		ft_hud_play_set_item_select_scroll_down(variable_list *l)
{
	int	i;

	i = 6;
	while (--i >= 0)
		if (l->p.item[i] == 2)
		{
			l->p.item[i--] = 1;
			if (i == -1)
				i = 5;
			while (l->p.item[i] == 0)
				if (--i == -1)
					i = 5;
			l->p.item[i] = 2;
		}
}

void		ft_hud_play_set_item_select_scroll(variable_list *l)
{
	if (l->i.scroll_up)
		ft_hud_play_set_item_select_scroll_up(l);
	else if (l->i.scroll_down)
		ft_hud_play_set_item_select_scroll_down(l);
}

void		ft_hud_play_item_0_animation_1(variable_list *l)
{
	if (l->i.mouse == 1)
		l->p.animation_timer = 20;
	l->u.tex = 270;
	l->u.tsy = 436;
	l->u.tey = 575;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
}
