#include "header.h"


void ft_script_on_input_group_74(variable_list* l, int ts)
{
	if (l->script_v1[l->t.group[ts]] == 0)
	{

		l->script_v1[l->t.group[ts]] = 1;
		ts = -1;
		while (++ts < l->triangle_number)
		{
			if (l->t.group[ts] == 74 && l->t.texture_id[ts] == 20)
			{
				l->t.texture_id[ts] = 21;
			}
		}
	}
	else if (l->script_v1[l->t.group[ts]] == 52)
	{
		l->script_v1[l->t.group[ts]]++;
		ts = -1;
		while (++ts < l->triangle_number)
		{
			if (l->t.group[ts] == 74 && l->t.texture_id[ts] == 20)
			{
				l->t.texture_id[ts] = 21;
			}
		}
	}
}

void ft_script_on_input_check_list(variable_list* l)
{
	int ts;

	ts = l->pixels_triangle[WDW2][WDH2];
	if (l->t.group[ts] == 74)
		ft_script_on_input_group_74(l, ts);

}

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

void ft_script_auto_start(variable_list* l, int group, int c)
{
	int i;
	unsigned int timer;

	timer = ft_atoi(l, l->g.action_auto[group], &c);
	if (timer != 0 && l->cooldown % timer == 0)
	{
		c += 1;
		if (ft_strings_compare(l->g.action_auto[group], "X", c))
		{
			c += ft_strings_count("X") + 1;
			double value;

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
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "Y", c))
		{
			c += ft_strings_count("Y") + 1;
			double value;

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
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "Z", c))
		{
			c += ft_strings_count("Z") + 1;
			double value;

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
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "H", c))
		{
			c += ft_strings_count("H") + 1;
			double value;

			value = ft_atoi(l, l->g.action_auto[group], &c);
			if (l->g.action_auto[group][c] == ';')
			{
				int s;
				double tmp;

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

				l->me.angle = value;
				i = 0;
				while (i < l->triangle_number)
				{
					if (l->t.group[i] == group)
					{
						tmp = (l->t.x1[i] - l->me.x) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.x;
						l->t.z1[i] = -(l->t.x1[i] - l->me.x) * sin(l->me.angle) + (l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.x1[i] = tmp;
						tmp = (l->t.x2[i] - l->me.x) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.x;
						l->t.z2[i] = -(l->t.x2[i] - l->me.x) * sin(l->me.angle) + (l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.x2[i] = tmp;
						tmp = (l->t.x3[i] - l->me.x) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.x;
						l->t.z3[i] = -(l->t.x3[i] - l->me.x) * sin(l->me.angle) + (l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.x3[i] = tmp;
					}
					i++;
				}
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "V", c))
		{
			c += ft_strings_count("V") + 1;
			double value;

			value = ft_atoi(l, l->g.action_auto[group], &c);
			if (l->g.action_auto[group][c] == ';')
			{
				int s;
				double tmp;

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

				l->me.angle = value;
				i = 0;
				while (i < l->triangle_number)
				{
					if (l->t.group[i] == group)
					{
						tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
						l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.y1[i] = tmp;
						tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
						l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.y2[i] = tmp;
						tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
						l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
						l->t.y3[i] = tmp;
					}
					i++;
				}
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "L", c))
		{
			c += ft_strings_count("L") + 1;
			double value;

			value = ft_atoi(l, l->g.action_auto[group], &c);
			if (l->g.action_auto[group][c] == ';')
			{
				int s;
				double tmp;

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

				l->me.angle = value;
				i = 0;
				while (i < l->triangle_number)
				{
					if (l->t.group[i] == group)
					{
						tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
						l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
						l->t.y1[i] = tmp;
						tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
						l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
						l->t.y2[i] = tmp;
						tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
						l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
						l->t.y3[i] = tmp;
					}
					i++;
				}
				ft_script_auto_start(l, group, ++c);
			}
		}
		else if (ft_strings_compare(l->g.action_auto[group], "S", c))
		{
			c += ft_strings_count("S") + 1;
			double value;

			value = ft_atoi(l, l->g.action_auto[group], &c);
			if (l->g.action_auto[group][c] == ';')
			{
				int s;
				double tmp;

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

				if (value > 0)
				{
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
				else if (value < 0)
				{
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
				double xyz[3];
				double p[3];

				p[0] = l->me.x;
				p[1] = l->me.y;
				p[2] = l->me.z;
				
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

				i = -1;
				while (++i < l->triangle_number)
				{
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

				ft_script_auto_start(l, group, ++c);
			}
		}
	}
}


void ft_script_auto(variable_list* l)
{
	int group;
	int c;
	int i;

	group = -1;
	while (++group < MAX_GROUPS)
	{
		c = 0;
		if (l->g.action_auto[group][0] != 0)
		{
			ft_script_auto_start(l, group, c);
		}
	}
}

