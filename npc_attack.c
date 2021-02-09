#include "header.h"

void	ft_init_npc(variable_list* l)
{
	int i;

	i = -1;
	while (i++ < MAX_NPC)
	{
		l->l_npc[i / 2].g_id = -1;
		l->l_npc[i].life = LIFE_NPC;
		l->l_npc[i].timer = TIMER_NPC;
	}
}

int		npc_id(variable_list* l, int ret)
{
	int i;

	if (ret == -1)
		return (-1);
	i = -1;
	while (i++ < MAX_NPC)
		if (l->l_npc[i].g_id == ret)
			return (i);
	return (-1);
}

void    ft_get_npc(variable_list* l)
{
	int tn;
	int ts;
	int i;

	i = 0;
	tn = l->triangle_number;
	ts = -1;
	while (++ts < tn)
	{
		if (l->g.npc[l->t.group[ts]] == 1)
		{
			if (l->l_npc[i / 2].g_id == l->t.group[ts])
			{
				l->l_npc[i / 2].x = (l->t.x1[ts] + l->l_npc[i / 2].x) / 2;
				l->l_npc[i / 2].y = (l->t.y1[ts] + l->l_npc[i / 2].y) / 2;
				l->l_npc[i / 2].z = (l->t.z1[ts] + l->l_npc[i / 2].z) / 2;
			}
			else
			{
				l->l_npc[i / 2].g_id = l->t.group[ts];
				l->l_npc[i / 2].timer = TIMER_NPC;
				l->l_npc[i / 2].in_range = 0;
				l->l_npc[i / 2].x = l->t.x1[ts];
				l->l_npc[i / 2].y = l->t.y1[ts];
				l->l_npc[i / 2].z = l->t.z1[ts];
				l->l_npc[i / 2].angle = l->g.sprite_orientation[l->t.group[ts]];
			}
			i++;
		}
	}
}

int        ft_range(variable_list* l, int i, int flag)
{
	double distance;

	distance = sqrt((l->l_npc[i].x - l->p.x) * (l->l_npc[i].x - l->p.x) +
		(l->l_npc[i].y - l->p.y) * (l->l_npc[i].y - l->p.y) +
		(l->l_npc[i].z - l->p.z) * (l->l_npc[i].z - l->p.z));
	printf("distance %d : %f\n", i, distance);
	if (distance < RANGE_NPC)
		if (flag && ft_bullet(l, i, RANGE_NPC) == i)
			return (2);
	return (1);
	return (0);
}


void	npc_attack(variable_list* l)
{
	int i;
	double angle;
	int* sprite_angle;

	i = -1;
	while (i++ < MAX_NPC && l->l_npc[i].g_id != -1)
	{
		if (l->l_npc[i].life && (l->l_npc[i].in_range == 1 || ft_range(l, i, 0)))
		{
			l->l_npc[i].in_range = 1;
			angle = atan2(l->l_npc[i].x - l->p.x, l->l_npc[i].z - l->p.z) * 180 / M_PI + 180;
			sprite_angle = &l->g.sprite_orientation[l->l_npc[i].g_id];
			//if (*sprite_angle != (int)angle)
			//{
				*sprite_angle = (int)angle;
			//}
			if (l->l_npc[i].timer-- == 0)
			{
				l->l_npc[i].in_range = 0;
				l->l_npc[i].timer = TIMER_NPC;
				if (ft_range(l, i, 1) == 2)
					printf("npc attack %d\n", i);
			}
		}
	}
}