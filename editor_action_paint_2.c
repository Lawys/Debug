/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_paint_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:44 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:39:41 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_paint_action_opacity(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->pe.pen_opacity, 10, 100);
		if (l->i.mouse == 1)
		{
			l->t.texture_opacity[l->triangle_select] = l->pe.pen_opacity;
			l->triangle_select = -1;
		}
	}
}

void		ft_map_editor_paint_action_light(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->pe.pen_light, 0, 100);
		if (l->i.mouse == 1)
		{
			l->t.texture_light[l->triangle_select] = l->pe.pen_light;
			l->triangle_select = -1;
		}
	}
}
