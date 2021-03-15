/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_action_group_8.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:33 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_group_action_create_npc(t_variable_list *l)
{
	int	ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1 ||
			l->triangle_number + 1 == MAX_TRIANGLES - 1)
			return ;
		ft_map_editor_group_action_check_free_group(l);
		if (l->me.new_group == MAX_GROUPS)
			return ;
		l->g.npc[l->me.new_group] = 1;
		ts = l->triangle_number++;
		ft_map_editor_group_action_create_npc_triangle_1(l, ts);
		ft_map_editor_group_action_create_npc_triangle_2(l, ts);
		l->group_select = l->me.new_group;
	}
}

void		ft_map_editor_group_action_duplicate_set_values(t_variable_list *l,
int ts)
{
	int	tn;

	tn = l->triangle_number++;
	l->t.area[tn] = l->t.area[ts];
	l->t.group[tn] = l->me.new_group;
	l->t.x1[tn] = l->t.x1[ts];
	l->t.y1[tn] = l->t.y1[ts];
	l->t.z1[tn] = l->t.z1[ts];
	l->t.x2[tn] = l->t.x2[ts];
	l->t.y2[tn] = l->t.y2[ts];
	l->t.z2[tn] = l->t.z2[ts];
	l->t.x3[tn] = l->t.x3[ts];
	l->t.y3[tn] = l->t.y3[ts];
	l->t.z3[tn] = l->t.z3[ts];
	l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
	l->t.texture_light[tn] = l->t.texture_light[ts];
	l->t.texture_shift_x[tn] = l->t.texture_shift_x[ts];
	l->t.texture_shift_y[tn] = l->t.texture_shift_y[ts];
	l->t.texture_id[tn] = l->t.texture_id[ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
	l->t.texture_sides[tn] = l->t.texture_sides[ts];
}

void		ft_map_editor_group_action_duplicate(t_variable_list *l)
{
	int	ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		ft_map_editor_group_action_check_free_group(l);
		if (l->me.new_group == MAX_GROUPS)
			return ;
		l->g.sprite[l->me.new_group] = l->g.sprite[l->group_select];
		l->g.npc[l->me.new_group] = l->g.npc[l->group_select];
		l->g.no_block[l->me.new_group] = l->g.no_block[l->group_select];
		ts = -1;
		while (++ts < l->triangle_number)
			if (l->t.group[ts] == l->group_select)
			{
				if (l->triangle_number == MAX_TRIANGLES - 1)
					return ;
				ft_map_editor_group_action_duplicate_set_values(l, ts);
			}
		l->group_select = l->me.new_group;
	}
}

void		ft_map_editor_group_action_delete_set_values(t_variable_list *l,
int ts)
{
	--l->triangle_number;
	l->t.area[ts] = l->t.area[l->triangle_number];
	l->t.group[ts] = l->t.group[l->triangle_number];
	l->g.npc[l->t.group[ts]] = 0;
	l->g.no_block[l->t.group[ts]] = 0;
	l->g.sprite[l->t.group[ts]] = 0;
	l->g.interact[l->t.group[ts]] = 0;
	l->t.x1[ts] = l->t.x1[l->triangle_number];
	l->t.y1[ts] = l->t.y1[l->triangle_number];
	l->t.z1[ts] = l->t.z1[l->triangle_number];
	l->t.x2[ts] = l->t.x2[l->triangle_number];
	l->t.y2[ts] = l->t.y2[l->triangle_number];
	l->t.z2[ts] = l->t.z2[l->triangle_number];
	l->t.x3[ts] = l->t.x3[l->triangle_number];
	l->t.y3[ts] = l->t.y3[l->triangle_number];
	l->t.z3[ts] = l->t.z3[l->triangle_number];
	l->t.texture_size_x[ts] = l->t.texture_size_x[l->triangle_number];
	l->t.texture_size_y[ts] = l->t.texture_size_y[l->triangle_number];
	l->t.texture_light[ts] = l->t.texture_light[l->triangle_number];
	l->t.texture_shift_x[ts] = l->t.texture_shift_x[l->triangle_number];
	l->t.texture_shift_y[ts] = l->t.texture_shift_y[l->triangle_number];
	l->t.texture_id[ts] = l->t.texture_id[l->triangle_number];
	l->t.texture_opacity[ts] = l->t.texture_opacity[l->triangle_number];
	l->t.texture_sides[ts] = l->t.texture_sides[l->triangle_number];
}

void		ft_map_editor_group_action_delete(t_variable_list *l)
{
	int	ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		ts = -1;
		while (++ts < l->triangle_number)
			if (l->t.group[ts] == l->group_select)
			{
				ft_map_editor_group_action_delete_set_values(l, ts);
				ts--;
			}
		l->group_select = -1;
	}
}
