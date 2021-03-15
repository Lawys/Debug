/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_player_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:52 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_player_action_item_pistol(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[1] == 0)
			l->p.start_item[1] = 1;
		else
			l->p.start_item[1] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_player_action_item_grenade(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[2] == 0)
			l->p.start_item[2] = 1;
		else
			l->p.start_item[2] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_player_action_item_telecommand(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[3] == 0)
			l->p.start_item[3] = 1;
		else
			l->p.start_item[3] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_player_action_item_access_card(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[4] == 0)
			l->p.start_item[4] = 1;
		else
			l->p.start_item[4] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_player_action_item_top_secret_box(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[5] == 0)
			l->p.start_item[5] = 1;
		else
			l->p.start_item[5] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}
