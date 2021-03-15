/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_size_to_window(t_variable_list *l)
{
	int	i;
	int	j;
	int	k;
	int	n;

	i = 0;
	while (i < WDHF)
	{
		j = 0;
		while (j < WDWF)
		{
			k = -1;
			while (++k < 2)
			{
				n = -1;
				while (++n < 2)
					if (l->pixels_distance[j / 2][i / 2] > 0)
						l->pixels[(k + i) * (WDWF) + (j + n)] =
						l->pixels_color[j / 2][i / 2];
			}
			j += 2;
		}
		i += 2;
	}
}

void		ft_loop_menu_1(t_variable_list *l)
{
	ft_npc(l);
	ft_engine_play_p(l);
	ft_size_to_window(l);
	ft_hud_play(l);
	ft_action(l);
}

void		ft_loop_menu_2(t_variable_list *l)
{
	ft_engine_play_me(l);
	if (l->triangle_select != -1)
	{
		ft_engine_set_window_blue_border_triangle1(l);
		ft_engine_set_window_blue_border_triangle2(l);
	}
	else if (l->area_select != -1)
	{
		ft_engine_set_window_red_border_area1(l);
		ft_engine_set_window_red_border_area2(l);
	}
	else if (l->group_select != -1)
	{
		ft_engine_set_window_green_border_group1(l);
		ft_engine_set_window_green_border_group2(l);
	}
	ft_size_to_window(l);
	ft_map_editor(l);
}

void		ft_loop_menu_3(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[33];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 0;
	l->u.wsy = 0;
	ft_put_texture(l);
	if (l->i.state[SDL_SCANCODE_RETURN])
		ft_free_and_exit(l, "You lose.\n");
}

void		ft_loop_menu_4(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[36];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 0;
	l->u.wsy = 0;
	ft_put_texture(l);
	if (l->i.state[SDL_SCANCODE_RETURN])
		ft_free_and_exit(l, "You win.\n");
}
