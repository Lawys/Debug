/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_area_4.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:54 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_parameter_link4(t_variable_list *l)
{
	ft_itoa(l->link4[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link5(t_variable_list *l)
{
	ft_itoa(l->link5[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link6(t_variable_list *l)
{
	ft_itoa(l->link6[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_options(t_variable_list *l)
{
	l->u.str_address = "OPTIONS";
	l->u.wsx = 37;
	l->u.wsy = 94.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_red;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_delete(t_variable_list *l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
