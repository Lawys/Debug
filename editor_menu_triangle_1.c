/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_menu_triangle_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:00 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 10:13:38 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_parameters_1(t_variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_triangle_parameter_triangle(l);
	ft_map_editor_triangle_parameter_triangle_id(l);
	ft_map_editor_triangle_parameter_area(l);
	ft_map_editor_triangle_parameter_group(l);
	ft_map_editor_triangle_parameter_position(l);
	ft_map_editor_triangle_parameter_position_x_all(l);
	ft_map_editor_triangle_parameter_position_y_all(l);
	ft_map_editor_triangle_parameter_position_z_all(l);
	ft_map_editor_triangle_parameter_position_size(l);
	ft_map_editor_triangle_parameter_rotation(l);
	ft_map_editor_triangle_parameter_position_h(l);
	ft_map_editor_triangle_parameter_position_v(l);
	ft_map_editor_triangle_parameter_position_l(l);
	ft_map_editor_triangle_parameter_position_x_1(l);
	ft_map_editor_triangle_parameter_position_y_1(l);
	ft_map_editor_triangle_parameter_position_z_1(l);
	ft_map_editor_triangle_parameter_position_x_2(l);
	ft_map_editor_triangle_parameter_position_y_2(l);
	ft_map_editor_triangle_parameter_position_z_2(l);
	ft_map_editor_triangle_parameter_position_x_3(l);
	ft_map_editor_triangle_parameter_position_y_3(l);
	ft_map_editor_triangle_parameter_position_z_3(l);
}

void		ft_map_editor_triangle_parameters_2(t_variable_list *l)
{
	ft_map_editor_triangle_parameter_texture(l);
	ft_map_editor_triangle_parameter_texture_id(l);
	ft_map_editor_triangle_parameter_texture_light(l);
	ft_map_editor_triangle_parameter_texture_opacity(l);
	ft_map_editor_triangle_parameter_texture_sides(l);
	ft_map_editor_triangle_parameter_texture_size(l);
	ft_map_editor_triangle_parameter_texture_size_x(l);
	ft_map_editor_triangle_parameter_texture_size_y(l);
	ft_map_editor_triangle_parameter_texture_shift(l);
	ft_map_editor_triangle_parameter_texture_shift_x(l);
	ft_map_editor_triangle_parameter_texture_shift_y(l);
	ft_map_editor_triangle_parameter_texture_size_adapt(l);
	ft_map_editor_triangle_parameter_texture_size_stretch(l);
	ft_map_editor_triangle_parameter_texture_size_repeat(l);
	ft_map_editor_triangle_parameter_texture_size_adapt_x(l);
	ft_map_editor_triangle_parameter_texture_size_adapt_y(l);
	ft_map_editor_triangle_parameter_options(l);
	ft_map_editor_triangle_parameter_create_new(l);
	ft_map_editor_triangle_parameter_create_square(l);
	ft_map_editor_triangle_parameter_duplicate(l);
	ft_map_editor_triangle_parameter_delete(l);
	ft_map_editor_triangle_parameter_texture_view(l);
}

void		ft_map_editor_triangle_actions_1(t_variable_list *l)
{
	ft_map_editor_triangle_action_triangle(l);
	ft_map_editor_triangle_action_area(l);
	ft_map_editor_triangle_action_group(l);
	ft_map_editor_triangle_action_position_x_all(l);
	ft_map_editor_triangle_action_position_y_all(l);
	ft_map_editor_triangle_action_position_z_all(l);
	ft_map_editor_triangle_action_position_size(l);
	ft_map_editor_triangle_action_position_h(l);
	ft_map_editor_triangle_action_position_v(l);
	ft_map_editor_triangle_action_position_l(l);
	ft_map_editor_triangle_action_position_x_1(l);
	ft_map_editor_triangle_action_position_y_1(l);
	ft_map_editor_triangle_action_position_z_1(l);
	ft_map_editor_triangle_action_position_x_2(l);
	ft_map_editor_triangle_action_position_y_2(l);
	ft_map_editor_triangle_action_position_z_2(l);
	ft_map_editor_triangle_action_position_x_3(l);
	ft_map_editor_triangle_action_position_y_3(l);
	ft_map_editor_triangle_action_position_z_3(l);
}

void		ft_map_editor_triangle_actions_2(t_variable_list *l)
{
	ft_map_editor_triangle_action_texture(l);
	ft_map_editor_triangle_action_texture_light(l);
	ft_map_editor_triangle_action_texture_opacity(l);
	ft_map_editor_triangle_action_texture_sides(l);
	ft_map_editor_triangle_action_texture_size_x(l);
	ft_map_editor_triangle_action_texture_size_y(l);
	ft_map_editor_triangle_action_texture_shift_x(l);
	ft_map_editor_triangle_action_texture_shift_y(l);
	ft_map_editor_triangle_action_texture_size_stretch(l);
	ft_map_editor_triangle_action_texture_size_repeat(l);
	ft_map_editor_triangle_action_texture_size_adapt_x(l);
	ft_map_editor_triangle_action_texture_size_adapt_y(l);
	ft_map_editor_triangle_action_create_new(l);
	ft_map_editor_triangle_action_create_square(l);
	ft_map_editor_triangle_action_duplicate(l);
	ft_map_editor_triangle_action_delete(l);
}

void		ft_map_editor_triangle(t_variable_list *l)
{
	if (l->action_select[0][1] == 1 && l->triangle_select != -1)
	{
		l->group_select = -1;
		l->area_select = -1;
		l->menu_select = 1;
		l->action = 0;
		ft_map_editor_triangle_parameters_1(l);
		ft_map_editor_triangle_parameters_2(l);
		l->action = 0;
		ft_map_editor_triangle_actions_1(l);
		ft_map_editor_triangle_actions_2(l);
	}
}
