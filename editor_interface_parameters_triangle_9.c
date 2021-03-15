/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_triangle_9.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:36 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_parameter_create_square(t_variable_list *l)
{
	l->u.str_address = "<SQUARE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_duplicate(t_variable_list *l)
{
	l->u.str_address = "<DUPLICATE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_delete(t_variable_list *l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_view(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[(int)l->t.texture_id[l->triangle_select]];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024 * ((double)WDHF / (double)WDWF);
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 0.11;
	l->u.wsx = 88;
	l->u.wsy = 74.5;
	ft_put_texture(l);
}
