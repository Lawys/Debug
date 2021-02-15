#include "header.h"

int	ft_strings_compare(char* line, char* word, int c)
{
	int i;

	i = -1;
	while (word[++i] != '\0')
		if (word[i] != line[c + i])
			return (0);
	return (1);
}

void ft_action_x(variable_list* l, int group, int c, char * str)
{
	double value;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
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
		ft_action_start(l, group, ++c, str);
	}
}
void ft_action_y(variable_list* l, int group, int c, char* str)
{
	double value;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
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
		ft_action_start(l, group, ++c, str);
	}
}
void ft_action_z(variable_list* l, int group, int c, char* str)
{
	double value;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
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
		ft_action_start(l, group, ++c, str);
	}
}

void ft_action_calculate_center(variable_list* l, int group)
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

void ft_action_h_rotate(variable_list* l, int group)
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

void ft_action_h(variable_list* l, int group, int c, char* str)
{
	double value;
	double tmp;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_h_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void ft_action_v_rotate(variable_list* l, int group)
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

void ft_action_v(variable_list* l, int group, int c, char* str)
{
	double value;
	double tmp;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_v_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void ft_action_l_rotate(variable_list* l, int group)
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

void ft_action_l(variable_list* l, int group, int c, char *str)
{
	double value;
	double tmp;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_l_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void ft_action_s_up(variable_list* l, int group, double value)
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

void ft_action_s_do(variable_list* l, int group, double value)
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

void ft_action_s_replace(variable_list* l, int group)
{
	double xyz[3];
	double p[3];
	int i;

	p[0] = l->me.x;
	p[1] = l->me.y;
	p[2] = l->me.z;
	ft_action_calculate_center(l, group);
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

void ft_action_s(variable_list* l, int group, int c, char * str)
{
	double value;
	double tmp;
	int i;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		if (value > 0)
			ft_action_s_up(l, group, value);
		else if (value < 0)
			ft_action_s_do(l, group, value);
		ft_action_s_replace(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void ft_action_o(variable_list* l, int group, int c, char* str)
{
	int value;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
	{
		if (l->g.action_statement[value] == 1)
			l->g.action_statement[value] = 3;
		else if (l->g.action_statement[value] == 0)
			l->g.action_statement[value] = 2;
	}
}

void ft_action_xyzhvls(variable_list* l, int group, int c, char* str)
{
	int i;
	int value;
	if (ft_strings_compare(str, "ON>", c))
	{
		value = ft_atoi(l, str, &c);
		if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
		{
			l->g.action_statement[value] = 1;
			ft_action_start(l, group, ++c, str);
		}
	}
	else if (ft_strings_compare(str, "OFF>", c))
	{
		value = ft_atoi(l, str, &c);
		if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
		{
			l->g.action_statement[value] = 0;
			ft_action_start(l, group, ++c, str);
		}
	}
	else if (ft_strings_compare(str, "O>", c))
		ft_action_o(l, group, c, str);
	else if (ft_strings_compare(str, "X>", c))
		ft_action_x(l, group, c, str);
	else if (ft_strings_compare(str, "Y>", c))
		ft_action_y(l, group, c, str);
	else if (ft_strings_compare(str, "Z>", c))
		ft_action_z(l, group, c, str);
	else if (ft_strings_compare(str, "H>", c))
		ft_action_h(l, group, c, str);
	else if (ft_strings_compare(str, "V>", c))
		ft_action_v(l, group, c, str);
	else if (ft_strings_compare(str, "L>", c))
		ft_action_l(l, group, c, str);
	else if (ft_strings_compare(str, "S>", c))
		ft_action_s(l, group, c, str);
}

void ft_action_start(variable_list* l, int group, int c, char* str)
{
	int i;
	int value;
	double distance;

	if (ft_strings_compare(str, "!", c))
	{
		c = 1;
		if (str[c] == ';')
		{
			if (l->g.action_statement[group] == 0 || l->g.action_statement[group] == 2)
				l->g.action_statement[group] = 1;
			else if (l->g.action_statement[group] == 1 || l->g.action_statement[group] == 3)
				l->g.action_statement[group] = 0;
			return;
		}
	}
	if (ft_strings_compare(str, "T>", c))
	{

		value = ft_atoi(l, str, &c);
		if (value > 0 && l->g.action_timer[group] < l->cooldown)
			l->g.action_timer[group] = l->cooldown + value;
		else if (value == 0 || l->g.action_timer[group] == l->cooldown)
		{
			if (l->g.action_statement[group] == 0 || l->g.action_statement[group] == 2)
				l->g.action_statement[group] = 1;
			else if (l->g.action_statement[group] == 1 || l->g.action_statement[group] == 3)
				l->g.action_statement[group] = 0;
		}
		if (str[c] == '>')
		{
			value = ft_atoi(l, str, &c);
			if (value > 0 && l->cooldown % value == 0)
				ft_action_xyzhvls(l, group, ++c, str);
		}
	}
	else if (ft_strings_compare(str, "A>", c))
	{
		value = ft_atoi(l, str, &c);
		if (str[c] == '>')
		{
			ft_action_calculate_center(l, group);
			distance = sqrt((l->me.x - l->p.x) * (l->me.x - l->p.x) +
				(l->me.y - l->p.y) * (l->me.y - l->p.y) +
				(l->me.z - l->p.z) * (l->me.z - l->p.z));
			if ((value > 0 && distance <= value) || (value < 0 && distance > value))
			{
				if (ft_strings_compare(str, "END;", ++c))
				{

				}
				else if (ft_strings_compare(str, "ON>", ++c))
				{
					value = ft_atoi(l, str, &c);
					if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
					{
						l->g.action_statement[value] = 1;
						ft_action_start(l, group, ++c, str);
					}
				}
				else if (ft_strings_compare(str, "OFF>", ++c))
				{
					value = ft_atoi(l, str, &c);
					if (str[c] == ';' && value > 0 && value < MAX_GROUPS - 1)
					{
						l->g.action_statement[value] = 0;
						ft_action_start(l, group, ++c, str);
					}
				}
				else if (l->menu_mode == 1 && ft_strings_compare(str, "LOOT>", c))
				{
					value = (int)ft_atoi(l, str, &c);
					if (str[c] == ';' && value >= 0 && value < 9)
					{
						l->hl.obj[value][2] = 1;
						l->g.exist[group] = 0;
						ft_action_start(l, group, ++c, str);
					}
				}
				else if (ft_strings_compare(str, "LIFE>", c))
				{
					value = (int)ft_atoi(l, str, &c);
					if (str[c] == ';')
					{
						l->hl.live_bar += value;
						if (l->hl.live_bar > 100)
							l->hl.live_bar = 100;
						l->g.exist[group] = 0;
						ft_action_start(l, group, ++c, str);
					}
				}
			}
		}
	}
}


void ft_action(variable_list* l)
{
	int group;
	int c;
	int i;

	group = -1;
	while (++group < MAX_GROUPS)
	{

		if (l->g.exist[group])
		{
			if (l->g.action_enable[group][0] != '\0' && ((l->g.action_statement[group] == 1 && l->g.action_enable[group][0] == '!') || l->g.action_statement[group] == 3))
			{
				c = 0;
				ft_action_start(l, group, c, l->g.action_enable[group]);
			}
			if (l->g.action_disable[group][0] != '\0' && ((l->g.action_statement[group] == 0 && l->g.action_disable[group][0] == '!') || l->g.action_statement[group] == 2))
			{
				c = 0;
				ft_action_start(l, group, c, l->g.action_disable[group]);
			}
		}
	}
}
