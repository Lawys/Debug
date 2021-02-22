/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 17:08:08 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_initialize_SDL(variable_list *l)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		write(1, "Failed to initialize SDL\n", 26);
		free(l);
		exit(-1);
	}
	if (!(l->window = SDL_CreateWindow("Doom_nukem windows",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WDWF, WDHF, 0)))
	{
		write(1, "Failed to open window\n", 23);
		SDL_Quit();
		free(l);
		exit(-1);
	}
	if (!(l->window_surface = SDL_GetWindowSurface(l->window)))
	{
		write(1, "Failed to GetWindowSurface\n", 28);
		SDL_DestroyWindow(l->window);
		SDL_Quit();
		free(l);
		exit(-1);
	}
	l->pixels = (Uint32*)l->window_surface->pixels;
}

void		ft_reset_arrays(variable_list *l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WDW)
	{
		j = -1;
		while (++j < WDH)
		{
			l->pixels_distance[i][j] = 9999999;
			l->pixels_triangle[i][j] = -1;
		}
	}
}

void		ft_map_reader_error(variable_list *l, char *file, double value,
	double min, double max)
{
	if (value < min || value > max)
	{
		free(file);
		ft_free_and_exit(l, "Load File Error\n");
	}
}

void		ft_reader_textures(variable_list *l, int *i, char *file, int size)
{
	int j;

	*i = -1;
	l->texture_number = 49;
	while (++(*i) < (1024 * 1024 * 4 * 49) && *i <= size)
	{
		if (*i % (1024 * 1024 * 4) == 0)
		{
			j = 0;
			l->texture_number--;
		}
		l->texture_colors[l->texture_number][j] = file[*i];
		j++;
	}
	l->texture_number = 49;
	if (write(1, "Textures OK.\n", 13) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}

void		ft_reader_triangles_error(
	variable_list *l, int *i, char *file, int size)
{
	if (write(1, "Triangles OK.\n", 14) == -1)
		ft_free_and_exit(l, "Write File Error\n");
	if (*i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}
}
