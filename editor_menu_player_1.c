/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_menu_player_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:57 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_player_parameters(t_variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_player_parameter_start(l);
	ft_map_editor_player_parameter_x(l);
	ft_map_editor_player_parameter_y(l);
	ft_map_editor_player_parameter_z(l);
	ft_map_editor_player_parameter_hp(l);
	ft_map_editor_player_parameter_item(l);
	ft_map_editor_player_parameter_item_bare_hands(l);
	ft_map_editor_player_parameter_item_pistol(l);
	ft_map_editor_player_parameter_item_grenade(l);
	ft_map_editor_player_parameter_item_telecommand(l);
	ft_map_editor_player_parameter_item_access_card(l);
	ft_map_editor_player_parameter_item_top_secret_box(l);
}

void		ft_map_editor_player_actions(t_variable_list *l)
{
	ft_map_editor_player_action_x(l);
	ft_map_editor_player_action_y(l);
	ft_map_editor_player_action_z(l);
	ft_map_editor_player_action_hp(l);
	ft_map_editor_player_action_item_bare_hands(l);
	ft_map_editor_player_action_item_pistol(l);
	ft_map_editor_player_action_item_grenade(l);
	ft_map_editor_player_action_item_telecommand(l);
	ft_map_editor_player_action_item_access_card(l);
	ft_map_editor_player_action_item_top_secret_box(l);
}

void		ft_map_editor_player(t_variable_list *l)
{
	if (l->action_select[0][5] == 1)
	{
		l->triangle_select = -1;
		l->group_select = -1;
		l->area_select = -1;
		l->menu_select = 5;
		l->action = 0;
		ft_map_editor_player_parameters(l);
		l->action = 0;
		ft_map_editor_player_actions(l);
	}
}
