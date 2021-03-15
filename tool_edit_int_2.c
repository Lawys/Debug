/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_edit_int_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:32:23 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_value_editing_int(t_variable_list *l, int *value, int min,
int max)
{
	int	i;
	int limits[2];

	limits[0] = min;
	limits[1] = max;
	l->me.mult /= 100;
	ft_itoa(*value, l->u.str);
	i = 0;
	if (l->u.str[0] != '0')
		while (l->u.str[i] != 0)
			i++;
	if (l->i.scroll_up)
		ft_value_editing_int_wheel_up(l, value, max);
	else if (l->i.scroll_down)
		ft_value_editing_int_wheel_down(l, value, min);
	else if (l->i.key_input >= '0' && l->i.key_input <= '9')
		ft_value_editing_int_set_number(l, value, limits, i);
	else if (l->i.state[42] && i > 0)
		ft_value_editing_int_remove_number(l, value, limits);
	else if (l->i.key_input == '-')
		ft_value_editing_int_set_negativ(value, limits);
}
