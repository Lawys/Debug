/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:34:41 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_map_editor_tool_set_mult(t_variable_list *l)
{
	l->me.mult = 100;
	if (l->i.state[225] && l->i.state[224])
		l->me.mult = 1;
	else if (l->i.state[225])
		l->me.mult = 1000;
	else if (l->i.state[224])
		l->me.mult = 10000;
}

void		ft_map_editor_menu_background(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 1600;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 2.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);
}

void		ft_map_editor_submenu_background(t_variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 820;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 34.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);
}

void		ft_map_editor_menu(t_variable_list *l)
{
	if (l->action_select[0][0] == 1)
	{
		l->menu_select = 0;
		l->action = 0;
		ft_map_editor_menu_background(l);
		ft_map_editor_menu_parameter_triangle(l);
		ft_map_editor_menu_parameter_area(l);
		ft_map_editor_menu_parameter_group(l);
		ft_map_editor_menu_parameter_light(l);
		ft_map_editor_menu_parameter_player(l);
		ft_map_editor_menu_parameter_game(l);
		ft_map_editor_menu_parameter_paint(l);
		ft_map_editor_menu_parameter_view_only(l);
		if (l->action_select[0][8])
			ft_value_editing_int(l, &l->view_only, 0, MAX_AREAS - 1);
	}
	else if (l->action_select[0][0] == 0)
	{
		l->triangle_select = -1;
		l->area_select = -1;
		l->group_select = -1;
		l->action_select[0][0]++;
	}
}

void		ft_map_editor(t_variable_list *l)
{
	l->writing_mode = 0;
	ft_map_editor_tool_set_mult(l);
	ft_map_editor_menu(l);
	ft_map_editor_triangle(l);
	ft_map_editor_area(l);
	ft_map_editor_group(l);
	ft_map_editor_player(l);
	ft_map_editor_game(l);
	ft_map_editor_paint(l);
}
