/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 17:00:57 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_reader_groups(variable_list *l, int *i, char *file, int size)
{
	int j;

	*i += 1;
	j = 0;
	while (*i + 3 <= size && file[*i + 3] != '#' && *i <= size)
	{
		l->g.sprite[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->g.sprite[j], 0, 1);
		l->g.npc[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->g.npc[j], 0, 1);
		l->g.no_block[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->g.no_block[j], 0, 1);
		l->g.interact[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->g.interact[j], 0, 1);
		l->u.tsx = j;
		ft_reader_groups_strings(l, i, file, size);
		j++;
	}
	ft_reader_groups_error(l, i, file, size);
}

void		ft_reader_areas_error(
	variable_list *l, int *i, char *file, int size)
{
	if (write(1, "Areas OK.\n", 10) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i != size - 6)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}

void		ft_reader_areas(variable_list *l, int *i, char *file, int size)
{
	int j;

	*i += 1;
	j = 0;
	while (*i + 3 <= size && file[*i + 3] != '#')
	{
		l->link1[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link1[j], -1, MAX_AREAS - 1);
		l->link2[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link2[j], -1, MAX_AREAS - 1);
		l->link3[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link3[j], -1, MAX_AREAS - 1);
		l->link4[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link4[j], -1, MAX_AREAS - 1);
		l->link5[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link5[j], -1, MAX_AREAS - 1);
		l->link6[j] = (int)ft_atoi(file, i);
		ft_map_reader_error(l, file, l->link6[j], -1, MAX_AREAS - 1);
		j++;
	}
	ft_reader_areas_error(l, i, file, size);
}

void		ft_reader(variable_list *l)
{
	char	c[1];
	int		i[3];
	char	*file;

	if ((i[3] = open("./FILE", O_RDONLY)) == -1)
		ft_free_and_exit(l, "Open File Error\n");
	i[1] = 0;
	while (read(i[0], c, 1) > 0)
		i[1]++;
	if (close(i[0]) == -1)
		ft_free_and_exit(l, "Close File Error\n");
	if (!(file = (char*)malloc((i[1] + 1) * sizeof(char))))
		ft_free_and_exit(l, "Malloc Error\n");
	if ((i[0] = open("./FILE", O_RDONLY)) == -1)
		ft_free_and_exit(l, "Open File Error\n");
	if (read(i[0], file, i[1]) == -1)
		ft_free_and_exit(l, "Read File Error\n");
	file[i[1]] = '\0';
	ft_reader_textures(l, &i[2], file, i[1]);
	ft_reader_triangles(l, &i[2], file, i[1]);
	ft_reader_groups(l, &i[2], file, i[1]);
	ft_reader_areas(l, &i[2], file, i[1]);
	free(file);
}

void		ft_engine_set_window_blue_border_triangle1(variable_list *l)
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
