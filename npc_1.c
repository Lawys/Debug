/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:49 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_npc_line_triangle_t(t_variable_list *l, t_npc_list *tmp)
{
	tmp->t =
		(tmp->nx * (l->p.x - tmp->p1x) + tmp->ny * (l->p.y - tmp->p1y) +
			tmp->nz * (l->p.z - tmp->p1z)) /
		(-tmp->vx * tmp->nx + -tmp->vy * tmp->ny + -tmp->vz * tmp->nz);
}

void		ft_npc_line_triangle_u(t_variable_list *l, t_npc_list *tmp)
{
	tmp->u =
		((-tmp->vy * tmp->v2z - -tmp->vz * tmp->v2y) * (l->p.x - tmp->p1x) +
		(-tmp->vz * tmp->v2x - -tmp->vx * tmp->v2z) * (l->p.y - tmp->p1y) +
		(-tmp->vx * tmp->v2y - -tmp->vy * tmp->v2x) * (l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx + tmp->vy * tmp->ny + tmp->vz * tmp->nz);
}

void		ft_npc_line_triangle_v(t_variable_list *l, t_npc_list *tmp)
{
	tmp->v =
		((tmp->v1y * -tmp->vz - tmp->v1z * -tmp->vy) * (l->p.x - tmp->p1x) +
		(tmp->v1z * -tmp->vx - tmp->v1x * -tmp->vz) * (l->p.y - tmp->p1y) +
		(tmp->v1x * -tmp->vy - tmp->v1y * -tmp->vx) * (l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx + tmp->vy * tmp->ny + tmp->vz * tmp->nz);
}

void		ft_npc_line_triangle_initialize(t_variable_list *l, t_npc_list *tmp,
int ts)
{
	tmp->p1x = l->t.x1[ts];
	tmp->p2x = l->t.x2[ts];
	tmp->p3x = l->t.x3[ts];
	tmp->p1y = l->t.y1[ts];
	tmp->p2y = l->t.y2[ts];
	tmp->p3y = l->t.y3[ts];
	tmp->p1z = l->t.z1[ts];
	tmp->p2z = l->t.z2[ts];
	tmp->p3z = l->t.z3[ts];
	tmp->v1x = tmp->p2x - tmp->p1x;
	tmp->v2x = tmp->p3x - tmp->p1x;
	tmp->v1y = tmp->p2y - tmp->p1y;
	tmp->v2y = tmp->p3y - tmp->p1y;
	tmp->v1z = tmp->p2z - tmp->p1z;
	tmp->v2z = tmp->p3z - tmp->p1z;
	tmp->nx = tmp->v1y * tmp->v2z - tmp->v1z * tmp->v2y;
	tmp->ny = tmp->v1z * tmp->v2x - tmp->v1x * tmp->v2z;
	tmp->nz = tmp->v1x * tmp->v2y - tmp->v1y * tmp->v2x;
}

void		ft_npc_hp_positive_init(
t_variable_list *l, t_npc_list *tmp, int group)
{
	int		ts;
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->t.group[ts] == group)
		{
			x = l->t.x1[ts] + (l->t.x3[ts] - l->t.x1[ts]) / 2;
			y = l->t.y1[ts] + (l->t.y2[ts] - l->t.y1[ts]) / 2;
			z = l->t.z1[ts];
			break ;
		}
	}
	tmp->vx = (x - l->p.x);
	tmp->vy = (y - l->p.y);
	tmp->vz = (z - l->p.z);
}
