/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:15 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:14 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_hud_play_item_1(t_variable_list *l)
{
	l->u.colors = l->texture_colors[35];
	l->u.wsx = 38.6;
	l->u.size = 1.875;
	if (l->p.animation_timer == 0)
		ft_hud_play_item_1_animation_1(l);
	else if (l->p.animation_timer > 15)
		ft_hud_play_item_1_animation_2(l);
	else if (l->p.animation_timer > 10)
		ft_hud_play_item_1_animation_3(l);
	else if (l->p.animation_timer > 5)
		ft_hud_play_item_1_animation_4(l);
	else if (l->p.animation_timer > 0)
		ft_hud_play_item_1_animation_5(l);
	ft_put_texture(l);
}

void		ft_hud_play_item_2_animation_1(t_variable_list *l)
{
	if (l->i.mouse == 1)
		l->p.animation_timer = 20;
	l->u.tsx = 627;
	l->u.tex = 1006;
	l->u.tsy = 106;
	l->u.tey = 416;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
}

void		ft_hud_play_item_2_animation_2(t_variable_list *l)
{
	l->u.tsx = 567;
	l->u.tex = 1006;
	l->u.tsy = 425;
	l->u.tey = 737;
	l->u.wsy = 100 - (((double)l->u.tey - l->u.tsy) * 100 * l->u.size) / 1024;
	l->p.animation_timer--;
}

void		ft_hud_play_item_2_animation_3_check_error(t_variable_list *l)
{
	if (l->triangle_number == MAX_TRIANGLES - 1)
		ft_free_and_exit(l, "MAX_TRIANGLES Error\n");
	ft_map_editor_group_action_check_free_group(l);
	if (l->me.new_group == MAX_GROUPS)
		ft_free_and_exit(l, "MAX_GROUPS Error\n");
}

void		ft_hud_play_item_2_animation_3_create_grenade(t_variable_list *l)
{
	l->gr.ts = l->triangle_number++;
	l->t.area[l->gr.ts] = 0;
	l->t.group[l->gr.ts] = l->me.new_group;
	l->g.no_block[(unsigned char)l->t.group[l->gr.ts]] = 1;
	l->t.x1[l->gr.ts] = l->gr.sx + 10;
	l->t.y1[l->gr.ts] = l->gr.sy - 10;
	l->t.z1[l->gr.ts] = l->gr.sz;
	l->t.x2[l->gr.ts] = l->gr.sx;
	l->t.y2[l->gr.ts] = l->gr.sy + 20;
	l->t.z2[l->gr.ts] = l->gr.sz;
	l->t.x3[l->gr.ts] = l->gr.sx - 10;
	l->t.y3[l->gr.ts] = l->gr.sy - 20;
	l->t.z3[l->gr.ts] = l->gr.sz;
	l->t.texture_size_x[l->gr.ts] = 600;
	l->t.texture_size_y[l->gr.ts] = 600;
	l->t.texture_light[l->gr.ts] = 100;
	l->t.texture_shift_x[l->gr.ts] = 5;
	l->t.texture_shift_y[l->gr.ts] = 20;
	l->t.texture_id[l->gr.ts] = 41;
	l->t.texture_opacity[l->gr.ts] = 100;
	l->t.texture_sides[l->gr.ts] = 0;
}
