/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_edit_double_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:31:58 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_value_editing_double_wheel_up(
t_variable_list *l, double *value, int max)
{
	*value += l->me.mult;
	if (*value > max)
		*value = max;
}

void		ft_value_editing_double_wheel_down(
t_variable_list *l, double *value, int min)
{
	*value -= l->me.mult;
	if (*value < min)
		*value = min;
}

void		ft_value_editing_double_set_number(
t_variable_list *l, double *value, int *limits, int i)
{
	int	result;

	if (*value != 0)
	{
		l->u.str[i + 1] = 0;
		l->u.str[i] = l->u.str[i - 1];
		l->u.str[i - 1] = l->u.str[i - 2];
		l->u.str[i - 2] = l->i.key_input;
		result = (int)ft_atoi(l->u.str, NULL);
	}
	else
	{
		l->u.str[i + 1] = 0;
		l->u.str[i] = l->i.key_input;
		result = (int)ft_atoi(l->u.str, NULL) * 100;
	}
	printf("%d %d\n", limits[0], limits[1]);
	printf("%f\n", *value);
	if (result >= limits[0] && result <= limits[1])
		*value = result;
	else if (result > limits[1])
		*value = limits[1];
	else if (result < limits[0])
		*value = limits[0];
	printf("%f\n", *value);
}

void		ft_value_editing_double_remove_number(t_variable_list *l,
double *value, int *limits, int i)
{
	int	result;

	if (l->u.str[i - 1] != '0')
	{
		l->u.str[i - 1] = '0';
		result = (int)ft_atoi(l->u.str, NULL);
	}
	else if (l->u.str[i - 2] != '0')
	{
		l->u.str[i - 2] = '0';
		result = (int)ft_atoi(l->u.str, NULL);
	}
	else
	{
		l->u.str[i - 3] = '0';
		result = (int)ft_atoi(l->u.str, NULL) / 10;
	}
	if (result >= limits[0] && result <= limits[1])
		*value = result;
	else if (result > limits[1])
		*value = limits[1];
	else if (result < limits[0])
		*value = limits[0];
	l->i.state[42] = 0;
}

void		ft_value_editing_double_set_negativ(
double *value, int *limits)
{
	*value *= -1;
	if (*value > limits[1])
		*value = limits[1];
	else if (*value < limits[0])
		*value = limits[0];
}
