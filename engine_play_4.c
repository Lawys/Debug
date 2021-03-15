/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:16 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_points_to_front_no_ref_6(
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
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y3 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x3 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z3 = 1;
}

void		ft_engine_play_calculate_points_to_front_no_ref(t_variable_list *l)
{
	int		ts;
	double	z1;
	double	z2;
	double	z3;

	ts = l->e.t_s;
	z1 = l->e.t_z1[ts];
	z2 = l->e.t_z2[ts];
	z3 = l->e.t_z3[ts];
	if (z1 < 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_1(l);
	else if (z1 < 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_2(l);
	if (z2 < 1 && z1 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_3(l);
	else if (z2 < 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_4(l);
	if (z3 < 1 && z1 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_5(l);
	else if (z3 < 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_no_ref_6(l);
}

void		ft_engine_play_calculate_points_to_front(t_variable_list *l)
{
	int		ts;
	double	z1;
	double	z2;
	double	z3;

	ts = l->e.t_s;
	z1 = l->e.t_z1[ts];
	z2 = l->e.t_z2[ts];
	z3 = l->e.t_z3[ts];
	if (z1 < 1 && z2 >= 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_ref_1(l);
	else if (z2 < 1 && z1 >= 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_ref_2(l);
	else if (z3 < 1 && z1 >= 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_ref_3(l);
	else
		ft_engine_play_calculate_points_to_front_no_ref(l);
}

void		ft_engine_play_calculate_pixel_points(t_variable_list *l)
{
	double	t;

	t = -l->e.view_distance / -l->e.tmp_z1;
	l->e.p_y1 = l->e.tmp_y1 * t + WDH2;
	l->e.p_x1 = l->e.tmp_x1 * t + WDW2;
	t = -l->e.view_distance / -l->e.tmp_z2;
	l->e.p_y2 = l->e.tmp_y2 * t + WDH2;
	l->e.p_x2 = l->e.tmp_x2 * t + WDW2;
	t = -l->e.view_distance / -l->e.tmp_z3;
	l->e.p_y3 = l->e.tmp_y3 * t + WDH2;
	l->e.p_x3 = l->e.tmp_x3 * t + WDW2;
	l->e.min_x = l->e.p_x1;
	if (l->e.p_x2 < l->e.min_x)
		l->e.min_x = l->e.p_x2;
	if (l->e.p_x3 < l->e.min_x)
		l->e.min_x = l->e.p_x3;
	l->e.max_x = l->e.p_x1;
	if (l->e.p_x2 > l->e.max_x)
		l->e.max_x = l->e.p_x2;
	if (l->e.p_x3 > l->e.max_x)
		l->e.max_x = l->e.p_x3;
}

void		ft_engine_play_calculate_pixel_points_p4(t_variable_list *l)
{
	double	t;
	double	*min_x;
	double	*max_x;
	double	x4;

	t = -l->e.view_distance / -l->e.tmp_z4;
	l->e.p_y4 = l->e.tmp_y4 * t;
	l->e.p_x4 = l->e.tmp_x4 * t;
	l->e.p_x4 += WDW2;
	l->e.p_y4 += WDH2;
	min_x = &l->e.min_x;
	max_x = &l->e.max_x;
	x4 = l->e.p_x4;
	if (x4 < *min_x)
		*min_x = x4;
	if (x4 > *max_x)
		*max_x = x4;
}
