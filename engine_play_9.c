/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:44 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_pixels_while_y_opacity(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *s)
{
	while (++s->y <= s->my)
	{
		s->t_d = s->t_n / -(((double)s->y - WDH2) * s->ny +
			((double)s->x - WDW2) * s->nx + s->nzvd);
		s->c_x = ((double)s->x - WDW2) * s->t_d;
		s->c_y = ((double)s->y - WDH2) * s->t_d;
		s->c_z = s->vd * s->t_d;
		s->t_d = sqrt(s->c_x * s->c_x + s->c_y * s->c_y + s->c_z * s->c_z);
		if (s->t_d <= l->pixels_distance[s->x][s->y] ||
			l->t.texture_opacity[l->pixels_triangle[s->x][s->y]] < 100)
		{
			s->v = ((((int)fabs((((s->v4x * (s->c_x + s->t_x1) + s->v4y *
			(s->c_y + s->t_y1) + s->v4z * (s->c_z + s->t_z1)) / s->d04) *
			10.24) * s->ttsiy + s->ttshy) + (int)s->s) & 1023) + (((int)fabs(((
			(s->v1x * (s->c_x + s->t_x1) + s->v1y * (s->c_y + s->t_y1) +
			s->v1z * (s->c_z + s->t_z1)) / s->d01) * 10.24) * s->ttsix -
			s->ttshx) + s->ss) & 1023) * 1024) * 4;
			if (s->c[s->v + 3] != 0)
				ft_engine_play_calculate_pixels_while_y_opacity_color(l, s);
		}
	}
}

void		ft_engine_play_calculate_pixels_opacity(t_variable_list *l)
{
	t_engine_play_calculate_pixels_tmp	tmp;

	ft_engine_play_calculate_pixels_initialize_part_1(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_2(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_3(l, &tmp);
	tmp.t_d = -1;
	tmp.x = (int)(l->e.min_x - 1);
	while (++tmp.x <= tmp.mx)
	{
		tmp.y = (int)tmp.fy[tmp.x];
		tmp.my = (int)tmp.ly[tmp.x];
		ft_engine_play_calculate_pixels_while_y_opacity(l, &tmp);
		tmp.fy[tmp.x] = WDH;
		tmp.ly[tmp.x] = -1;
	}
}

void		ft_engine_play_p(t_variable_list *l)
{
	ft_engine_set_angles_value(l);
	ft_engine_set_triangles_points(l);
	ft_engine_calculate_triangles_distance(l);
	ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	ft_engine_play_calculate_p(l, 0, 0);
	l->pixels_color[WDW2][WDH2] = 0x00FF00;
}

void		ft_engine_play_me(t_variable_list *l)
{
	ft_engine_set_angles_value(l);
	ft_engine_set_triangles_points(l);
	ft_engine_calculate_triangles_distance(l);
	ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	ft_engine_play_calculate_me(l);
	l->pixels_color[WDW2][WDH2] = 0x00FF00;
}

void		ft_engine_set_triangles_points(t_variable_list *l)
{
	int	ts;
	int	tn;

	tn = l->triangle_number;
	ts = -1;
	while (++ts < tn)
	{
		if (l->g.sprite[l->t.group[ts]] == 1 || l->g.npc[l->t.group[ts]] == 1)
			ft_engine_set_triangles_points_sprite(l, ts);
		else
			ft_engine_set_triangles_points_no_sprite(l, ts);
	}
}
