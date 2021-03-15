/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_player_2.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:47 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_player_parameter_item(t_variable_list *l)
{
	l->u.str_address = "ITEM";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_player_parameter_item_bare_hands(t_variable_list *l)
{
	l->u.str_address = "<BARE HANDS>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[0])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}

void		ft_map_editor_player_parameter_item_pistol(t_variable_list *l)
{
	l->u.str_address = "<PISTOL>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[1])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}

void		ft_map_editor_player_parameter_item_grenade(t_variable_list *l)
{
	l->u.str_address = "<GRENADE>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[2])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}

void		ft_map_editor_player_parameter_item_telecommand(t_variable_list *l)
{
	l->u.str_address = "<TELECOMMAND>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[3])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
