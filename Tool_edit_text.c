#include "header.h"

void	ft_text_editing(variable_list* l, char* str, int max)
{
	int i = 0;
	while (str[i] != 0)
		i++;

	if (l->i.key_input >= ' ' && l->i.key_input <= '}' && i < max)
	{
		str[i++] = l->i.key_input;
		str[i] = 0;
	}
	else if (l->i.state[42] && i > 0)
	{
		str[--i] = 0;
		l->i.state[42] = 0;
	}
	l->writing_mode = 1;
}
