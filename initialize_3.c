/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_initialize_skybox_4(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 45;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_5(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 47;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_6(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 47;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_7(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 48;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_8(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 48;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
