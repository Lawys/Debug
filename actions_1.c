/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:23:45 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:19:59 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_action_x(t_variable_list *l, int group, int c, char *str)
{
	double	value;
	int		i;

	value = ft_atoi(str, &c);
	if (str[c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.x1[i] += value;
				l->t.x2[i] += value;
				l->t.x3[i] += value;
			}
		}
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_y(t_variable_list *l, int group, int c, char *str)
{
	double	value;
	int		i;

	value = ft_atoi(str, &c);
	if (str[c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.y1[i] += value;
				l->t.y2[i] += value;
				l->t.y3[i] += value;
			}
		}
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_z(t_variable_list *l, int group, int c, char *str)
{
	double	value;
	int		i;

	value = ft_atoi(str, &c);
	if (str[c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.z1[i] += value;
				l->t.z2[i] += value;
				l->t.z3[i] += value;
			}
		}
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_calculate_center(t_variable_list *l, int group)
{
	int	i;
	int	s;

	l->me.x = 0;
	l->me.y = 0;
	l->me.z = 0;
	s = 0;
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			s++;
			l->me.x += (l->t.x1[i] + l->t.x2[i] + l->t.x3[i]) / 3;
			l->me.y += (l->t.y1[i] + l->t.y2[i] + l->t.y3[i]) / 3;
			l->me.z += (l->t.z1[i] + l->t.z2[i] + l->t.z3[i]) / 3;
		}
	l->me.x = l->me.x / s;
	l->me.y = l->me.y / s;
	l->me.z = l->me.z / s;
}

void		ft_action_h_rotate(t_variable_list *l, int group)
{
	int		i;
	double	tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.x1[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z1[i] = -(l->t.x1[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x1[i] = tmp;
			tmp = (l->t.x2[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z2[i] = -(l->t.x2[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x2[i] = tmp;
			tmp = (l->t.x3[i] - l->me.x) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.x;
			l->t.z3[i] = -(l->t.x3[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x3[i] = tmp;
		}
}
