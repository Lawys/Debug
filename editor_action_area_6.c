/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_area_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:42 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_action_link1(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link1[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_link2(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link2[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_link3(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link3[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_link4(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link4[l->area_select], 1, MAX_AREAS - 1);
	}
}

void		ft_map_editor_area_action_link5(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link5[l->area_select], 1, MAX_AREAS - 1);
	}
}
