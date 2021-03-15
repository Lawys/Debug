/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_menu_1.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:25 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_menu_parameter_triangle(t_variable_list *l)
{
	l->u.str_address = "TRIANGLE";
	l->u.wsx = 4.5;
	l->u.wsy = 74.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_area(t_variable_list *l)
{
	l->u.str_address = "AREA";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_group(t_variable_list *l)
{
	l->u.str_address = "GROUP";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_light(t_variable_list *l)
{
	l->u.str_address = "LIGHT";
	l->u.wsx = 4.5;
	l->u.wsy += 3;
	++l->action;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_player(t_variable_list *l)
{
	l->u.str_address = "PLAYER";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}
