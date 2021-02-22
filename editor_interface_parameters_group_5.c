/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_group_5.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:20 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:38:52 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_parameter_create_npc(variable_list *l)
{
	l->u.str_address = "<CREATE NPC>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_duplicate(variable_list *l)
{
	l->u.str_address = "<DUPLICATE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_delete(variable_list *l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
