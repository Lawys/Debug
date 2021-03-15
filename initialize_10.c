/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_loop(t_variable_list *l)
{
	while (1)
	{
		if (SDL_UpdateWindowSurface(l->window) < 0)
			ft_free_and_exit(l, "SDL_UpdateWindowSurface Error\n");
		ft_reset_arrays(l);
		if (l->menu_mode == 0)
			ft_hud_main_menu(l);
		else
		{
			if (l->menu_mode == 1)
				ft_loop_menu_1(l);
			else if (l->menu_mode == 2)
				ft_loop_menu_2(l);
			else if (l->menu_mode == 3)
				ft_loop_menu_3(l);
			else if (l->menu_mode == 4)
				ft_loop_menu_4(l);
			ft_get_time(l);
		}
		ft_events(l);
	}
}

int			main(int argc, char **argv)
{
	t_variable_list *l;

	if (!(l = malloc(sizeof(t_variable_list))))// || argc != 2)
	{
		_write(1, "Start Error\n", 13);
		exit(0);
	}
	ft_initialize_variables(l);
	ft_initialize_sdl(l);
	ft_reader(l, argv);
	ft_loop(l);
	return (0);
}
