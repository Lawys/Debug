/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:30 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_grenade_distance_negative_delete(t_variable_list *l)
{
	int	ts;
	int	tn;

	l->gr.gd = 0;
	tn = --l->triangle_number;
	ts = l->gr.ts;
	l->t.area[ts] = l->t.area[tn];
	l->t.group[ts] = l->t.group[tn];
	l->t.x1[ts] = l->t.x1[tn];
	l->t.y1[ts] = l->t.y1[tn];
	l->t.z1[ts] = l->t.z1[tn];
	l->t.x2[ts] = l->t.x2[tn];
	l->t.y2[ts] = l->t.y2[tn];
	l->t.z2[ts] = l->t.z2[tn];
	l->t.x3[ts] = l->t.x3[tn];
	l->t.y3[ts] = l->t.y3[tn];
	l->t.z3[ts] = l->t.z3[tn];
	l->t.texture_size_x[ts] = l->t.texture_size_x[tn];
	l->t.texture_size_y[ts] = l->t.texture_size_y[tn];
	l->t.texture_light[ts] = l->t.texture_light[tn];
	l->t.texture_shift_x[ts] = l->t.texture_shift_x[tn];
	l->t.texture_shift_y[ts] = l->t.texture_shift_y[tn];
	l->t.texture_id[ts] = l->t.texture_id[tn];
	l->t.texture_opacity[ts] = l->t.texture_opacity[tn];
	l->t.texture_sides[ts] = l->t.texture_sides[tn];
}

void		ft_hud_play_grenade_distance_negative_explosion(t_variable_list *l)
{
	int	i;

	if (sqrt((l->gr.sx - l->p.x) * (l->gr.sx - l->p.x) +
		(l->gr.sy - l->p.y) * (l->gr.sy - l->p.y) +
		(l->gr.sz - l->p.z) * (l->gr.sz - l->p.z)) < 200)
		l->p.hp = 0;
	i = -1;
	while (++i < l->triangle_number)
		if (l->g.npc[l->t.group[i]] == 1)
		{
			ft_action_calculate_center(l, l->t.group[i]);
			if (sqrt((l->me.x - l->gr.sx) * (l->me.x - l->gr.sx) +
				(l->me.y - l->gr.sy) * (l->me.y - l->gr.sy) +
				(l->me.z - l->gr.sz) * (l->me.z - l->gr.sz)) < 200)
				l->g.npc_hp[l->t.group[i]] = -10;
		}
}

void		ft_hud_play_grenade_distance_negative_move(t_variable_list *l)
{
	l->t.x1[l->gr.ts] = l->gr.sx - 100 * l->e.c_h;
	l->t.y1[l->gr.ts] = l->gr.sy - 100;
	l->t.z1[l->gr.ts] = l->gr.sz - 100 * l->e.s_h;
	l->t.x2[l->gr.ts] = l->gr.sx;
	l->t.y2[l->gr.ts] = l->gr.sy + 100;
	l->t.z2[l->gr.ts] = l->gr.sz;
	l->t.x3[l->gr.ts] = l->gr.sx + 100 * l->e.c_h;
	l->t.y3[l->gr.ts] = l->gr.sy - 100;
	l->t.z3[l->gr.ts] = l->gr.sz + 100 * l->e.s_h;
	l->t.texture_size_x[l->gr.ts] = 55;
	l->t.texture_size_y[l->gr.ts] = 55;
	l->t.texture_shift_x[l->gr.ts] = -22;
	l->t.texture_shift_y[l->gr.ts] = 22;
	l->t.texture_id[l->gr.ts] = 39;
	l->t.texture_opacity[l->gr.ts] = 99;
}

void		ft_hud_play_grenade_distance_negative(t_variable_list *l)
{
	if (l->t.texture_opacity[l->gr.ts] < 100)
	{
		l->t.x1[l->gr.ts] = l->gr.sx - 100 * l->e.c_h;
		l->t.z1[l->gr.ts] = l->gr.sz - 100 * l->e.s_h;
		l->t.x3[l->gr.ts] = l->gr.sx + 100 * l->e.c_h;
		l->t.z3[l->gr.ts] = l->gr.sz + 100 * l->e.s_h;
		l->t.texture_opacity[l->gr.ts]--;
		if (l->t.texture_opacity[l->gr.ts] == 0)
			ft_hud_play_grenade_distance_negative_delete(l);
	}
	else
	{
		ft_hud_play_grenade_distance_negative_explosion(l);
		l->gr.sx -= l->gr.gx * 20;
		l->gr.sy -= l->gr.gy * 20;
		l->gr.sz -= l->gr.gz * 20;
		ft_hud_play_grenade_distance_negative_move(l);
	}
}

void		ft_hud_play_grenade(t_variable_list *l)
{
	if (l->gr.gd > 0)
		ft_hud_play_grenade_distance_positive(l);
	else if (l->gr.gd < 0)
		ft_hud_play_grenade_distance_negative(l);
}
