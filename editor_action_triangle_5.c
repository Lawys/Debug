/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_5.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:16 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:39:29 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_position_x_1(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.x1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}

void		ft_map_editor_triangle_action_position_y_1(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_z_1(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_x_2(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.x2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_triangle_action_position_y_2(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
}
