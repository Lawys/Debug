/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_menu_game_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:45 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_game_parameters(t_variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_game_parameter_npc(l);
	ft_map_editor_game_parameter_npc_health(l);
	ft_map_editor_game_parameter_npc_damage(l);
	ft_map_editor_game_parameter_world(l);
	ft_map_editor_game_parameter_world_gravity(l);
}

void		ft_map_editor_game_actions(t_variable_list *l)
{
	ft_map_editor_game_action_npc_health(l);
	ft_map_editor_game_action_npc_damage(l);
	ft_map_editor_game_action_world_gravity(l);
}

void		ft_map_editor_game(t_variable_list *l)
{
	if (l->action_select[0][6] == 1)
	{
		l->triangle_select = -1;
		l->group_select = -1;
		l->area_select = -1;
		l->menu_select = 6;
		l->action = 0;
		ft_map_editor_game_parameters(l);
		l->action = 0;
		ft_map_editor_game_actions(l);
	}
}
