#include "header.h"

int	ft_strings_count(char* word)
{
	int i;

	i = -1;
	while (word[++i] != '\0')
		continue;
	return(i);
}

int	ft_strings_compare(char* line, char* word, int c)
{
	int i;

	i = -1;
	while (word[++i] != '\0')
		if (word[i] != line[c + i])
			return (0);
	if (line[c + i] == '>' || line[c + i] == ';')
		return (1);
	return (0);
}

void ft_action_auto_x(variable_list* l, int group, int c)
{
	double value;
	int i;

	c += ft_strings_count("X") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.x1[i] += value;
				l->t.x2[i] += value;
				l->t.x3[i] += value;
			}
		}
		ft_action_auto_start(l, group, ++c);
	}
}
void ft_action_auto_y(variable_list* l, int group, int c)
{
	double value;
	int i;

	c += ft_strings_count("Y") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.y1[i] += value;
				l->t.y2[i] += value;
				l->t.y3[i] += value;
			}
		}
		ft_action_auto_start(l, group, ++c);
	}
}
void ft_action_auto_z(variable_list* l, int group, int c)
{
	double value;
	int i;

	c += ft_strings_count("Z") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		i = -1;
		while (++i < l->triangle_number)
		{
			if (l->t.group[i] == group)
			{
				l->t.z1[i] += value;
				l->t.z2[i] += value;
				l->t.z3[i] += value;
			}
		}
		ft_action_auto_start(l, group, ++c);
	}
}

void ft_action_auto_calculate_center(variable_list* l, int group)
{
	int i;
	int s;

	l->me.x = 0;
	l->me.y = 0;
	l->me.z = 0;
	s = 0;
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			s++;
			l->me.x += (l->t.x1[i] + l->t.x2[i] + l->t.x3[i]) / 3;
			l->me.y += (l->t.y1[i] + l->t.y2[i] + l->t.y3[i]) / 3;
			l->me.z += (l->t.z1[i] + l->t.z2[i] + l->t.z3[i]) / 3;
		}
	l->me.x = l->me.x / s;
	l->me.y = l->me.y / s;
	l->me.z = l->me.z / s;
}

void ft_action_auto_h_rotate(variable_list* l, int group)
{
	int i;
	double tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.x1[i] - l->me.x) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) *
				sin(l->me.angle) + l->me.x;
			l->t.z1[i] = -(l->t.x1[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x1[i] = tmp;
			tmp = (l->t.x2[i] - l->me.x) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) *
				sin(l->me.angle) + l->me.x;
			l->t.z2[i] = -(l->t.x2[i] - l->me.x) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x2[i] = tmp;
			tmp = (l->t.x3[i] - l->me.x) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) *
				sin(l->me.angle) + l->me.x;
			l->t.z3[i] = -(l->t.x3[i] - l->me.x) *
				sin(l->me.angle) + (l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.x3[i] = tmp;
		}
}

void ft_action_auto_h(variable_list* l, int group, int c)
{
	double value;
	double tmp;
	int i;

	c += ft_strings_count("H") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		ft_action_auto_calculate_center(l, group);
		l->me.angle = value;
		ft_action_auto_h_rotate(l, group);
		ft_action_auto_start(l, group, ++c);
	}
}

void ft_action_auto_v_rotate(variable_list* l, int group)
{
	int i;
	double tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) *
				sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) *
				sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) *
				sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
}

void ft_action_auto_v(variable_list* l, int group, int c)
{
	double value;
	double tmp;
	int i;

	c += ft_strings_count("V") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		ft_action_auto_calculate_center(l, group);
		l->me.angle = value;
		ft_action_auto_v_rotate(l, group);
		ft_action_auto_start(l, group, ++c);
	}
}

void ft_action_auto_l_rotate(variable_list* l, int group)
{
	int i;
	double tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.x1[i] - l->me.x) *
				sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.x2[i] - l->me.x) *
				sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +(l->t.x3[i] - l->me.x) *
				sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
}

void ft_action_auto_l(variable_list* l, int group, int c)
{
	double value;
	double tmp;
	int i;

	c += ft_strings_count("L") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		ft_action_auto_calculate_center(l, group);
		l->me.angle = value;
		ft_action_auto_l_rotate(l, group);
		ft_action_auto_start(l, group, ++c);
	}
}

void ft_action_auto_s_up(variable_list* l, int group, double value)
{
	int i;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			l->t.x1[i] *= 1 + 0.001 * value;
			l->t.x2[i] *= 1 + 0.001 * value;
			l->t.x3[i] *= 1 + 0.001 * value;
			l->t.y1[i] *= 1 + 0.001 * value;
			l->t.y2[i] *= 1 + 0.001 * value;
			l->t.y3[i] *= 1 + 0.001 * value;
			l->t.z1[i] *= 1 + 0.001 * value;
			l->t.z2[i] *= 1 + 0.001 * value;
			l->t.z3[i] *= 1 + 0.001 * value;
			l->t.texture_size_x[i] /= 1 + 0.001 * value;
			l->t.texture_size_y[i] /= 1 + 0.001 * value;
		}
}

