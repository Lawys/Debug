#include "header.h"
/*
void	ft_map_editor_paint_size(variable_list* l)
{
	if (l->i.state[58])
	{
		if (l->me.size < 50)
			l->me.size += 10;
		l->i.state[58] = 0;
	}
	else if (l->i.state[59])
	{
		if (l->me.size > 10)
			l->me.size -= 10;
		l->i.state[59] = 0;
	}
}
void	ft_map_editor_paint_pixels_initialize(variable_list* l)
{
	int i;

	i = -1;
	while (++i < MAX_TRIANGLES)
		l->t.list[i] = -1;
	l->me.nowx = l->i.mouse_x / 2 - 10;
	l->me.endx = l->i.mouse_x / 2 + 10;
	l->me.nowy = l->i.mouse_y / 2 - 10;
	l->me.endy = l->i.mouse_y / 2 + 10;
	if (l->me.nowy < 0)
		l->me.nowy = 0;
	if (l->me.endy > WDH * 2 - 1)
		l->me.endy = WDH * 2 - 1;
	if (l->me.nowx < 0)
		l->me.nowx = 0;
	if (l->me.endx > WDW * 2 - 1)
		l->me.endx = WDW * 2 - 1;
}
void	ft_map_editor_paint_group_triangle_list(variable_list* l)
{
	int tmpx;
	int i;
	int ts;

	while (l->me.nowy < l->me.endy)
	{
		tmpx = l->me.nowx;
		while (tmpx < l->me.endx)
		{
			l->pixels[l->me.nowy * WDW * 2 + tmpx] += 256 * 32;
			if (l->i.mouse == 1 && l->i.mouse_time_pressing > 5)
			{
				ts = l->pixels_triangle[tmpx / 2][l->me.nowy / 2];
				if (l->t.group[ts] == l->group_select)
				{
					i = -1;
					while (l->t.list[++i] != -1)
						if (l->t.list[i] == ts)
							break;
					if (l->t.list[i] == -1)
						l->t.list[i] = ts;
				}
			}
			tmpx++;
		}
		l->me.nowy++;
	}
}
void	ft_map_editor_paint_area_triangle_list(variable_list* l)
{
	int tmpx;
	int i;
	int ts;

	while (l->me.nowy < l->me.endy)
	{
		tmpx = l->me.nowx;
		while (tmpx < l->me.endx)
		{
			l->pixels[l->me.nowy * WDW * 2 + tmpx] += 256 * 32;
			if (l->i.mouse == 1 && l->i.mouse_time_pressing > 5)
			{
				ts = l->pixels_triangle[tmpx / 2][l->me.nowy / 2];
				if (l->t.area[ts] == l->area_select)
				{
					i = -1;
					while (l->t.list[++i] != -1)
						if (l->t.list[i] == ts)
							break;
					if (l->t.list[i] == -1)
						l->t.list[i] = ts;
				}
			}
			tmpx++;
		}
		l->me.nowy++;
	}
}
void	ft_map_editor_paint_selected_texture(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[(int)l->paint_texture_select];
	l->u.tsx = 0;
	l->u.tex = 256;
	l->u.tsy = 0;
	l->u.tey = 256;
	l->u.sizex = (double)WDW / 8192;
	l->u.sizey = (double)WDH / (8192 * ((double)WDH / WDW));
	l->u.size = 1;
	l->u.wsx = 80;
	l->u.wsy = 75;
	ft_put_texture(l);
}*/