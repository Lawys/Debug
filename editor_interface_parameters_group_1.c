/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_group_1.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:04 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_parameter_group(t_variable_list *l)
{
	l->u.str_address = "GROUP";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_group_id(t_variable_list *l)
{
	l->u.str_address = "ID";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->group_select, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_switch(t_variable_list *l)
{
	l->u.str_address = ">>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->me.group_switch_value, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_position(t_variable_list *l)
{
	l->u.str_address = "POSITION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_position_x(t_variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}
