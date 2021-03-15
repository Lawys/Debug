/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_group_6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:25 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_action_enable(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		l->writing_mode = 1;
		ft_text_editing(l, l->g.action_enable[l->group_select], 56);
		l->u.action = -1;
		l->u.colors = l->texture_colors[16];
		l->u.tsx = 250;
		l->u.tex = 777;
		l->u.tsy = 415;
		l->u.tey = 674;
		l->u.sizex = (double)WDWF / 541.5;
		l->u.sizey = (double)WDHF / 4608;
		l->u.size = 1;
		l->u.wsx = 2;
		l->u.wsy = 67.4;
		ft_put_texture(l);
		l->u.wsx = 4;
		l->u.wsy = 69.3;
		l->u.action = -1;
		l->u.size = 0.8;
		l->u.colors = l->me.color_white;
		l->u.colors_on = l->me.color_white;
		l->u.str_address = l->g.action_enable[l->group_select];
		ft_put_text(l);
	}
}

void		ft_map_editor_group_action_disable(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		l->writing_mode = 1;
		ft_text_editing(l, l->g.action_disable[l->group_select], 56);
		l->u.action = -1;
		l->u.colors = l->texture_colors[16];
		l->u.tsx = 250;
		l->u.tex = 777;
		l->u.tsy = 415;
		l->u.tey = 674;
		l->u.sizex = (double)WDWF / 541.5;
		l->u.sizey = (double)WDHF / 4608;
		l->u.size = 1;
		l->u.wsx = 2;
		l->u.wsy = 67.4;
		ft_put_texture(l);
		l->u.wsx = 4;
		l->u.wsy = 69.3;
		l->u.action = -1;
		l->u.size = 0.8;
		l->u.colors = l->me.color_white;
		l->u.colors_on = l->me.color_white;
		l->u.str_address = l->g.action_disable[l->group_select];
		ft_put_text(l);
	}
}

void		ft_map_editor_group_action_sprite(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->g.sprite[l->group_select] == 0)
		{
			l->g.sprite[l->group_select] = 1;
			l->g.npc[l->group_select] = 0;
			l->g.no_block[l->group_select] = 0;
		}
		else
			l->g.sprite[l->group_select] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_group_action_npc(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->g.npc[l->group_select] == 0)
		{
			l->g.sprite[l->group_select] = 0;
			l->g.npc[l->group_select] = 1;
			l->g.no_block[l->group_select] = 0;
		}
		else
			l->g.npc[l->group_select] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_group_action_no_block(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->g.no_block[l->group_select] == 0)
		{
			l->g.sprite[l->group_select] = 0;
			l->g.npc[l->group_select] = 0;
			l->g.no_block[l->group_select] = 1;
		}
		else
			l->g.no_block[l->group_select] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}
