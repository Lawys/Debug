/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_group_4.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:27:16 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_parameter_sprite(t_variable_list *l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.sprite[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<SPRITE>";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_npc(t_variable_list *l)
{
	l->u.action = ++l->action;
	if (l->g.npc[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<NPC>";
	l->u.wsx += 0.5;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_no_block(t_variable_list *l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.no_block[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<NO BLOCK>";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_interact(t_variable_list *l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.interact[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<INTERACT>";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_options(t_variable_list *l)
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
