/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:03 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_action_on(t_variable_list *l, int group, int c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		l->g.action_statement[value] = 2;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_off(t_variable_list *l, int group, int c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		l->g.action_statement[value] = 3;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_area_end(t_variable_list *l)
{
	if (l->p.item[5] == 2)
		l->menu_mode = 4;
}

void		ft_action_area_loot(t_variable_list *l, int group, int c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == ';' && value >= 0 && value < 9)
	{
		l->p.item[value] = 1;
		l->g.exist[group] = 0;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_area_heal(t_variable_list *l, int group, int c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == ';')
	{
		l->p.hp += value;
		if (l->p.hp > 100)
			l->p.hp = 100;
		l->g.exist[group] = 0;
		ft_action_start(l, group, ++c, str);
	}
}
