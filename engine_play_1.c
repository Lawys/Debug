/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:05 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_calculate_triangles_distance(
t_variable_list *l)
{
	int		i;
	int		end;
	double	*address[3];

	i = 0;
	end = l->triangle_number;
	address[0] = l->e.t_z1;
	address[1] = l->e.t_z2;
	address[2] = l->e.t_z3;
	while (i < end)
	{
		l->e.t_d[i] = address[0][i];
		if (address[1][i] > l->e.t_d[i])
			l->e.t_d[i] = address[1][i];
		if (address[2][i] > l->e.t_d[i])
			l->e.t_d[i] = address[2][i];
		l->e.t_id[i] = i;
		i++;
	}
}

void		ft_engine_set_x_y_z(
t_variable_list *l, double *x, double *y, double *z)
{
	*x = l->e.xp * l->e.c_h + (l->e.zp) * l->e.s_h;
	*z = -l->e.xp * l->e.s_h + (l->e.zp) * l->e.c_h;
	*y = l->e.yp * l->e.c_v - (*z) * l->e.s_v;
	*z = l->e.yp * l->e.s_v + (*z) * l->e.c_v;
	*y *= -1;
}

void		ft_engine_set_angles_value(t_variable_list *l)
{
	l->e.c_h = cos(l->p.h);
	l->e.s_h = sin(l->p.h);
	l->e.c_v = cos(l->p.v);
	l->e.s_v = sin(l->p.v);
	l->e.c_l = cos(l->p.r);
	l->e.s_l = sin(l->p.r);
}

void		ft_engine_set_triangles_points_sprite(
t_variable_list *l, int ts)
{
	double x;
	double z;
	double c;
	double s;

	x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts] +
		(l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]))) / 4;
	z = (l->t.z1[ts] + l->t.z2[ts] + l->t.z3[ts] +
		(l->t.z2[ts] + (l->t.z3[ts] - l->t.z1[ts]))) / 4;
	c = cos(-l->p.h);
	s = sin(-l->p.h);
	l->e.xp = (l->t.x1[ts] - x) * c + (l->t.z1[ts] - z) * s + x - l->p.x;
	l->e.yp = l->t.y1[ts] - l->p.y;
	l->e.zp = -(l->t.x1[ts] - x) * s + (l->t.z1[ts] - z) * c + z - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x1[ts], &l->e.t_y1[ts], &l->e.t_z1[ts]);
	l->e.xp = (l->t.x2[ts] - x) * c + (l->t.z2[ts] - z) * s + x - l->p.x;
	l->e.yp = l->t.y2[ts] - l->p.y;
	l->e.zp = -(l->t.x2[ts] - x) * s + (l->t.z2[ts] - z) * c + z - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x2[ts], &l->e.t_y2[ts], &l->e.t_z2[ts]);
	l->e.xp = (l->t.x3[ts] - x) * c + (l->t.z3[ts] - z) * s + x - l->p.x;
	l->e.yp = l->t.y3[ts] - l->p.y;
	l->e.zp = -(l->t.x3[ts] - x) * s + (l->t.z3[ts] - z) * c + z - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x3[ts], &l->e.t_y3[ts], &l->e.t_z3[ts]);
}

void		ft_engine_set_triangles_points_no_sprite(
t_variable_list *l, int ts)
{
	l->e.xp = l->t.x1[ts] - l->p.x;
	l->e.yp = l->t.y1[ts] - l->p.y;
	l->e.zp = l->t.z1[ts] - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x1[ts], &l->e.t_y1[ts],
	&l->e.t_z1[ts]);
	l->e.xp = l->t.x2[ts] - l->p.x;
	l->e.yp = l->t.y2[ts] - l->p.y;
	l->e.zp = l->t.z2[ts] - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x2[ts], &l->e.t_y2[ts],
	&l->e.t_z2[ts]);
	l->e.xp = l->t.x3[ts] - l->p.x;
	l->e.yp = l->t.y3[ts] - l->p.y;
	l->e.zp = l->t.z3[ts] - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x3[ts], &l->e.t_y3[ts],
	&l->e.t_z3[ts]);
}
