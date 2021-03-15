/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_play_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:29 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_play_calculate_triangle_line_3_4(
t_variable_list *l, int i, double *first_y, double *last_y)
{
	double	x[2];
	double	y[2];
	double	t;
	double	v;

	x[0] = l->e.p_x3;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y3;
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

void		ft_engine_play_calculate_triangle_limits_no_ref(t_variable_list *l)
{
	int		x;
	double	max_x;
	double	*first_y;
	double	*last_y;

	x = (int)(l->e.min_x - 1.);
	max_x = l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;
	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_1_3(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_2_3(l, x, &first_y[x],
		&last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1 + 0.0;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
	}
}

void		ft_engine_play_calculate_triangle_limits_ref_1(t_variable_list *l)
{
	int		x;
	int		max_x;
	double	*first_y;
	double	*last_y;

	x = (int)(l->e.min_x - 1);
	max_x = (int)l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;
	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_2_3(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_3_4(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_1_4(l, x, &first_y[x],
		&last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
	}
}

void		ft_engine_play_calculate_triangle_limits_ref_2(t_variable_list *l)
{
	int		x;
	double	max_x;
	double	*first_y;
	double	*last_y;

	x = (int)(l->e.min_x - 1.);
	max_x = l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;
	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_1_3(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_3_4(l, x, &first_y[x],
		&last_y[x]);
		ft_engine_play_calculate_triangle_line_2_4(l, x, &first_y[x],
		&last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
	}
}

void		ft_engine_play_calculate_if_appear(t_variable_list *l)
{
	l->e.ref = 0;
	ft_engine_play_calculate_points_to_front(l);
	ft_engine_play_calculate_pixel_points(l);
	if (l->e.ref > 0)
		ft_engine_play_calculate_pixel_points_p4(l);
	if (l->e.min_x < 0)
		l->e.min_x = 0;
	if (l->e.max_x >= WDW)
		l->e.max_x = WDW - 1.;
	if (l->e.ref == 0)
		ft_engine_play_calculate_triangle_limits_no_ref(l);
	else if (l->e.ref == 1)
		ft_engine_play_calculate_triangle_limits_ref_1(l);
	else if (l->e.ref > 1)
		ft_engine_play_calculate_triangle_limits_ref_2(l);
}
