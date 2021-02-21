#include "header.h"

void		ft_value_editing_int_wheel_up(variable_list *l, int *value, int max)
{
	*value += (int)l->me.mult;
	if (*value > max)
		*value = max;
}

void		ft_value_editing_int_wheel_down(variable_list *l, int *value, int min)
{
	*value -= (int)l->me.mult;
	if (*value < min)
		*value = min;
}

void		ft_value_editing_int_set_number(variable_list *l, int *value, int min, int max, int i)
{
	int result;

	l->u.str[i + 1] = 0;
	l->u.str[i] = l->i.key_input;
	result = (int)ft_atoi(l, l->u.str, NULL);
	if (result >= min && result <= max)
		*value = result;
	else if (result > max)
		*value = max;
	else if (result < min)
		*value = min;
}

void		ft_value_editing_int_remove_number(variable_list *l, int *value, int min, int max, int i)
{
	*value /= 10;
	if (*value > max)
		*value = max;
	else if (*value < min)
		*value = min;
	l->i.state[42] = 0;
}

void		ft_value_editing_int_set_negativ(variable_list *l, int *value, int min, int max, int i)
{
	*value *= -1;
	if (*value > max)
		*value = max;
	else if (*value < min)
		*value = min;
}
