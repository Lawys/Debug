/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:09 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_engine_play_calculate_skip_triangles_behind_player(
t_variable_list *l)
{
	int		i;
	double	*distance;

	distance = l->e.t_d;
	i = -1;
	while (distance[++i] < 1 && i < l->triangle_number)
		continue;
	return (i);
}

void	ft_engine_play_calculate_initialize_points_vectors_normals(
t_variable_list *l)
{
	int	ts;

	ts = l->e.t_s;
	l->e.tmp_z1 = l->e.t_z1[ts];
	l->e.tmp_z2 = l->e.t_z2[ts];
	l->e.tmp_z3 = l->e.t_z3[ts];
	l->e.tmp_x1 = l->e.t_x1[ts];
	l->e.tmp_x2 = l->e.t_x2[ts];
	l->e.tmp_x3 = l->e.t_x3[ts];
	l->e.tmp_y1 = l->e.t_y1[ts];
	l->e.tmp_y2 = l->e.t_y2[ts];
	l->e.tmp_y3 = l->e.t_y3[ts];
	l->e.v1x = l->e.tmp_x2 - l->e.tmp_x1;
	l->e.v2x = l->e.tmp_x3 - l->e.tmp_x1;
	l->e.v1y = l->e.tmp_y2 - l->e.tmp_y1;
	l->e.v2y = l->e.tmp_y3 - l->e.tmp_y1;
	l->e.v1z = l->e.tmp_z2 - l->e.tmp_z1;
	l->e.v2z = l->e.tmp_z3 - l->e.tmp_z1;
	l->e.nx = l->e.v1y * l->e.v2z - l->e.v1z * l->e.v2y;
	l->e.ny = l->e.v1z * l->e.v2x - l->e.v1x * l->e.v2z;
	l->e.nz = l->e.v1x * l->e.v2y - l->e.v1y * l->e.v2x;
	l->e.t_normal = (l->e.tmp_y1 * l->e.ny + l->e.tmp_x1 *
		l->e.nx + l->e.tmp_z1 * l->e.nz);
}

void	ft_engine_play_calculate_points_to_front_ref_1(t_variable_list *l)
{
	double	t;
	double	x;
	double	y;
	double	z;
	int		ts;

	ts = l->e.t_s;
	x = l->e.t_x1[ts];
	y = l->e.t_y1[ts];
	z = l->e.t_z1[ts];
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y1 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x1 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z1 = 1;
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 1;
}

void	ft_engine_play_calculate_points_to_front_ref_2(t_variable_list *l)
{
	double	t;
	double	x;
	double	y;
	double	z;
	int		ts;

	ts = l->e.t_s;
	x = l->e.t_x2[ts];
	y = l->e.t_y2[ts];
	z = l->e.t_z2[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y2 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x2 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z2 = 1;
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 2;
}

void	ft_engine_play_calculate_points_to_front_ref_3(t_variable_list *l)
{
	double	t;
	double	x;
	double	y;
	double	z;
	int		ts;

	ts = l->e.t_s;
	x = l->e.t_x3[ts];
	y = l->e.t_y3[ts];
	z = l->e.t_z3[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y3 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x3 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z3 = 1;
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 3;
}