void ft_action_auto_s_do(variable_list* l, int group, double value)
{
	int i;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			l->t.x1[i] /= 1 + 0.001 * value;
			l->t.x2[i] /= 1 + 0.001 * value;
			l->t.x3[i] /= 1 + 0.001 * value;
			l->t.y1[i] /= 1 + 0.001 * value;
			l->t.y2[i] /= 1 + 0.001 * value;
			l->t.y3[i] /= 1 + 0.001 * value;
			l->t.z1[i] /= 1 + 0.001 * value;
			l->t.z2[i] /= 1 + 0.001 * value;
			l->t.z3[i] /= 1 + 0.001 * value;
			l->t.texture_size_x[i] *= 1 + 0.001 * value;
			l->t.texture_size_y[i] *= 1 + 0.001 * value;
		}
}

void ft_action_auto_s_replace(variable_list* l, int group)
{
	double xyz[3];
	double p[3];
	int i;

	p[0] = l->me.x;
	p[1] = l->me.y;
	p[2] = l->me.z;
	ft_action_auto_calculate_center(l, group);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			xyz[0] = l->me.x - p[0];
			xyz[1] = l->me.y - p[1];
			xyz[2] = l->me.z - p[2];
			l->t.x1[i] -= xyz[0];
			l->t.x2[i] -= xyz[0];
			l->t.x3[i] -= xyz[0];
			l->t.y1[i] -= xyz[1];
			l->t.y2[i] -= xyz[1];
			l->t.y3[i] -= xyz[1];
			l->t.z1[i] -= xyz[2];
			l->t.z2[i] -= xyz[2];
			l->t.z3[i] -= xyz[2];
		}
}

void ft_action_auto_s(variable_list* l, int group, int c)
{
	double value;
	double tmp;
	int i;

	c += ft_strings_count("S") + 1;
	value = ft_atoi(l, l->g.action_auto[group], &c);
	if (l->g.action_auto[group][c] == ';')
	{
		ft_action_auto_calculate_center(l, group);
		if (value > 0)
			ft_action_auto_s_up(l, group, value);
		else if (value < 0)
			ft_action_auto_s_do(l, group, value);
		ft_action_auto_s_replace(l, group);
		ft_action_auto_start(l, group, ++c);
	}
}

void ft_action_auto_xyzhvls(variable_list* l, int group, int c)
{
	int i;

	if (ft_strings_compare(l->g.action_auto[group], "X", c))
		ft_action_auto_x(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "Y", c))
		ft_action_auto_y(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "Z", c))
		ft_action_auto_z(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "H", c))
		ft_action_auto_h(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "V", c))
		ft_action_auto_v(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "L", c))
		ft_action_auto_l(l, group, c);
	else if (ft_strings_compare(l->g.action_auto[group], "S", c))
		ft_action_auto_s(l, group, c);
			
}

void ft_action_auto_start(variable_list* l, int group, int c)
{
	int i;
	int value;
	double distance;

	if (ft_strings_compare(l->g.action_auto[group], "A", c))
	{
		value = ft_atoi(l, l->g.action_auto[group], &c);
		ft_action_auto_calculate_center(l, group);
		distance = sqrt((l->me.x - l->p.x) * (l->me.x - l->p.x) +
			(l->me.y - l->p.y) * (l->me.y - l->p.y) +
			(l->me.z - l->p.z) * (l->me.z - l->p.z));
		if ((value > 0 && distance <= value) || (value < 0 && distance > value))
		{
			c += 1;
			if (ft_strings_compare(l->g.action_auto[group], "T", c))
			{
				value = ft_atoi(l, l->g.action_auto[group], &c);
				if (value != 0 && l->cooldown % value == 0)
				{
					c += 1;
					ft_action_auto_xyzhvls(l, group, c);
				}
			}
			else if (ft_strings_compare(l->g.action_auto[group], "WIN", c))
			{
			}
			else if (l->menu_mode == 1 && ft_strings_compare(l->g.action_auto[group], "LOOT", c))
			{
				c += ft_strings_count("LOOT") + 1;
				l->hl.item_state[(int)ft_atoi(l, l->g.action_auto[group], &c)] = 1;
				if (l->g.action_auto[group][c] == ';')
				{
					i = -1;
					while (++i < l->triangle_number)
						if (l->t.group[i] == group)
							l->t.texture_opacity[i] = 0;
					ft_action_auto_start(l, group, ++c);
				}
			}
			else if (ft_strings_compare(l->g.action_auto[group], "HP", c))
			{
				l->hl.live_bar += ft_atoi(l, l->g.action_auto[group], &c);
				if (l->hl.live_bar > 100)
					l->hl.live_bar = 100;
				ft_action_auto_start(l, group, ++c);
			}
		}
	}
	else if (ft_strings_compare(l->g.action_auto[group], "T", c))
	{
		value = ft_atoi(l, l->g.action_auto[group], &c);
		if (value > 0 && l->cooldown % value == 0)
		{
			c += 1;
			ft_action_auto_xyzhvls(l, group, c);
		}
	}
}


void ft_action_auto(variable_list* l)
{
	int group;
	int c;
	int i;

	group = -1;
	while (++group < MAX_GROUPS)
	{
		if (l->g.action_auto[group][0] != 0)
		{
			c = 0;
			ft_action_auto_start(l, group, c);
		}
		if (l->g.object[group] == 1)
		{
			if (l->g.action_enable[group][0] != 0)
			{
				c = 0;
				//ft_action_enable_start(l, group, c);
			}
			if (l->g.action_disable[group][0] != 0)
			{
				c = 0;
				//ft_action_disable_start(l, group, c);
			}
		}
	}
}
