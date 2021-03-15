/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_triangle_7.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:28 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_parameter_texture_shift_x(t_variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.texture_shift_x[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_shift_y(t_variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.texture_shift_y[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_adapt(
t_variable_list *l)
{
	l->u.str_address = "AUTO TEXTURE";
	l->u.wsy += 2.5;
	l->u.action = -1;
	l->u.wsx = 37;
	l->u.colors = l->me.color_red;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_stretch(
t_variable_list *l)
{
	l->u.str_address = "<STRETCH>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_repeat(
t_variable_list *l)
{
	l->u.str_address = "<REPEAT>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
