#include "header.h"

void		ft_action_h(variable_list* l, int group, int c, char* str)
{
	double value;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_h_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_v_rotate(variable_list* l, int group)
{
	int i;
	double tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
}

void		ft_action_v(variable_list* l, int group, int c, char* str)
{
	double value;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_v_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}

void		ft_action_l_rotate(variable_list* l, int group)
{
	int i;
	double tmp;

	i = -1;
	while (++i < l->triangle_number)
		if (l->t.group[i] == group)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
}

void		ft_action_l(variable_list* l, int group, int c, char* str)
{
	double value;

	value = ft_atoi(l, str, &c);
	if (str[c] == ';')
	{
		ft_action_calculate_center(l, group);
		l->me.angle = value;
		ft_action_l_rotate(l, group);
		ft_action_start(l, group, ++c, str);
	}
}
