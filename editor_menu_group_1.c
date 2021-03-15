/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_menu_group_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:49 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_parameters(t_variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_group_parameter_group(l);
	ft_map_editor_group_parameter_group_id(l);
	ft_map_editor_group_parameter_switch(l);
	ft_map_editor_group_parameter_position(l);
	ft_map_editor_group_parameter_position_x(l);
	ft_map_editor_group_parameter_position_y(l);
	ft_map_editor_group_parameter_position_z(l);
	ft_map_editor_group_parameter_position_h(l);
	ft_map_editor_group_parameter_position_v(l);
	ft_map_editor_group_parameter_position_l(l);
	ft_map_editor_group_parameter_position_size(l);
	ft_map_editor_group_parameter_action(l);
	ft_map_editor_group_parameter_enable(l);
	ft_map_editor_group_parameter_disable(l);
	ft_map_editor_group_parameter_flag(l);
	ft_map_editor_group_parameter_sprite(l);
	ft_map_editor_group_parameter_npc(l);
	ft_map_editor_group_parameter_no_block(l);
	ft_map_editor_group_parameter_interact(l);
	ft_map_editor_group_parameter_options(l);
	ft_map_editor_group_parameter_create_npc(l);
	ft_map_editor_group_parameter_duplicate(l);
	ft_map_editor_group_parameter_delete(l);
}

void		ft_map_editor_group_actions(t_variable_list *l)
{
	ft_map_editor_group_action_select_group(l);
	ft_map_editor_group_action_switch_group(l);
	ft_map_editor_group_action_position_x(l);
	ft_map_editor_group_action_position_y(l);
	ft_map_editor_group_action_position_z(l);
	ft_map_editor_group_action_position_h(l);
	ft_map_editor_group_action_position_v(l);
	ft_map_editor_group_action_position_l(l);
	ft_map_editor_group_action_position_size(l);
	ft_map_editor_group_action_enable(l);
	ft_map_editor_group_action_disable(l);
	ft_map_editor_group_action_sprite(l);
	ft_map_editor_group_action_npc(l);
	ft_map_editor_group_action_no_block(l);
	ft_map_editor_group_action_interact(l);
	ft_map_editor_group_action_create_npc(l);
	ft_map_editor_group_action_duplicate(l);
	ft_map_editor_group_action_delete(l);
}

void		ft_map_editor_group(t_variable_list *l)
{
	if (l->action_select[0][3] == 1 && l->group_select != -1)
	{
		l->triangle_select = -1;
		l->area_select = -1;
		l->menu_select = 3;
		l->action = 0;
		ft_map_editor_group_parameters(l);
		l->action = 0;
		ft_map_editor_group_actions(l);
	}
}
