/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:39 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_pixels_initialize_part_2(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *tmp)
{
	int	ts;

	ts = tmp->t_s;
	tmp->nzvd = tmp->vd * tmp->nz;
	tmp->l = l->t.texture_light[ts] / 100.;
	tmp->v4x = (tmp->v1y * tmp->nz - tmp->ny * tmp->v1z);
	tmp->v4y = (tmp->v1z * tmp->nx - tmp->nz * tmp->v1x);
	tmp->v4z = (tmp->v1x * tmp->ny - tmp->nx * tmp->v1y);
	tmp->d01 = sqrt(tmp->v1x * tmp->v1x + tmp->v1y *
		tmp->v1y + tmp->v1z * tmp->v1z);
	tmp->d04 = sqrt(tmp->v4x * tmp->v4x + tmp->v4y *
		tmp->v4y + tmp->v4z * tmp->v4z);
	tmp->t_x1 = l->e.t_x1[ts];
	tmp->t_y1 = l->e.t_y1[ts];
	tmp->t_z1 = l->e.t_z1[ts];
	tmp->c = l->texture_colors[(int)l->t.texture_id[ts]];
	tmp->ttsix = l->t.texture_size_x[ts] / 100;
	tmp->ttshx = l->t.texture_shift_x[ts] * 10.24;
	tmp->ttsiy = l->t.texture_size_y[ts] / 100;
	tmp->ttshy = l->t.texture_shift_y[ts] * 10.24;
	tmp->o = l->t.texture_opacity[ts] / 100;
}

void		ft_engine_play_calculate_pixels_initialize_part_3(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *tmp)
{
	double	center;
	int		ts;
	int		group;

	ts = tmp->t_s;
	group = l->t.group[ts];
	if (l->g.npc[group] == 1)
	{
		if (l->g.npc_statement[group] < 4)
		{
			center = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts] +
				(l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]))) / 4;
			tmp->s = -atan2(center - l->p.x, l->t.z1[ts] - l->p.z);
			tmp->s = ((int)((tmp->s / M_PI * 180 - 202.5 +
				l->g.npc_o[group]) / 45) * 128.);
		}
		else
			tmp->s = l->g.npc_o[group] * 128.;
		tmp->ss = -l->g.npc_statement[group] * 132;
	}
	else
	{
		tmp->s = 0;
		tmp->ss = 0;
	}
}

void		ft_engine_play_calculate_pixels_while_y(
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
		if (s->t_d <= l->pixels_distance[s->x][s->y])
		{
			s->v = (((int)(fabs((((s->v4x * (s->c_x + s->t_x1) + s->v4y *
	(s->c_y + s->t_y1) + s->v4z * (s->c_z + s->t_z1)) / s->d04) * 10.24) *
	s->ttsiy + s->ttshy) + s->s) & 1023) + (((int)fabs((((s->v1x * (s->c_x +
	s->t_x1) + s->v1y * (s->c_y + s->t_y1) + s->v1z * (s->c_z + s->t_z1)) /
	s->d01) * 10.24) * s->ttsix - s->ttshx) + s->ss) & 1023) * 1024) * 4;
			if (s->c[s->v + 3] != 0)
			{
				l->pixels_distance[s->x][s->y] = s->t_d;
				l->pixels_triangle[s->x][s->y] = s->t_s;
				l->pixels_color[s->x][s->y] = (int)(s->l * s->c[s->v]) +
				(int)(s->l * s->c[s->v + 1]) * 256 +
				(int)(s->l * s->c[s->v + 2]) * 65536;
			}
		}
	}
}

void		ft_engine_play_calculate_pixels(t_variable_list *l)
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
		ft_engine_play_calculate_pixels_while_y(l, &tmp);
		tmp.fy[tmp.x] = WDH;
		tmp.ly[tmp.x] = -1;
	}
}

void		ft_engine_play_calculate_pixels_while_y_opacity_color(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *s)
{
	l->pixels_distance[s->x][s->y] = s->t_d;
	l->pixels_triangle[s->x][s->y] = s->t_s;
	l->pixels_color[s->x][s->y] =
		(int)(s->l * s->c[s->v] * s->o) +
		(int)((l->pixels_color[s->x][s->y] & 0xff) *
			(1 - s->o)) +
		((int)(s->l * s->c[s->v + 1] * s->o) +
			(int)(((l->pixels_color[s->x][s->y] >> 8) & 0xff) *
				(1 - s->o))) * 256 +
		((int)(s->l * s->c[s->v + 2] * s->o) +
			(int)(((l->pixels_color[s->x][s->y] >> 16) & 0xff) *
				(1 - s->o))) * 65536;
}
