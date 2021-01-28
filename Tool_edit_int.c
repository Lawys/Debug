#include "header.h"


void	ft_value_editing_int_wheel_up(variable_list* l, int* value, int max)
{
	*value += l->me.mult;
	if (*value > max)
		*value = max;
}

void	ft_value_editing_int_wheel_down(variable_list* l, int* value, int min)
{
	*value -= l->me.mult;
	if (*value < min)
		*value = min;
}

void	ft_value_editing_int_set_number(variable_list* l, int* value, int min, int max, int i)
{
	int result;

	l->u.str[i + 1] = 0;
	l->u.str[i] = l->i.key_input;
	result = ft_atoi(l, l->u.str, NULL);
	if (result >= min && result <= max)
		*value = result;
	else if (result > max)
		*value = max;
	else if (result < min)
		*value = min;
}

void	ft_value_editing_int_remove_number(variable_list* l, int* value, int min, int max, int i)
{
	*value /= 10;
	if (*value > max)
		*value = max;
	else if (*value < min)
		*value = min;
	l->i.state[42] = 0;
}

void	ft_value_editing_int_set_negativ(variable_list* l, int* value, int min, int max, int i)
{
	*value *= -1;
	if (*value > max)
		*value = max;
	else if (*value < min)
		*value = min;
}

void	ft_value_editing_int(variable_list* l, int* value, int min, int max)
{
	int i;

	l->me.mult /= 100;
	ft_itoa(l, *value, l->u.str);
	i = 0;
	if (l->u.str[0] != '0')
		while (l->u.str[i] != 0)
			i++;
	if (l->i.scroll_up)
		ft_value_editing_int_wheel_up(l, value, max);
	else if (l->i.scroll_down)
		ft_value_editing_int_wheel_down(l, value, min);
	else if (l->i.key_input >= '0' && l->i.key_input <= '9')
		ft_value_editing_int_set_number(l, value, min, max, i);
	else if (l->i.state[42] && i > 0)
		ft_value_editing_int_remove_number(l, value, min, max, i);
	else if (l->i.key_input == '-')
		ft_value_editing_int_set_negativ(l, value, min, max, i);
}

