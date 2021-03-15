/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_triangle_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:59 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_action_triangle(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->triangle_select, 12,
			l->triangle_number - 1);
}

void		ft_map_editor_triangle_action_area(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.area[l->triangle_select], 1,
			MAX_AREAS - 1);
}

void		ft_map_editor_triangle_action_group(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.group[l->triangle_select], 1,
			MAX_GROUPS - 1);
}

void		ft_map_editor_triangle_action_position_x_all(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.x1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}

void		ft_map_editor_triangle_action_position_y_all(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.y1[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y2[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y3[l->triangle_select],
			-MAX_GENERIC, MAX_GENERIC);
	}
}
