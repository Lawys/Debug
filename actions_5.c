/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:24:08 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_action_area(t_variable_list *l, int group, int c, char *str)
{
	double	distance;
	int		value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == '>')
	{
		ft_action_calculate_center(l, group);
		distance = sqrt((l->me.x - l->p.x) * (l->me.x - l->p.x) +
			(l->me.y - l->p.y) * (l->me.y - l->p.y) +
			(l->me.z - l->p.z) * (l->me.z - l->p.z));
		if ((value > 0 && distance <= value) ||
			(value < 0 && distance > value))
		{
			if (ft_strings_compare(str, "END;", ++c))
				ft_action_area_end(l);
			else if (ft_strings_compare(str, "LOOT>", c))
				ft_action_area_loot(l, group, c, str);
			else if (ft_strings_compare(str, "HEAL>", c))
				ft_action_area_heal(l, group, c, str);
		}
	}
}

void		ft_action_exist(t_variable_list *l, int group, int c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		if (l->g.exist[value] == 0)
			l->g.exist[value] = 1;
		else
			l->g.exist[value] = 0;
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_xyzhvls(t_variable_list *l, int group, int c, char *str)
{
	if (ft_strings_compare(str, "ON>", c))
		ft_action_on(l, group, c, str);
	else if (ft_strings_compare(str, "OFF>", c))
		ft_action_off(l, group, c, str);
	else if (ft_strings_compare(str, "X>", c))
		ft_action_x(l, group, c, str);
	else if (ft_strings_compare(str, "Y>", c))
		ft_action_y(l, group, c, str);
	else if (ft_strings_compare(str, "Z>", c))
		ft_action_z(l, group, c, str);
	else if (ft_strings_compare(str, "H>", c))
		ft_action_h(l, group, c, str);
	else if (ft_strings_compare(str, "V>", c))
		ft_action_v(l, group, c, str);
	else if (ft_strings_compare(str, "L>", c))
		ft_action_l(l, group, c, str);
	else if (ft_strings_compare(str, "SIZE>", c))
		ft_action_size(l, group, c, str);
	else if (ft_strings_compare(str, "TEXTURE>", c))
		ft_action_texture(l, group, c, str);
	else if (ft_strings_compare(str, "AREA>", c))
		ft_action_area(l, group, c, str);
	else if (ft_strings_compare(str, "EXIST>", c))
		ft_action_exist(l, group, c, str);
}

void		ft_action_start_action_timer_positive(t_variable_list *l, int group,
int c, char *str)
{
	int	value;

	if (c == 0)
	{
		while (str[c] != ';' && str[c] != '\0')
			c++;
		c++;
	}
	if (ft_strings_compare(str, "ONCE>", c))
	{
		value = (int)ft_atoi(str, &c);
		if (l->g.action_timer[group] == value && str[c] == '>')
			ft_action_xyzhvls(l, group, ++c, str);
	}
	else
	{
		ft_action_xyzhvls(l, group, c, str);
	}
}

void		ft_action_start_action_timer_negative_key(t_variable_list *l,
int group, int *c, char *str)
{
	int	value;

	value = (int)ft_atoi(str, c);
	if (l->p.item[value] != 2)
	{
		if (l->g.action_statement[group] == 2)
			l->g.action_statement[group] = 0;
		else if (l->g.action_statement[group] == 3)
			l->g.action_statement[group] = 1;
		return ;
	}
	else if (str[*c] == '>')
		(*c)++;
}
