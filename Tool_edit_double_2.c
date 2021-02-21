#include "header.h"

void		ft_value_editing_double(variable_list *l, double *value, int min, int max)
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
