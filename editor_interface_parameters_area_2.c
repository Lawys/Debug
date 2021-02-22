/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_area_2.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:26:46 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:39:11 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_parameter_position_y(variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_position_z(variable_list *l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_position_h(variable_list *l)
{
	l->u.str_address = "H";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_position_v(variable_list *l)
{
	l->u.str_address = "V";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_position_l(variable_list *l)
{
	l->u.str_address = "L";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
