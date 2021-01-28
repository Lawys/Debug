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

