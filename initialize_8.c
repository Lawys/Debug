/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_engine_set_window_blue_border_triangle2(t_variable_list *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->pixels_triangle[i][j] == l->triangle_select)
			{
				l->pixels_color[i][j] = 0x0000FF;
				while (j < WDH &&
				l->pixels_triangle[i][j] == l->triangle_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0x0000FF;
			}
			j++;
		}
		i++;
	}
}

void		ft_engine_set_window_red_border_area1(t_variable_list *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->t.area[l->pixels_triangle[j][i]] == l->area_select)
			{
				l->pixels_color[j][i] = 0xFF0000;
				while (j < WDW &&
				l->t.area[l->pixels_triangle[j][i]] == l->area_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0xFF0000;
			}
			j++;
		}
		i++;
	}
}

void		ft_engine_set_window_red_border_area2(t_variable_list *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->t.area[l->pixels_triangle[i][j]] == l->area_select)
			{
				l->pixels_color[i][j] = 0xFF0000;
				while (j < WDH &&
				l->t.area[l->pixels_triangle[i][j]] == l->area_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0xFF0000;
			}
			j++;
		}
		i++;
	}
}

void		ft_engine_set_window_green_border_group1(t_variable_list *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->t.group[l->pixels_triangle[j][i]] == l->group_select)
			{
				l->pixels_color[j][i] = 0x00FF00;
				while (j < WDW &&
	l->t.group[l->pixels_triangle[j][i]] == l->group_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0x00FF00;
			}
			j++;
		}
		i++;
	}
}

void		ft_engine_set_window_green_border_group2(t_variable_list *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->t.group[l->pixels_triangle[i][j]] == l->group_select)
			{
				l->pixels_color[i][j] = 0x00FF00;
				while (j < WDH &&
				l->t.group[l->pixels_triangle[i][j]] == l->group_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0x00FF00;
			}
			j++;
		}
		i++;
	}
}
