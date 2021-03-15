/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_triangle_6.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:24 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_parameter_texture_opacity(t_variable_list *l)
{
	l->u.str_address = "OPACITY";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.texture_opacity[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size(t_variable_list *l)
{
	l->u.str_address = "SIZE";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_blue;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_x(t_variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.texture_size_x[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_y(t_variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.texture_size_y[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_shift(t_variable_list *l)
{
	l->u.str_address = "SHIFT";
	l->u.wsx += 1;
	l->u.size = 0.80;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_blue;
	l->u.action = -1;
	ft_put_text(l);
}
