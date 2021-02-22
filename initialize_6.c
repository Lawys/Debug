/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 17:01:19 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_reader_triangles_w1(variable_list *l, int *i, char *file)
{
	l->t.area[l->triangle_number] = (int)ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.area[l->triangle_number], 1,
		MAX_AREAS - 1);
	l->t.group[l->triangle_number] = (int)ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.group[l->triangle_number], 1,
		MAX_GROUPS - 1);
	l->t.x1[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.x1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y1[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.y1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z1[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.z1[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.x2[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.x2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y2[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.y2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z2[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.z2[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
}

void		ft_reader_triangles_w2(variable_list *l, int *i, char *file)
{
	l->t.x3[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.x3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.y3[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.y3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.z3[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.z3[l->triangle_number], -MAX_GENERIC,
		MAX_GENERIC);
	l->t.texture_id[l->triangle_number] = (int)ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.texture_id[l->triangle_number], 0,
		(double)l->texture_number - 1);
	l->t.texture_size_x[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.texture_size_x[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_size_y[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.texture_size_y[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_shift_x[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.texture_shift_x[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
	l->t.texture_shift_y[l->triangle_number] = ft_atoi(file, i);
	ft_map_reader_error(l, file, l->t.texture_shift_y[l->triangle_number],
		-MAX_GENERIC, MAX_GENERIC);
}

void		ft_reader_triangles(variable_list *l, int *i, char *file, int size)
{
	*i += 3;
	while (*i + 3 <= size && file[*i + 3] != '#')
	{
		ft_reader_triangles_w1(l, i, file);
		ft_reader_triangles_w2(l, i, file);
		l->t.texture_light[l->triangle_number] = ft_atoi(file, i);
		ft_map_reader_error(l, file, l->t.texture_light[l->triangle_number],
			0, 100);
		l->t.texture_opacity[l->triangle_number] = ft_atoi(file, i);
		ft_map_reader_error(l, file, l->t.texture_opacity[l->triangle_number],
			10, 100);
		l->t.texture_sides[l->triangle_number] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->t.texture_sides[l->triangle_number],
			-1, 1);
		l->triangle_number++;
	}
	ft_reader_triangles_error(l, i, file, size);
}

void		ft_reader_groups_error(
	variable_list *l, int *i, char *file, int size)
{
	if (write(1, "Groups OK.\n", 11) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}

void		ft_reader_groups_strings(
	variable_list *l, int *i, char *file, int size)
{
	int k;

	k = 0;
	while (++(*i) <= size && file[*i] != ',' && k < 57
		&& file[*i] >= '!' && file[*i] <= 'Z')
	{
		l->g.action_enable[j][k] = file[*i];
		k++;
	}
	k = 0;
	while (++(*i) <= size && file[*i] != ',' && k < 57
		&& file[*i] >= '!' && file[*i] <= 'Z')
	{
		l->g.action_disable[j][k] = file[*i];
		k++;
	}
}
