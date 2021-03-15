/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_reader_groups(t_variable_list *l, int *i, int size)
{
	int j;

	*i += 1;
	j = 0;
	while (*i + 3 <= size && l->file[*i + 3] != '#' && *i <= size)
	{
		l->g.sprite[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->g.sprite[j], 0, 1);
		l->g.npc[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->g.npc[j], 0, 1);
		l->g.no_block[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->g.no_block[j], 0, 1);
		l->g.interact[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->g.interact[j], 0, 1);
		l->u.tsx = j;
		ft_reader_groups_strings(l, i, size);
		j++;
	}
	ft_reader_groups_error(l, i, size);
}

void		ft_reader_areas_error(
	t_variable_list *l, int *i, int size)
{
	if (_write(1, "Areas OK.\n", 10) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i != size - 6)
	{
		free(l->file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}

void		ft_reader_areas(t_variable_list *l, int *i, int size)
{
	int j;

	*i += 1;
	j = 0;
	while (*i + 3 <= size && l->file[*i + 3] != '#')
	{
		l->link1[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link1[j], -1, MAX_AREAS - 1);
		l->link2[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link2[j], -1, MAX_AREAS - 1);
		l->link3[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link3[j], -1, MAX_AREAS - 1);
		l->link4[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link4[j], -1, MAX_AREAS - 1);
		l->link5[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link5[j], -1, MAX_AREAS - 1);
		l->link6[j] = (int)ft_atoi(l->file, i);
		ft_map_reader_error(l, l->link6[j], -1, MAX_AREAS - 1);
		j++;
	}
	ft_reader_areas_error(l, i, size);
}

void		ft_reader(t_variable_list *l, char **argv)
{
	int		fd;
	int		i;

	if (!(l->file = (char*)malloc((205630323 + 1) * sizeof(char))))
		ft_free_and_exit(l, "Malloc Error\n");
	if ((_sopen_s(&fd, "./FILE", _O_RDONLY, _SH_DENYNO, 0)) == -1)
		ft_free_and_exit(l, "Open File Error\n");
	if (_read(fd, l->file, 205630323) == -1)
		ft_free_and_exit(l, "Read File Error\n");
	l->file[205630323] = '\0';
	ft_reader_textures(l, &i, 205630323);
	ft_reader_triangles(l, &i, 205630323);
	ft_reader_groups(l, &i, 205630323);
	ft_reader_areas(l, &i, 205630323);
	free(l->file);
}

void		ft_engine_set_window_blue_border_triangle1(t_variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->pixels_triangle[j][i] == l->triangle_select)
			{
				l->pixels_color[j][i] = 0x0000FF;
				while (j < WDW &&
					l->pixels_triangle[j][i] == l->triangle_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0x0000FF;
			}
			j++;
		}
		i++;
	}
}
