/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_group_3.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:11 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_parameter_position_size(t_variable_list *l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_action(t_variable_list *l)
{
	l->u.str_address = "ACTION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_enable(t_variable_list *l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "ENABLE";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_disable(t_variable_list *l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "DISABLE";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_flag(t_variable_list *l)
{
	l->u.str_address = "FLAG";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}
