/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_edit_int_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:32:07 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/22 10:12:40 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_value_editing_int_wheel_up(variable_list *l, int *value,
int max)
{
	*value += (int)l->me.mult;
	if (*value > max)
		*value = max;
}

void		ft_value_editing_int_wheel_down(variable_list *l, int *value,
int min)
{
	*value -= (int)l->me.mult;
	if (*value < min)
		*value = min;
}

void		ft_value_editing_int_set_number(variable_list *l, int *value,
int *limits, int i)
{
	int result;

	l->u.str[i + 1] = 0;
	l->u.str[i] = l->i.key_input;
	result = (int)ft_atoi(l->u.str, NULL);
	if (result >= limits[0] && result <= limits[1])
		*value = result;
	else if (result > limits[1])
		*value = limits[1];
	else if (result < limits[0])
		*value = limits[0];
}

void		ft_value_editing_int_remove_number(variable_list *l, int *value,
int *limits, int i)
{
	*value /= 10;
	if (*value > limits[1])
		*value = limits[1];
	else if (*value < limits[0])
		*value = limits[0];
	l->i.state[42] = 0;
}

void		ft_value_editing_int_set_negativ(variable_list *l, int *value,
int *limits)
{
	*value *= -1;
	if (*value > limits[1])
		*value = limits[1];
	else if (*value < limits[0])
		*value = limits[0];
}
