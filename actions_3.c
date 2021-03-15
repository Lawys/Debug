/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:23:58 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_action_s_up(t_variable_list *l, int group, double value)
{
	int	i;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			l->t.x1[i] *= 1 + 0.001 * value;
			l->t.x2[i] *= 1 + 0.001 * value;
			l->t.x3[i] *= 1 + 0.001 * value;
			l->t.y1[i] *= 1 + 0.001 * value;
			l->t.y2[i] *= 1 + 0.001 * value;
			l->t.y3[i] *= 1 + 0.001 * value;
			l->t.z1[i] *= 1 + 0.001 * value;
			l->t.z2[i] *= 1 + 0.001 * value;
			l->t.z3[i] *= 1 + 0.001 * value;
			l->t.texture_size_x[i] /= 1 + 0.001 * value;
			l->t.texture_size_y[i] /= 1 + 0.001 * value;
		}
}

void		ft_action_s_do(t_variable_list *l, int group, double value)
{
	int	i;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			l->t.x1[i] /= 1 + 0.001 * value;
			l->t.x2[i] /= 1 + 0.001 * value;
			l->t.x3[i] /= 1 + 0.001 * value;
			l->t.y1[i] /= 1 + 0.001 * value;
			l->t.y2[i] /= 1 + 0.001 * value;
			l->t.y3[i] /= 1 + 0.001 * value;
			l->t.z1[i] /= 1 + 0.001 * value;
			l->t.z2[i] /= 1 + 0.001 * value;
			l->t.z3[i] /= 1 + 0.001 * value;
			l->t.texture_size_x[i] *= 1 + 0.001 * value;
			l->t.texture_size_y[i] *= 1 + 0.001 * value;
		}
}

void		ft_action_s_replace(t_variable_list *l, int group)
{
	double	xyz[3];
	double	p[3];
	int		i;

	p[0] = l->me.x;
	p[1] = l->me.y;
	p[2] = l->me.z;
	ft_action_calculate_center(l, group);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			xyz[0] = l->me.x - p[0];
			xyz[1] = l->me.y - p[1];
			xyz[2] = l->me.z - p[2];
			l->t.x1[i] -= xyz[0];
			l->t.x2[i] -= xyz[0];
			l->t.x3[i] -= xyz[0];
			l->t.y1[i] -= xyz[1];
			l->t.y2[i] -= xyz[1];
			l->t.y3[i] -= xyz[1];
			l->t.z1[i] -= xyz[2];
			l->t.z2[i] -= xyz[2];
			l->t.z3[i] -= xyz[2];
		}
}

void		ft_action_size(t_variable_list *l, int group, int c, char *str)
{
	double	value;

	value = ft_atoi(str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		if (value > 0)
			ft_action_s_up(l, group, value);
		else if (value < 0)
			ft_action_s_do(l, group, value);
		ft_action_s_replace(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_texture(t_variable_list *l, int group, int c, char *str)
{
	double	value;
	int		i;

	value = ft_atoi(str, &c);
	if (str[c] == ';' && value >= 0 && value < l->texture_number)
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
				l->t.texture_id[i] = (int)value;
		}
		ft_action_start(l, group, ++c, str);
	}
}
