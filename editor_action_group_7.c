/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_group_7.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:29 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_action_interact(t_variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->g.interact[l->group_select] == 0)
		{
			l->g.interact[l->group_select] = 1;
		}
		else
			l->g.interact[l->group_select] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void		ft_map_editor_group_action_check_free_group(t_variable_list *l)
{
	int	i;

	l->me.new_group = 0;
	while (l->me.new_group < MAX_GROUPS)
	{
		i = 0;
		while (i < l->triangle_number)
		{
			if (l->t.group[i] == l->me.new_group)
				break ;
			i++;
		}
		if (i == l->triangle_number)
			break ;
		l->me.new_group++;
	}
}

void		ft_map_editor_group_action_create_npc_triangle_1(t_variable_list *l,
int ts)
{
	l->t.area[ts] = 1;
	l->t.group[ts] = l->me.new_group;
	l->t.x1[ts] = (int)l->p.x;
	l->t.y1[ts] = (int)l->p.y - 50.;
	l->t.z1[ts] = (int)l->p.z;
	l->t.x2[ts] = (int)l->p.x;
	l->t.y2[ts] = (int)l->p.y + 50.;
	l->t.z2[ts] = (int)l->p.z;
	l->t.x3[ts] = (int)l->p.x + 100.;
	l->t.y3[ts] = (int)l->p.y - 50.;
	l->t.z3[ts] = (int)l->p.z;
	l->t.texture_size_x[ts] = 12.5;
	l->t.texture_size_y[ts] = 12.5;
	l->t.texture_light[ts] = 100;
	l->t.texture_shift_x[ts] = 87.5;
	l->t.texture_shift_y[ts] = 0;
	l->t.texture_id[ts] = 27;
	l->t.texture_opacity[ts] = 100;
	l->t.texture_sides[ts] = 0;
}

void		ft_map_editor_group_action_create_npc_triangle_2_shift(
t_variable_list *l, int ts, int tn)
{
	l->t.texture_shift_x[tn] = -(l->t.texture_shift_x[ts] +
		sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts])) *
		l->t.texture_size_x[ts] / 100);
	l->t.texture_shift_y[tn] = -(l->t.texture_shift_y[ts] +
		sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts])) *
		l->t.texture_size_y[ts] / 100);
}

void		ft_map_editor_group_action_create_npc_triangle_2(t_variable_list *l,
int ts)
{
	int	tn;

	tn = l->triangle_number++;
	l->t.area[tn] = l->t.area[ts];
	l->t.group[tn] = l->t.group[ts];
	l->t.x1[tn] = l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]);
	l->t.y1[tn] = l->t.y2[ts] + (l->t.y3[ts] - l->t.y1[ts]);
	l->t.z1[tn] = l->t.z2[ts] + (l->t.z3[ts] - l->t.z1[ts]);
	l->t.x2[tn] = l->t.x3[ts];
	l->t.y2[tn] = l->t.y3[ts];
	l->t.z2[tn] = l->t.z3[ts];
	l->t.x3[tn] = l->t.x2[ts];
	l->t.y3[tn] = l->t.y2[ts];
	l->t.z3[tn] = l->t.z2[ts];
	l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
	l->t.texture_light[tn] = l->t.texture_light[ts];
	ft_map_editor_group_action_create_npc_triangle_2_shift(l, ts, tn);
	l->t.texture_id[tn] = l->t.texture_id[ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
	l->t.texture_sides[tn] = l->t.texture_sides[ts];
}
