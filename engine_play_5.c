/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:25 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_triangle_line_1_2(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x2;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y2;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}

void		ft_engine_play_calculate_triangle_line_1_3(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x3;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y3;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}

void		ft_engine_play_calculate_triangle_line_2_3(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x2;
	x[1] = l->e.p_x3;
	y[0] = l->e.p_y2;
	y[1] = l->e.p_y3;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}

void		ft_engine_play_calculate_triangle_line_1_4(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y4;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}

void		ft_engine_play_calculate_triangle_line_2_4(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x2;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y2;
	y[1] = l->e.p_y4;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
