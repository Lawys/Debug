/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_menu_2.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:30 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_menu_parameter_game(t_variable_list *l)
{
	l->u.str_address = "GAME";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_paint(t_variable_list *l)
{
	l->u.str_address = "PAINT";
	l->u.wsx = 4.5;
	l->u.action = ++l->action;
	l->u.wsy += 3;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_view_only(t_variable_list *l)
{
	l->u.str_address = "VIEW ONLY AREA";
	l->u.wsx = 4.5;
	l->u.action = ++l->action;
	l->u.wsy += 3;
	l->u.size = 0.80;
	ft_put_text(l);
	ft_itoa(l->view_only, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 1;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
