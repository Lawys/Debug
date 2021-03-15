/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_edit_double_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:32:03 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_value_editing_double(t_variable_list *l, double *value, int min,
int max)
{
	int	i;
	int limits[2];

	limits[0] = min * 100;
	limits[1] = max * 100;
	*value = (int)(*value * 100.000001);
	min *= 100;
	max *= 100;
	ft_itoa(*value, l->u.str);
	i = 0;
	if (l->u.str[0] != '0')
		while (l->u.str[i] != 0)
			i++;
	if (l->i.scroll_up)
		ft_value_editing_double_wheel_up(l, value, max);
	else if (l->i.scroll_down)
		ft_value_editing_double_wheel_down(l, value, min);
	else if (l->i.key_input >= '0' && l->i.key_input <= '9')
		ft_value_editing_double_set_number(l, value, limits, i);
	else if (l->i.state[42] && i > 0)
		ft_value_editing_double_remove_number(l, value, limits, i);
	else if (l->i.key_input == '-')
		ft_value_editing_double_set_negativ(value, limits);
	*value = (int)*value / 100.;
}
