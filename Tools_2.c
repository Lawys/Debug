#include "header.h"

void		ft_atoi_while_p2(variable_list* l, char* str, int* i, double* result_decimal)
{
	double	c;

	(*i) += 2;
	c = 10;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result_decimal += ((double)str[*i] - 48.) / c;
		c *= 10;
		(*i)++;
	}
}

double ft_atoi_while(variable_list* l, char* str, int* i)
{
	double	result;
	double	result_decimal;
	double	n;

	result = 0;
	result_decimal = 0;
	if (ft_atoi_while_init(l, str, i, &n) == 0)
		return(0);
	if (str[*i] >= '1' && str[*i] <= '9')
	{
		ft_atoi_while_p1(l, str, i, &result, &result_decimal);
		result = result * n;
	}
	else if (str[*i] == '0' && str[*i + 1] == '.')
	{
		ft_atoi_while_p2(l, str, i, &result_decimal);
		result = result_decimal * n;
	}
	else
		(*i)++;
	return (result);
}

double ft_atoi(variable_list* l, char* str, int* i)
{
	double result;
	int inc;

	if (i != NULL)
		inc = *i;
	else
		inc = 0;
	result = 0;
	while (str[inc] != '\0' && (str[inc] < '0' || str[inc] > '9') && str[inc] != '-')
		inc++;
	result = ft_atoi_while(l, str, &inc);
	if (i != NULL)
		*i = inc;
	return(result);
}

void		ft_itoa_naturals(variable_list* l, double number, char* str, int* i)
{
	int result;
	int c;

	result = (int)number;
	c = 1;
	while (result > 9)
	{
		result /= 10;
		c *= 10;
	}
	result = (int)number;
	while (c > 0)
	{
		str[(*i)++] = (result / c) + 48;
		result -= (result / c) * c;
		c /= 10;
	}
}

void		ft_itoa_decimals(variable_list* l, double number, char* str, int* i)
{
	int d;
	int c;

	str[(*i)++] = '.';
	d = 0;
	c = 10;
	while (d++ < 2)
	{
		str[(*i)++] = (int)(number * c) % 10 + 48;
		c *= 10;
	}
	while (str[(*i) - 1] == '0')
		(*i)--;
	if (str[(*i) - 1] == '.')
		(*i)--;
}
