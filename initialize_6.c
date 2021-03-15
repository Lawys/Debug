/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_reader_triangles_w1(t_variable_list *l, int *i)
{
	l->t.area[l->triangle_number] = (int)ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.area[l->triangle_number], 1,
		MAX_AREAS - 1);
	l->t.group[l->triangle_number] = (int)ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.group[l->triangle_number], 1,
		MAX_GROUPS - 1);
	l->t.x1[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.x1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y1[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.y1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z1[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.z1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.x2[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.x2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y2[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.y2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z2[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.z2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
}

void		ft_reader_triangles_w2(t_variable_list *l, int *i)
{
	l->t.x3[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.x3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y3[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.y3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z3[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.z3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.texture_id[l->triangle_number] = (int)ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.texture_id[l->triangle_number], 0,
		(double)l->texture_number - 1);
	l->t.texture_size_x[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.texture_size_x[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_size_y[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.texture_size_y[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_shift_x[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.texture_shift_x[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_shift_y[l->triangle_number] = ft_atoi(l->file, i);
	ft_map_reader_error(l, l->t.texture_shift_y[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
}

void		ft_reader_triangles(t_variable_list *l, int *i, int size)
{
	*i += 3;
	while (*i + 3 <= size && l->file[*i + 3] != '#')
	{
		ft_reader_triangles_w1(l, i);
		ft_reader_triangles_w2(l, i);
		l->t.texture_light[l->triangle_number] = ft_atoi(l->file, i);
		ft_map_reader_error(l, l->t.texture_light[l->triangle_number],
			0, 100);
		l->t.texture_opacity[l->triangle_number] = ft_atoi(l->file, i);
		ft_map_reader_error(l, l->t.texture_opacity[l->triangle_number],
			10, 100);
		l->t.texture_sides[l->triangle_number] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->t.texture_sides[l->triangle_number],
			-1, 1);
		l->triangle_number++;
	}
	ft_reader_triangles_error(l, i, size);
}

void		ft_reader_groups_error(
	t_variable_list *l, int *i, int size)
{
	if (_write(1, "Groups OK.\n", 11) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i == size)
	{
		free(l->file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}

void		ft_reader_groups_strings(
	t_variable_list *l, int *i, int size)
{
	int k;
	int j;

	j = l->u.tsx;
	k = 0;
	while (++(*i) <= size && l->file[*i] != ',' && k < 57
		&& l->file[*i] >= '!' && l->file[*i] <= 'Z')
	{
		l->g.action_enable[j][k] = l->file[*i];
		k++;
	}
	k = 0;
	while (++(*i) <= size && l->file[*i] != ',' && k < 57
		&& l->file[*i] >= '!' && l->file[*i] <= 'Z')
	{
		l->g.action_disable[j][k] = l->file[*i];
		k++;
	}
}
