/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_initialize_variables_triangles(t_variable_list *l)
{
	int	i;

	i = -1;
	while (++i < MAX_TRIANGLES)
	{
		l->e.t_d[i] = 0;
		l->e.t_z1[i] = 0;
		l->e.t_z2[i] = 0;
		l->e.t_z3[i] = 0;
		l->e.t_x1[i] = 0;
		l->e.t_x2[i] = 0;
		l->e.t_x3[i] = 0;
		l->e.t_y1[i] = 0;
		l->e.t_y2[i] = 0;
		l->e.t_y3[i] = 0;
		l->e.t_id[i] = 0;
	}
}

void		ft_initialize_variables_groups(t_variable_list *l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAX_GROUPS)
	{
		l->g.sprite[i] = 0;
		l->g.npc[i] = 0;
		l->g.no_block[i] = 0;
		l->action_v1[i] = 0;
		l->g.npc_o[i] = 0;
		l->g.npc_hp[i] = 3;
		l->g.npc_statement[i] = 0;
		l->g.npc_timer[i] = 1;
		l->g.exist[i] = 1;
		l->g.action_timer[i] = -1;
		l->g.action_statement[i] = 0;
		l->g.interact[i] = 0;
		j = -1;
		while (++j < 67)
		{
			l->g.action_enable[i][j] = 0;
			l->g.action_disable[i][j] = 0;
		}
	}
}

void		ft_initialize_variables_areas(t_variable_list *l)
{
	int	i;

	i = -1;
	while (++i < MAX_AREAS)
	{
		l->link1[i] = -1;
		l->link2[i] = -1;
		l->link3[i] = -1;
		l->link4[i] = -1;
		l->link5[i] = -1;
		l->link6[i] = -1;
	}
}

void		ft_initialize_variables_1(t_variable_list *l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WDW)
	{
		l->e.first_y[i] = WDH;
		l->e.last_y[i] = -1;
	}
	i = -1;
	while (++i < 50)
	{
		j = -1;
		while (++j < 200)
			l->action_select[i][j] = 0;
	}
	i = -1;
	while (++i < 15)
	{
		l->u.str[i] = 0;
		l->me.str[i] = 0;
	}
}

void		ft_initialize_variables_2(t_variable_list *l)
{
	l->player_area = 0;
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
	l->triangle_number = 0;
	l->texture_number = 0;
	l->group_number = 0;
	l->area_number = 0;
	l->p.x = -163.22;
	l->p.y = 190;
	l->p.z = -243.15;
	l->p.h = 0;
	l->p.v = 0;
	l->p.r = 0;
	l->writing_mode = 0;
	l->triangle_select = -1;
	l->area_select = -1;
	l->group_select = -1;
	l->menu_select = 0;
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
	l->texture_number = 0;
	l->me.area_switch_value = 1;
	l->me.group_switch_value = 1;
	l->e.view_distance = (double)WDW2 / tan(M_PI / 4);
	l->gravity = 0;
}
