#include "header.h"

void	ft_value_editing_double_wheel_up(variable_list* l, double* value, int max)
{
	*value += l->me.mult;
	if (*value > max)
		*value = max;
}

void	ft_value_editing_double_wheel_down(variable_list* l, double* value, int min)
{
	*value -= l->me.mult;
	if (*value < min)
		*value = min;
}

void	ft_value_editing_double_set_number(variable_list* l, double* value, int min, int max, int i)
{
	int result;

	if (*value != 0)
	{
		l->u.str[i + 1] = 0;
		l->u.str[i] = l->u.str[i - 1];
		l->u.str[i - 1] = l->u.str[i - 2];
		l->u.str[i - 2] = l->i.key_input;
		result = ft_atoi(l, l->u.str, NULL);
	}
	else
	{
		l->u.str[i + 1] = 0;
		l->u.str[i] = l->i.key_input;
		result = ft_atoi(l, l->u.str, NULL) * 100;
	}
	if (result >= min && result <= max)
		*value = result;
	else if (result > max)
		*value = max;
	else if (result < min)
		*value = min;
}

void	ft_value_editing_double_remove_number(variable_list* l, double* value, int min, int max, int i)
{
	int result;

	if (l->u.str[i - 1] != '0')
	{
		l->u.str[i - 1] = '0';
		result = ft_atoi(l, l->u.str, NULL);
	}
	else if (l->u.str[i - 2] != '0')
	{
		l->u.str[i - 2] = '0';
		result = ft_atoi(l, l->u.str, NULL);
	}
	else
	{
		l->u.str[i - 3] = '0';
		result = ft_atoi(l, l->u.str, NULL) / 10;
	}
	if (result >= min && result <= max)
		*value = result;
	else if (result > max)
		*value = max;
	else if (result < min)
		*value = min;
	l->i.state[42] = 0;
}

void	ft_value_editing_double_set_negativ(variable_list* l, double* value, int min, int max, int i)
{
	*value *= -1;
	if (*value > max)
		*value = max;
	else if (*value < min)
		*value = min;
}

void	ft_value_editing_double(variable_list* l, double* value, int min, int max)
{
	int i;

	*value = (int)(*value * 100.000001);
	min *= 100;
	max *= 100;
	ft_itoa(l, *value, l->u.str);
	i = 0;
	if (l->u.str[0] != '0')
		while (l->u.str[i] != 0)
			i++;
	if (l->i.scroll_up)
		ft_value_editing_double_wheel_up(l, value, max);
	else if (l->i.scroll_down)
		ft_value_editing_double_wheel_down(l, value, min);
	else if (l->i.key_input >= '0' && l->i.key_input <= '9')
		ft_value_editing_double_set_number(l, value, min, max, i);
	else if (l->i.state[42] && i > 0)
		ft_value_editing_double_remove_number(l, value, min, max, i);
	else if (l->i.key_input == '-')
		ft_value_editing_double_set_negativ(l, value, min, max, i);
	*value = (int)*value / 100.;
}
