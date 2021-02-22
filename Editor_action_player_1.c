/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_player_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:47 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 10:15:21 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_player_action_x(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_x, -MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_player_action_y(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_y, -MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_player_action_z(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_z, -MAX_GENERIC, MAX_GENERIC);
}

void		ft_map_editor_player_action_hp(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_hp, 0, 100);
}

void		ft_map_editor_player_action_item_bare_hands(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[0] == 0)
			l->p.start_item[0] = 1;
		else
			l->p.start_item[0] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}
