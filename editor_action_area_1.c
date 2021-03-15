/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_area_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:21 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_area_action_select_area(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->area_select, 1, MAX_AREAS - 1);
}

void		ft_map_editor_area_action_switch_area(t_variable_list *l)
{
	int	i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->me.area_switch_value, 1, MAX_AREAS - 1);
		if (l->i.state[40] || l->i.state[88])
		{
			i = 0;
			while (i < l->triangle_number)
			{
				if (l->t.area[i] == l->area_select)
					l->t.area[i] = l->me.area_switch_value;
				i++;
			}
			l->area_select = l->me.area_switch_value;
			l->i.state[40] = 0;
			l->i.state[88] = 0;
			l->me.area_switch_value = 1;
		}
	}
}

void		ft_map_editor_area_action_position_x_up(t_variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.x1[i] += l->me.mult / 100;
			l->t.x2[i] += l->me.mult / 100;
			l->t.x3[i] += l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_area_action_position_x_down(t_variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.x1[i] -= l->me.mult / 100;
			l->t.x2[i] -= l->me.mult / 100;
			l->t.x3[i] -= l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_area_action_position_x(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_x_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_x_down(l);
	}
}
