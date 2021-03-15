/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:33 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_event_map_editor_mode_moving_y(t_variable_list *l)
{
	if (l->i.state[20])
		l->p.y += l->p.speed;
	else if (l->i.state[8])
		l->p.y -= l->p.speed;
}

void		ft_event_map_editor_mode(t_variable_list *l)
{
	l->p.speed = 4;
	ft_event_map_editor_mode_motion(l);
	ft_event_map_editor_mode_moving(l);
	ft_event_map_editor_mode_moving_y(l);
	ft_event_map_editor_mode_select_on_click(l);
}

void		ft_events_init(t_variable_list *l)
{
	l->i.scroll_up = 0;
	l->i.scroll_down = 0;
	l->i.key_input = 0;
	SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
	while (SDL_PollEvent(&l->event))
	{
		if (l->event.type == SDL_MOUSEWHEEL)
		{
			if (l->event.wheel.y > 0)
				l->i.scroll_up = 1;
			else if (l->event.wheel.y < 0)
				l->i.scroll_down = 1;
		}
		if (l->event.key.state != 0)
			l->i.key_input = l->event.key.state;
	}
	l->i.state = (Uint8*)SDL_GetKeyboardState(NULL);
	l->i.mouse = SDL_GetMouseState(&l->i.mouse_x, &l->i.mouse_y);
	ft_event_map_editor_mode_mouse_time_pressing_counter(l);
}

void		ft_events(t_variable_list *l)
{
	ft_events_init(l);
	if (l->i.state[SDL_SCANCODE_ESCAPE] || l->event.type == SDL_QUIT)
		ft_free_and_exit(l, "Escape.\n");
	if (l->writing_mode == 0)
	{
		if (l->menu_mode == 1)
			ft_event_playing_mode(l);
		else if (l->menu_mode == 2)
		{
			ft_event_map_editor_mode(l);
			if (l->i.state[53])
			{
				l->i.state[53] = 0;
				ft_hud_main_menu_play(l);
			}
		}
	}
}
