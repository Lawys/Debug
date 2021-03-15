/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_menu_paint_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:53 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_paint_parameters(t_variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_paint_parameter_mode(l);
	ft_map_editor_paint_parameter_delete(l);
	ft_map_editor_paint_parameter_texture(l);
	ft_map_editor_paint_parameter_group(l);
	ft_map_editor_paint_parameter_area(l);
	ft_map_editor_paint_parameter_opacity(l);
	ft_map_editor_paint_parameter_light(l);
}

void		ft_map_editor_paint_actions(t_variable_list *l)
{
	ft_map_editor_paint_action_delete(l);
	ft_map_editor_paint_action_texture(l);
	ft_map_editor_paint_action_group(l);
	ft_map_editor_paint_action_area(l);
	ft_map_editor_paint_action_opacity(l);
	ft_map_editor_paint_action_light(l);
}

void		ft_map_editor_paint(t_variable_list *l)
{
	if (l->action_select[0][7] == 1)
	{
		l->menu_select = 7;
		l->action = 0;
		ft_map_editor_paint_parameters(l);
		l->action = 0;
		ft_map_editor_paint_actions(l);
	}
}
