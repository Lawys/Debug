/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_initialize_variables_3(t_variable_list *l)
{
	l->cooldown = 0;
	l->me.color_white = l->texture_colors[10];
	l->me.color_blue = l->texture_colors[14];
	l->me.color_red = l->texture_colors[15];
	l->me.color_green = l->texture_colors[9];
	l->i.state = (Uint8*)SDL_GetKeyboardState(NULL);
	l->i.mouse = SDL_GetMouseState(&l->i.mouse_x, &l->i.mouse_y);
	l->menu_mode = 0;
	l->p.start_x = -375;
	l->p.start_y = 350;
	l->p.start_z = 840;
	l->p.start_hp = 100;
	l->p.start_item[0] = 1;
	l->p.start_item[1] = 1;
	l->p.start_item[2] = 0;
	l->p.start_item[3] = 0;
	l->p.start_item[4] = 0;
	l->p.start_item[5] = 0;
	l->p.hp = 100;
	l->p.animation_timer = 0;
	l->gr.gd = 0;
	l->npc_base_life = 3;
	l->npc_base_damage = 5;
	l->coef_gravity = 1;
}

void		ft_initialize_variables_4(t_variable_list *l)
{
	l->pe.pen_size = 0;
	l->pe.pen_texture = 0;
	l->pe.pen_group = 0;
	l->pe.pen_area = 0;
	l->pe.pen_opacity = 100;
	l->pe.pen_light = 100;
	l->view_only = 0;
	l->p.jump_timer = 0;
}

void		ft_initialize_skybox_1(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 43;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_2(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 43;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_3(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 45;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
