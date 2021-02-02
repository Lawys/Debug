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



void ft_script_auto(variable_list* l)
{
	int ts;
	double tmp;
	int i;
	int group;
	int c;

	group = -1;
	while (++group < MAX_GROUPS)
	{
		if (l->g.object[group] == 1)
		{
			l->me.x = 0;
			l->me.y = 0;
			l->me.z = 0;
			c = 0;
			i = -1;
			while (i < l->triangle_number)
			{
				if (l->t.group[i] == group)
				{
					c++;
					l->me.x += (l->t.x1[i] + l->t.x2[i] + l->t.x3[i]) / 3;
					l->me.y += (l->t.y1[i] + l->t.y2[i] + l->t.y3[i]) / 3;
					l->me.z += (l->t.z1[i] + l->t.z2[i] + l->t.z3[i]) / 3;
				}
				i++;
			}
			l->me.x = l->me.x / c;
			l->me.y = l->me.y / c;
			l->me.z = l->me.z / c;

			l->me.angle = M_PI / 180;
			i = -1;
			while (++i < l->triangle_number)
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
			}
		}
	}


	if (l->script_v1[74] > 0)
	{
		if (l->script_v1[74] < 51)
		{
			ts = -1;
			while (++ts < l->triangle_number)
			{
				if (l->t.group[ts] == 629)
				{
					l->t.z1[ts]--;
					l->t.z2[ts]--;
					l->t.z3[ts]--;
				}
			}
			l->script_v1[74]++;
		}
		else if (l->script_v1[74] == 51)
		{
			ts = -1;
			while (++ts < l->triangle_number)
			{
				if (l->t.group[ts] == 74 && l->t.texture_id[ts] == 21)
				{
					l->t.texture_id[ts] = 20;
				}
			}
			l->script_v1[74]++;
		}
		else if (l->script_v1[74] > 52 && l->script_v1[74] < 103)
		{
			ts = -1;
			while (++ts < l->triangle_number)
			{
				if (l->t.group[ts] == 629)
				{
					l->t.z1[ts]++;
					l->t.z2[ts]++;
					l->t.z3[ts]++;
				}
			}
			l->script_v1[74]++;
		}
		else if (l->script_v1[74] == 103)
		{
			ts = -1;
			while (++ts < l->triangle_number)
			{
				if (l->t.group[ts] == 74 && l->t.texture_id[ts] == 21)
				{
					l->t.texture_id[ts] = 20;
				}
			}
			l->script_v1[74] = 0;
		}
	}
}

