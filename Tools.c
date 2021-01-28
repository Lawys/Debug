#include "header.h"

void	ft_free_and_exit(variable_list* l)
{
	printf("%d\n", _CrtDumpMemoryLeaks());
	SDL_FreeSurface(l->window_surface);
	SDL_DestroyWindow(l->window);
	SDL_Quit();
	free(l);
	printf("%d\n", _CrtDumpMemoryLeaks());
	SDL_Delay(500);
	exit(0);
}

void    ft_get_time(variable_list* l)
{
	static double moyenne = 0, cd = 0;
	static double time, frametime, old_time;
	unsigned char str[15];

	while (1)
	{
		time = clock();
		frametime = (time - old_time) / (CLOCKS_PER_SEC);
		if ((1 / frametime) <= 999)
			break;
	}
	old_time = time;
	//if (l->cooldown > 250)cd++, moyenne += (1. / frametime), printf("%f\n", moyenne / cd);
		l->u.wsx = 2;
		l->u.wsy = 2;
		l->u.action = -1;
		l->u.size = 1;
		l->u.colors = l->texture_colors[10];
		l->u.wsx = 2;
		l->u.str_address = str;
		ft_itoa(l, l->p.x, l->u.str_address);
		ft_put_text(l);
		l->u.wsx = l->u.wsx + 20;
		ft_itoa(l, l->p.y, l->u.str_address);
		ft_put_text(l);
		l->u.wsx = l->u.wsx + 20;
		ft_itoa(l, l->p.z, l->u.str_address);
		ft_put_text(l);
		l->u.wsx = l->u.wsx + 20;
		ft_itoa(l, (double)((int)(1 / frametime)), l->u.str_address);
		l->u.wsx = 96;
		ft_put_text(l);
		old_time = time;
	
	l->cooldown++;
}

void	ft_bmp_reader(variable_list* l, char* image_name)
{
	int fd = 0;
	int error;

	_sopen_s(&fd, image_name, 0, _SH_DENYWR, 0);
	error = _read(fd, l->texture_colors[l->texture_number++], 1024 * 1024 * 4 + 138);
	_close(fd);

}

void	ft_set_array_values(variable_list* l, void** array, int value, unsigned int length)
{
	int i;
	i = -1;
	while (++i < length)
		array[i] = value;
}

double		ft_atoi_while(variable_list* l, char* str, int* i)
{
	double	c;
	double	result;
	double	result_decimal;
	double	n;

	result = 0;
	result_decimal = 0;
	n = 1;
	if (str[*i] == '\0')
		return (0);
	if (str[*i] == '-')
	{
		n *= -1;
		(*i)++;
		if (str[*i] == '\0')
			return (0);
	}
	while (str[*i] == '0' && str[*i + 1] == '0')
		(*i)++;
	if (str[*i] >= '1' && str[*i] <= '9')
	{
		c = 10;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result *= c;
			result += (double)str[*i] - 48.;
			(*i)++;
		}
		if (str[*i] == '.')
		{
			(*i)++;
			c = 10;
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				result_decimal += ((double)str[*i] - 48.) / c;
				c *= 10;
				(*i)++;
			}
			result += result_decimal;
		}
		result = result * n;
	}
	else if (str[*i] == '0' && str[*i + 1] == '.')
	{
		(*i) += 2;
		c = 10;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result_decimal += ((double)str[*i] - 48.) / c;
			c *= 10;
			(*i)++;
		}
		result = result_decimal * n;
	}
	else
		(*i)++;
	return (result);
}

double		ft_atoi(variable_list* l, char* str, int* i)
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

int	ft_itoa(variable_list* l, double number, char* str)
{
	int		i;
	int		result;
	int		d;
	int		c;

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
		str[i++] = (result / c) + 48;
		result -= (result / c) * c;
		c /= 10;
	}
	if (number - (int)number > 0)
	{
		str[i++] = '.';
		d = 0;
		c = 10;
		while (d++ < 2)
		{
			str[i++] = (int)(number * c) % 10 + 48;
			c *= 10;
		}
		while (str[i - 1] == '0')
			i--;
		if (str[i - 1] == '.')
			i--;
	}
	str[i] = 0;
	return(i);
}


void ft_swap_nbr(int* k, double* t, int i, int j)
{
	int c;

	c = t[i];
	t[i] = t[j];
	t[j] = c;
	c = k[i];
	k[i] = k[j];
	k[j] = c;
}
void ft_quick_sort(int *k, double* t, int size)
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


