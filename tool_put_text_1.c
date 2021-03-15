/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_put_text_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:32:32 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_put_text_texture_initialize(
t_variable_list *l, t_utility_list *tmp)
{
	int	i;

	tmp->size = (l->u.size / 2);
	tmp->wsx = (double)WDWF * (l->u.wsx / 100);
	tmp->wsy = (double)WDHF * (l->u.wsy / 100);
	tmp->wex = tmp->wsx;
	tmp->wey = tmp->wsy + 34. * tmp->size * ((double)WDHF / 1024);
	tmp->action = l->u.action;
	tmp->colors = l->u.colors;
	if (l->action != -1 && l->action_select[l->menu_select][tmp->action])
		tmp->colors = l->u.colors_on;
	i = -1;
	while (l->u.str_address[++i])
	{
		if (l->u.str_address[i] == 'I' || l->u.str_address[i] == '.')
			tmp->wex += 12. * tmp->size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == '1' || l->u.str_address[i] == ' ')
			tmp->wex += 18. * tmp->size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == 'J')
			tmp->wex += 24. * tmp->size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == 'L')
			tmp->wex += 30. * tmp->size * ((double)WDWF / 1024);
		else
			tmp->wex += 34. * tmp->size * ((double)WDWF / 1024);
	}
}

void		ft_put_text_texture_while(t_variable_list *l, t_utility_list *tmp,
int x, int y)
{
	int	value;
	int	xf;
	int	yf;

	value = (((int)(1024 - y / (tmp->size * ((double)WDHF / 1024)) +
	tmp->tsy) % 1024) * 1024 + ((int)(x / (tmp->size * ((double)WDWF / 1024)) +
	tmp->tsx) % 1024)) * 4;
	if (tmp->colors[value + 3] != 0)
	{
		value = tmp->colors[value] +
		tmp->colors[value + 1] * 256 +
		tmp->colors[value + 2] * 65536;
		yf = (int)(tmp->wsy + y);
		xf = (int)(tmp->wsx + x);
		if (xf >= 0 && xf < WDWF &&
			yf >= 0 && yf < WDHF)
		{
			l->pixels_distance[xf / 2][yf / 2] = 0;
			l->pixels[yf * WDWF + xf] = value;
		}
	}
}

void		ft_put_text_texture_action(t_variable_list *l, t_utility_list *tmp)
{
	int	i;

	if (tmp->action != -1 && l->i.mouse_x > tmp->wsx && l->i.mouse_x < tmp->wex
	&& l->i.mouse_y > tmp->wsy && l->i.mouse_y < tmp->wey)
	{
		tmp->colors = l->u.colors_on;
		if (l->i.mouse == 1 && l->i.mouse_time_pressing == 1)
		{
			if (l->action_select[l->menu_select][tmp->action] == 0)
			{
				if (l->menu_select != 0 || tmp->action != 8)
				{
					i = 0;
					while (++i < 200)
						l->action_select[l->menu_select][i] = 0;
				}
				l->action_select[l->menu_select][tmp->action] = 1;
				if (l->action_select[0][7])
					l->triangle_select = -1;
			}
			else
				l->action_select[l->menu_select][tmp->action] = 0;
		}
	}
}

void		ft_put_text_texture(t_variable_list *l, t_utility_list *tmp)
{
	int	x;
	int	y;
	int	endy;
	int	endx;

	endy = (int)(34. * tmp->size * ((double)WDHF / 1024));
	endx = (int)(34. * tmp->size * ((double)WDWF / 1024));
	y = -1;
	while (++y < endy)
	{
		x = -1;
		while (++x < endx)
			ft_put_text_texture_while(l, tmp, x, y);
	}
}

void		ft_put_text(t_variable_list *l)
{
	int				i;
	t_utility_list	tmp;

	ft_put_text_texture_initialize(l, &tmp);
	ft_put_text_texture_action(l, &tmp);
	i = -1;
	while (l->u.str_address[++i])
	{
		tmp.tsx = (int)((double)l->u.str_address[i] / 23) * 37;
		tmp.tsy = -((l->u.str_address[i] % 23) * 36 - 1024);
		ft_put_text_texture(l, &tmp);
		if (l->u.str_address[i] == 'I' || l->u.str_address[i] == '.')
			tmp.wsx += 12. * tmp.size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == '1' || l->u.str_address[i] == ' ')
			tmp.wsx += 18. * tmp.size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == 'J')
			tmp.wsx += 24. * tmp.size * ((double)WDWF / 1024);
		else if (l->u.str_address[i] == 'L')
			tmp.wsx += 30. * tmp.size * ((double)WDWF / 1024);
		else
			tmp.wsx += 34. * tmp.size * ((double)WDWF / 1024);
	}
	l->u.wsx = (tmp.wsx * 100) / WDWF;
}
