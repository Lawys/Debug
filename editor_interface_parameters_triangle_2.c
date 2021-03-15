/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_triangle_2.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:08 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_triangle_parameter_position_x_all(t_variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.size = 1;
	l->u.action = ++l->action;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_y_all(t_variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_z_all(t_variable_list *l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_size(t_variable_list *l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_rotation(t_variable_list *l)
{
	l->u.str_address = "ROTATION";
	l->u.wsx += 1;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
