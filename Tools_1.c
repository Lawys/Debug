#include "header.h"

void		ft_free_and_exit(variable_list *l, const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		continue;
	_write(1, str, i * sizeof(char));
	SDL_FreeSurface(l->window_surface);
	SDL_DestroyWindow(l->window);
	SDL_Quit();
	free(l);
	printf("%d\n", _CrtDumpMemoryLeaks());
	SDL_Delay(500);
	exit(0);
}

void		ft_get_time_editor(variable_list *l)
{
	l->u.wsx = 2;
	ft_itoa(l, l->p.x, l->u.str_address);
	ft_put_text(l);
	l->u.wsx = l->u.wsx + 20;
	ft_itoa(l, l->p.y, l->u.str_address);
	ft_put_text(l);
	l->u.wsx = l->u.wsx + 20;
	ft_itoa(l, l->p.z, l->u.str_address);
	ft_put_text(l);
	l->u.wsx = l->u.wsx + 20;
}

void		ft_get_time(variable_list *l)
{
	static double moyenne = 0;
	static double cd = 0;

	while (1)
	{
		l->u.time = clock();
		l->u.frametime = (l->u.time - l->u.old_time) / (CLOCKS_PER_SEC);
		if ((1 / l->u.frametime) <= 300)
			break;
	}
	l->u.old_time = l->u.time;
	l->u.action = -1;
	l->u.size = 1;
	l->u.colors = l->texture_colors[10];
	l->u.wsy = 2;
	l->u.str_address = l->u.str;
	if (l->menu_mode == 2)
		ft_get_time_editor(l);
	ft_itoa(l, (double)((int)(1 / l->u.frametime)), l->u.str_address);
	l->u.wsx = 95.5;
	ft_put_text(l);
	l->u.old_time = l->u.time;
	l->cooldown++;
}

double ft_atoi_while_init(variable_list *l, char *str, int *i, double*n)
{
	*n = 1;
	if (str[*i] == '\0')
		return (0);
	if (str[*i] == '-')
	{
		*n *= -1;
		(*i)++;
		if (str[*i] == '\0')
			return (0);
	}
	while (str[*i] == '0' && str[*i + 1] == '0')
		(*i)++;
	return(1);
}

void		ft_atoi_while_p1(variable_list *l, char *str, int *i, double *result, double *result_decimal)
{
	double c;

	c = 10;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result *= c;
		*result += (double)str[*i] - 48.;
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		c = 10;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*result_decimal += ((double)str[*i] - 48.) / c;
			c *= 10;
			(*i)++;
		}
		*result += *result_decimal;
	}
}
