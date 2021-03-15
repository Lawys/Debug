/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:12 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_points_to_front_no_ref_1(
t_variable_list *l)
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
}

void		ft_engine_play_calculate_points_to_front_no_ref_2(
t_variable_list *l)
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
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y1 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x1 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z1 = 1;
}

void		ft_engine_play_calculate_points_to_front_no_ref_3(
t_variable_list *l)
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
}

void		ft_engine_play_calculate_points_to_front_no_ref_4(
t_variable_list *l)
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
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y2 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x2 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z2 = 1;
}

void		ft_engine_play_calculate_points_to_front_no_ref_5(
t_variable_list *l)
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
}
