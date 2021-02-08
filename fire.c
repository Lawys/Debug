/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:14:45 by hmidoun           #+#    #+#             */
/*   Updated: 2021/02/08 20:20:29 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



double	dot(xyz_list a, xyz_list b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

int		point_in_triangle(xyz_list v0, xyz_list v1, xyz_list v2)
{
	double 	inv_denom;
	double	u;
	double	v;

	inv_denom = (dot(v0, v0) * dot(v1, v1) - dot(v0, v1) * dot(v0, v1));
	u = (dot(v1, v1) * dot(v0, v2) - dot(v0, v1) * dot(v1, v2)) / inv_denom;
	v = (dot(v0, v0) * dot(v1, v2) - dot(v0, v1) * dot(v0, v2)) / inv_denom;

	if (u >= 0 && v >= 0 && (u + v) < 1 && fabs(v0.x * u + v1.x * v - v2.x) < 1 &&
		fabs(v0.y * u + v1.y * v - v2.y) < 1 && fabs(v0.z * u + v1.z * v - v2.z) < 1)
		return (1);
	return (0);
}

int		contact(variable_list* l, int ts, xyz_list p)
{
	xyz_list v0;
	xyz_list v1;
	xyz_list v2;

	v0.x = l->t.x2[ts] - l->t.x1[ts];
	v0.y = l->t.y2[ts] - l->t.y1[ts];
	v0.z = l->t.z2[ts] - l->t.z1[ts];
	v1.x = l->t.x3[ts] - l->t.x1[ts];
	v1.y = l->t.y3[ts] - l->t.y1[ts];
	v1.z = l->t.z3[ts] - l->t.z1[ts];
	v2.x = p.x - l->t.x1[ts];
	v2.y = p.y - l->t.y1[ts];
	v2.z = p.z - l->t.z1[ts];

	return (point_in_triangle(v0, v1, v2));
}

int     check_all_triangles(variable_list* l, xyz_list p)
{
	int tn;
	int ts;

	tn = l->triangle_number;
	ts = -1;
	while (++ts < tn)
	{
		if (contact(l, ts, p))
		{
			//printf("contact\n");
			if (l->g.npc[l->t.group[ts]] == 1)
				return (l->t.group[ts]);
			return (-1);
		}
	}
	return (-2);
}

xyz_list	ft_bullet_step(variable_list* l, int p_flag, xyz_list p)
{
	if (p_flag < 0)
	{
		p.y += l->e.s_v;
		p.x -= l->e.s_h * l->e.c_v;
		p.z += l->e.c_h * l->e.c_v;
	}
	else
	{
		p.x += (l->l_npc[p_flag].x - l->p.x) / (RANGE_NPC - 2);
		p.y += (l->l_npc[p_flag].y - l->p.y) / (RANGE_NPC - 2);
		p.z += (l->l_npc[p_flag].z - l->p.z) / (RANGE_NPC - 2);
	}
	return (p);
}

int		ft_bullet(variable_list* l, int p_flag, int range)
{
	int		i;
	xyz_list	p;
	int		ret;

	p.x = l->p.x;
	p.y = l->p.y;
	p.z = l->p.z;
	i = -1;
	while (i++ < range)
	{
		p = ft_bullet_step(l, p_flag, p);
		ret = check_all_triangles(l, p);
		if (ret > -2)
			return (npc_id(l, ret));
	}
	return (-1);
}
