/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:30:51 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_initialize_skybox_9(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 46;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_10(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 46;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_11(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 44;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_skybox_12(t_variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 44;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}

void		ft_initialize_variables(t_variable_list *l)
{
	ft_initialize_variables_triangles(l);
	ft_initialize_variables_groups(l);
	ft_initialize_variables_areas(l);
	ft_initialize_variables_1(l);
	ft_initialize_variables_2(l);
	ft_initialize_variables_3(l);
	ft_initialize_variables_4(l);
	ft_initialize_skybox_1(l);
	ft_initialize_skybox_2(l);
	ft_initialize_skybox_3(l);
	ft_initialize_skybox_4(l);
	ft_initialize_skybox_5(l);
	ft_initialize_skybox_6(l);
	ft_initialize_skybox_7(l);
	ft_initialize_skybox_8(l);
	ft_initialize_skybox_9(l);
	ft_initialize_skybox_10(l);
	ft_initialize_skybox_11(l);
	ft_initialize_skybox_12(l);
}
