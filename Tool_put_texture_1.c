#include "header.h"

void		ft_put_texture_initialize(variable_list* l, utility_list* tmp)
{
	tmp->action = l->u.action;
	tmp->wsx = (double)WDWF * (l->u.wsx / 100);
	tmp->wsy = (double)WDHF * (l->u.wsy / 100);
	tmp->sizey = l->u.sizey * l->u.size;
	tmp->sizex = l->u.sizex * l->u.size;
	tmp->tsy = (int)(l->u.tsy * tmp->sizey);
	tmp->tsx = (int)(l->u.tsx * tmp->sizex);
	tmp->tey = l->u.tey;
	tmp->tex = l->u.tex;
}

void		ft_put_texture_while(variable_list* l, utility_list* tmp, int x, int y)
{
	int value;
	int xf;
	int yf;

	value = (((int)(1023 - y / tmp->sizey) % 1024) * 1024 +
		((int)(x / tmp->sizex) % 1024)) * 4;
	if (tmp->colors[value + 3] != 0)
	{
		value = tmp->colors[value] +
		tmp->colors[value + 1] * 256 +
		tmp->colors[value + 2] * 65536;
		yf = (int)(tmp->wsy + y - tmp->tsy);
		xf = (int)(tmp->wsx + x - tmp->tsx);
		if (xf >= 0 && xf < WDWF &&
			yf >= 0 && yf < WDHF)
		{
			l->pixels_triangle[xf / 2][yf / 2] = -1;
			l->pixels[yf * WDWF + xf] = value;
		}
	}
}

void		ft_put_texture_action(variable_list* l, utility_list* tmp)
{
	int i;

	if (tmp->action != -1 &&
		l->i.mouse_x > tmp->wsx &&
		l->i.mouse_x < tmp->wsx + tmp->tex * tmp->sizex - tmp->tsx &&
		l->i.mouse_y > tmp->wsy &&
		l->i.mouse_y < tmp->wsy + tmp->tey * tmp->sizey - tmp->tsy)
	{
		tmp->colors = l->u.colors_on;
		if (l->i.mouse == 1 && l->i.mouse_time_pressing == 1)
		{
			if (l->action_select[l->menu_select][tmp->action] == 0)
			{
				i = 0;
				while (++i < 200)
					l->action_select[l->menu_select][i] = 0;
				l->action_select[l->menu_select][tmp->action] = 1;
			}
			else
				l->action_select[l->menu_select][tmp->action] = 0;
		}
	}
	else
		tmp->colors = l->u.colors;
}

void		ft_put_texture(variable_list* l)
{
	int x;
	int y;
	int endy;
	int endx;
	utility_list tmp;

	ft_put_texture_initialize(l, &tmp);
	endy = (int)(tmp.tey * tmp.sizey);
	endx = (int)(tmp.tex * tmp.sizex);
	ft_put_texture_action(l, &tmp);
	y = tmp.tsy - 1;
	while (++y < endy)
	{
		x = tmp.tsx - 1;
		while (++x < endx)
			ft_put_texture_while(l, &tmp, x, y);
	}
}
