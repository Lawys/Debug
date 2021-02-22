/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_6.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:21 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 10:15:08 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_position_z_2(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_x_3(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.x3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_y_3(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_z_3(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_texture(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.texture_id[l->triangle_select],
			0, l->texture_number - 1);
}
