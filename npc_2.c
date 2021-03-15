/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:53 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_npc_hp_positive_while(
t_variable_list *l, t_npc_list *tmp, int group)
{
	int	ts;

	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->g.no_block[l->t.group[ts]] == 0 &&
			l->g.npc[l->t.group[ts]] == 0 &&
			l->g.sprite[l->t.group[ts]] == 0 &&
			l->g.exist[l->t.group[ts]] == 1)
		{
			ft_npc_line_triangle_initialize(l, tmp, ts);
			ft_npc_line_triangle_t(l, tmp);
			ft_npc_line_triangle_u(l, tmp);
			ft_npc_line_triangle_v(l, tmp);
			if (tmp->t >= 0 && tmp->t < 1 && tmp->u >= 0 && tmp->u <= 1 &&
				tmp->v >= 0 && tmp->v <= 1 && tmp->u + tmp->v <= 1)
			{
				l->g.npc_hp[group] = l->npc_base_life;
				l->g.npc_statement[group] = 0;
				return (1);
			}
		}
	}
	return (0);
}

void		ft_npc_hp_positive(t_variable_list *l, t_npc_list *tmp, int group)
{
	ft_npc_hp_positive_init(l, tmp, group);
	if (ft_npc_hp_positive_while(l, tmp, group) == 1)
		return ;
	l->g.npc_o[group] = (int)(atan2(tmp->vx, tmp->vz) * 180 / M_PI + 180);
	if (l->g.npc_timer[group] % 10 == 0)
	{
		l->p.hp -= l->npc_base_damage;
		l->g.npc_statement[group] = 2;
	}
	else if ((l->g.npc_timer[group] - 2) % 10 == 0)
		l->g.npc_statement[group] = 1;
	l->g.npc_timer[group]++;
}

void		ft_npc_hp_negative(t_variable_list *l, int group)
{
	if (l->g.npc_hp[group] == -10)
	{
		l->g.npc_statement[group] = 5;
		l->g.npc_hp[group] = -1;
		l->g.npc_timer[group] = 0;
		l->g.npc_o[group] = 0;
	}
	else if (l->g.npc_hp[group] == 0)
	{
		l->g.npc_statement[group] = 4;
		l->g.npc_timer[group] = 0;
		l->g.npc_o[group] = 0;
		l->g.npc_hp[group] = -1;
	}
	else if (l->g.npc_hp[group] < 0 && ++l->g.npc_timer[group] % 5 == 0)
	{
		l->g.npc_o[group] = -l->g.npc_hp[group];
		l->g.npc_hp[group]--;
		if (l->g.npc_hp[group] == -8)
			l->g.exist[group] = 0;
	}
}

void		ft_npc(t_variable_list *l)
{
	t_npc_list	tmp;
	int			group;
	int			i;

	group = -1;
	while (++group < MAX_GROUPS)
		if (l->g.npc[group] == 1 && l->g.exist[group] == 1)
		{
			if (l->g.npc_hp[group] <= 0)
				ft_npc_hp_negative(l, group);
			else if (l->g.npc_hp[group] > 0)
			{
				if (l->g.npc_timer[group] < 0)
					l->g.npc_timer[group]++;
				else
					ft_npc_hp_positive(l, &tmp, group);
			}
		}
}
