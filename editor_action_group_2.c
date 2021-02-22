/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_group_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:04 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 16:40:01 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_action_position_y_up(variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.y1[i] += l->me.mult / 100;
			l->t.y2[i] += l->me.mult / 100;
			l->t.y3[i] += l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_group_action_position_y_down(variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.y1[i] -= l->me.mult / 100;
			l->t.y2[i] -= l->me.mult / 100;
			l->t.y3[i] -= l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_group_action_position_y(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_group_action_position_y_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_group_action_position_y_down(l);
	}
}

void		ft_map_editor_group_action_position_z_up(variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.z1[i] += l->me.mult / 100;
			l->t.z2[i] += l->me.mult / 100;
			l->t.z3[i] += l->me.mult / 100;
		}
		i++;
	}
}

void		ft_map_editor_group_action_position_z_down(variable_list *l)
{
	int	i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.group[i] == l->group_select)
		{
			l->t.z1[i] -= l->me.mult / 100;
			l->t.z2[i] -= l->me.mult / 100;
			l->t.z3[i] -= l->me.mult / 100;
		}
		i++;
	}
}
