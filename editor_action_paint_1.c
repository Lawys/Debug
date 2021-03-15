/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_paint_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:40 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_paint_action_delete_set_values(t_variable_list *l)
{
	int	ts;
	int	tn;

	ts = l->triangle_select;
	tn = --l->triangle_number;
	l->t.area[ts] = l->t.area[tn];
	l->t.group[ts] = l->t.group[tn];
	l->t.x1[ts] = l->t.x1[tn];
	l->t.y1[ts] = l->t.y1[tn];
	l->t.z1[ts] = l->t.z1[tn];
	l->t.x2[ts] = l->t.x2[tn];
	l->t.y2[ts] = l->t.y2[tn];
	l->t.z2[ts] = l->t.z2[tn];
	l->t.x3[ts] = l->t.x3[tn];
	l->t.y3[ts] = l->t.y3[tn];
	l->t.z3[ts] = l->t.z3[tn];
	l->t.texture_size_x[ts] = l->t.texture_size_x[tn];
	l->t.texture_size_y[ts] = l->t.texture_size_y[tn];
	l->t.texture_light[ts] = l->t.texture_light[tn];
	l->t.texture_shift_x[ts] = l->t.texture_shift_x[tn];
	l->t.texture_shift_y[ts] = l->t.texture_shift_y[tn];
	l->t.texture_id[ts] = l->t.texture_id[tn];
	l->t.texture_opacity[ts] = l->t.texture_opacity[tn];
	l->t.texture_sides[ts] = l->t.texture_sides[tn];
}

void		ft_map_editor_paint_action_delete(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.mouse == 1 && l->triangle_select != -1)
		{
			if (l->triangle_number == 0)
				return ;
			ft_map_editor_paint_action_delete_set_values(l);
			l->triangle_select = -1;
		}
	}
}

void		ft_map_editor_paint_action_texture(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->pe.pen_texture, 0, l->texture_number - 1);
		if (l->i.mouse == 1)
		{
			l->t.texture_id[l->triangle_select] = l->pe.pen_texture;
			l->triangle_select = -1;
		}
	}
}

void		ft_map_editor_paint_action_group(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->pe.pen_group, 0, MAX_GROUPS - 1);
		if (l->i.mouse == 1)
		{
			l->t.group[l->triangle_select] = l->pe.pen_group;
			l->triangle_select = -1;
		}
	}
}

void		ft_map_editor_paint_action_area(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->pe.pen_area, 0, MAX_AREAS - 1);
		if (l->i.mouse == 1)
		{
			l->t.area[l->triangle_select] = l->pe.pen_area;
			l->triangle_select = -1;
		}
	}
}
