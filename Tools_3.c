#include "header.h"

int	ft_itoa(variable_list* l, double number, char* str)
{
	int		i;

	i = 0;
	if (number < 0)
	{
		str[i++] = '-';
		number = -number;
	}
	else if (number == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return(i);
	}
	ft_itoa_naturals(l, number, str, &i);
	if (number - (int)number > 0)
		ft_itoa_decimals(l, number, str, &i);
	str[i] = 0;
	return(i);
}

int	ft_strings_compare(char* line, char* word, int c)
{
	int i;

	i = -1;
	while (word[++i] != '\0')
		if (word[i] != line[c + i])
			return (0);
	return (1);
}

void		ft_swap_nbr(int* k, double* t, int i, int j)
{
	double d;
	int c;

	d = t[i];
	t[i] = t[j];
	t[j] = d;
	c = k[i];
	k[i] = k[j];
	k[j] = c;
}

void		ft_quick_sort(int* k, double* t, int size)
{
	double p;
	int i;
	int j;
	if (t == NULL || size <= 1)
		return;
	p = t[size - 1];
	j = -1;
	i = 0;
	while (++j < size - 1)
	{
		if (t[j] < p)
		{
			if (i != j)
				ft_swap_nbr(k, t, i, j);
			i++;
		}
	}
	ft_swap_nbr(k, t, i, size - 1);
	ft_quick_sort(k, t, i);
	ft_quick_sort(k + i + 1, t + i + 1, size - i - 1);
}
