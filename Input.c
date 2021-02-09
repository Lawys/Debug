#include "header.h"

void	ft_event_playing_mode_motion(variable_list* l)
{
	l->p.h += (((double)WDW2) - l->i.mouse_x) / 360;
	l->p.v += (((double)WDH2) - l->i.mouse_y) / 360;
	SDL_WarpMouseInWindow(l->window, WDW2, WDH2);
	if (l->p.v > M_PI / 2 - M_PI / 45)
		l->p.v = M_PI / 2 - M_PI / 45;
	else if (l->p.v < -M_PI / 2 + M_PI / 45)
		l->p.v = -M_PI / 2 + M_PI / 45;
}

/*void	ft_event_playing_mode_player_line_line_intersection(variable_list* l)
{
	tmp->x = 0;
	tmp->y = 0;
	if ((tmp->x1 - tmp->x2) * (tmp->y3 - tmp->y4) - (tmp->y1 - tmp->y2) * (tmp->x3 - tmp->x4) != 0)
	{
		tmp->t = ((tmp->x1 - tmp->x3) * (tmp->y3 - tmp->y4) - (tmp->y1 - tmp->y3) * (tmp->x3 - tmp->x4)) /
			((tmp->x1 - tmp->x2) * (tmp->y3 - tmp->y4) - (tmp->y1 - tmp->y2) * (tmp->x3 - tmp->x4));
		tmp->u = -((tmp->x1 - tmp->x2) * (tmp->y1 - tmp->y3) - (tmp->y1 - tmp->y2) * (tmp->x1 - tmp->x3)) /
			((tmp->x1 - tmp->x2) * (tmp->y3 - tmp->y4) - (tmp->y1 - tmp->y2) * (tmp->x3 - tmp->x4));
		if (tmp->t > 0 && tmp->t < 1 && tmp->u > 0 && tmp->u < 1)
		{
			tmp->x = tmp->x1 + tmp->t * (tmp->x2 - tmp->x1);
			tmp->y = tmp->y1 + tmp->t * (tmp->y2 - tmp->y1);
		}
	}
}*/
void	ft_event_playing_mode_player_line_plan_t(variable_list* l, player_move_list* tmp)
{
	tmp->t =
		(tmp->nx * (l->p.x - tmp->p1x) +
			tmp->ny * (l->p.y - tmp->p1y) +
			tmp->nz * (l->p.z - tmp->p1z)) /
		(-tmp->vx * tmp->nx +
			-tmp->vy * tmp->ny +
			-tmp->vz * tmp->nz);
}

void	ft_event_playing_mode_player_line_plan_u(variable_list* l, player_move_list* tmp)
{
	tmp->u =
		((-tmp->vy * tmp->p02z - -tmp->vz * tmp->p02y) *
			(l->p.x - tmp->p1x) +
			(-tmp->vz * tmp->p02x - -tmp->vx * tmp->p02z) *
			(l->p.y - tmp->p1y) +
			(-tmp->vx * tmp->p02y - -tmp->vy * tmp->p02x) *
			(l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}

void	ft_event_playing_mode_player_line_plan_v(variable_list* l, player_move_list* tmp)
{
	tmp->v =
		((tmp->p01y * -tmp->vz - tmp->p01z * -tmp->vy) *
			(l->p.x - tmp->p1x) +
			(tmp->p01z * -tmp->vx - tmp->p01x * -tmp->vz) *
			(l->p.y - tmp->p1y) +
			(tmp->p01x * -tmp->vy - tmp->p01y * -tmp->vx) *
			(l->p.z - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}

void	ft_event_playing_mode_player_vector_intersection(variable_list* l, player_move_list* tmp)
{
	double x;
	double y;
	double z;

	ft_event_playing_mode_player_line_plan_t(l, tmp);
	ft_event_playing_mode_player_line_plan_u(l, tmp);
	ft_event_playing_mode_player_line_plan_v(l, tmp);
	if (tmp->t > 0 && tmp->t <= 1 &&
		tmp->u >= 0 && tmp->u <= 1 &&
		tmp->v >= 0 && tmp->v <= 1 &&
		tmp->u + tmp->v <= 1)
	{
		x = tmp->vx * tmp->t;
		y = tmp->vy * tmp->t;
		z = tmp->vz * tmp->t;
		//printf("%f %f %f\n", x, y, z);

		if (x > 0 && x < tmp->save_px && fabs(tmp->nx) > fabs(tmp->ny))
			tmp->save_px = x;
		else if (x < 0 && x > tmp->save_nx && fabs(tmp->nx) > fabs(tmp->ny))
			tmp->save_nx = x;

		if (z > 0 && z < tmp->save_pz && fabs(tmp->nz) > fabs(tmp->ny))
			tmp->save_pz = z;
		else if (z < 0 && z > tmp->save_nz && fabs(tmp->nz) > fabs(tmp->ny))
			tmp->save_nz = z;

		if (y > 0 && y < tmp->save_py && tmp->ny > 0)
			tmp->save_py = y;
		else if (y < 0 && y > tmp->save_ny && tmp->ny < 0)
			tmp->save_ny = y;

	}
}
void	ft_event_playing_mode_triangle_init(variable_list* l, player_move_list* tmp, int ts)
{
	tmp->p1x = l->t.x1[ts];
	tmp->p2x = l->t.x2[ts];
	tmp->p3x = l->t.x3[ts];
	tmp->p1y = l->t.y1[ts];
	tmp->p2y = l->t.y2[ts];
	tmp->p3y = l->t.y3[ts];
	tmp->p1z = l->t.z1[ts];
	tmp->p2z = l->t.z2[ts];
	tmp->p3z = l->t.z3[ts];
	tmp->p01x = tmp->p2x - tmp->p1x;
	tmp->p02x = tmp->p3x - tmp->p1x;
	tmp->p01y = tmp->p2y - tmp->p1y;
	tmp->p02y = tmp->p3y - tmp->p1y;
	tmp->p01z = tmp->p2z - tmp->p1z;
	tmp->p02z = tmp->p3z - tmp->p1z;
	tmp->nx = tmp->p01y * tmp->p02z -
		tmp->p01z * tmp->p02y;
	tmp->ny = tmp->p01z * tmp->p02x -
		tmp->p01x * tmp->p02z;
	tmp->nz = tmp->p01x * tmp->p02y -
		tmp->p01y * tmp->p02x;
}

void	ft_event_playing_mode_triangle_line_plan_t(variable_list* l, player_move_list* tmp)
{
	tmp->t =
		(tmp->nx * (tmp->p[0] - tmp->p1x) +
			tmp->ny * (tmp->p[1] - tmp->p1y) +
			tmp->nz * (tmp->p[2] - tmp->p1z)) /
		(-tmp->vx * tmp->nx +
			-tmp->vy * tmp->ny +
			-tmp->vz * tmp->nz);
}
void	ft_event_playing_mode_triangle_line_plan_u(variable_list* l, player_move_list* tmp)
{
	tmp->u =
		((-tmp->vy * tmp->p02z - -tmp->vz * tmp->p02y) *
			(tmp->p[0] - tmp->p1x) +
			(-tmp->vz * tmp->p02x - -tmp->vx * tmp->p02z) *
			(tmp->p[1] - tmp->p1y) +
			(-tmp->vx * tmp->p02y - -tmp->vy * tmp->p02x) *
			(tmp->p[2] - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}
void	ft_event_playing_mode_triangle_line_plan_v(variable_list* l, player_move_list* tmp)
{
	tmp->v =
		((tmp->p01y * -tmp->vz - tmp->p01z * -tmp->vy) *
			(tmp->p[0] - tmp->p1x) +
			(tmp->p01z * -tmp->vx - tmp->p01x * -tmp->vz) *
			(tmp->p[1] - tmp->p1y) +
			(tmp->p01x * -tmp->vy - tmp->p01y * -tmp->vx) *
			(tmp->p[2] - tmp->p1z)) /
		(tmp->vx * tmp->nx +
			tmp->vy * tmp->ny +
			tmp->vz * tmp->nz);
}
void	ft_event_playing_mode_triangle_vector_intersection(variable_list* l, player_move_list* tmp)
{
	double x;
	double y;
	double z;
	double dist;

	ft_event_playing_mode_triangle_line_plan_t(l, tmp);
	ft_event_playing_mode_triangle_line_plan_u(l, tmp);
	ft_event_playing_mode_triangle_line_plan_v(l, tmp);
	if (tmp->t >= 0 && tmp->t <= 1 &&
		tmp->u >= 0 && tmp->u <= 1 &&
		tmp->v >= 0 && tmp->v <= 1)
	{
		x = (tmp->p[0] + tmp->vx * tmp->t) - l->p.x;
		y = (tmp->p[1] + tmp->vy * tmp->t) - l->p.y;
		z = (tmp->p[2] + tmp->vz * tmp->t) - l->p.z;

		if (x > 0 && x < tmp->save_px)
			tmp->save_px = x;
		else if (x < 0 && x > tmp->save_nx)
			tmp->save_nx = x;

		if (z > 0 && z < tmp->save_pz)
			tmp->save_pz = z;
		else if (z < 0 && z > tmp->save_nz)
			tmp->save_nz = z;

		if (y > 0 && y < tmp->save_py && tmp->vy < 0)
			tmp->save_py = y;
		else if (y < 0 && y > tmp->save_ny)
			tmp->save_ny = y;
	}
}
void	ft_event_playing_mode_player_hitbox_triangle_init(player_move_list* tmp)
{
	tmp->p01x = tmp->p2x - tmp->p1x;
	tmp->p02x = tmp->p3x - tmp->p1x;
	tmp->p01y = tmp->p2y - tmp->p1y;
	tmp->p02y = tmp->p3y - tmp->p1y;
	tmp->p01z = tmp->p2z - tmp->p1z;
	tmp->p02z = tmp->p3z - tmp->p1z;
	tmp->nx = tmp->p01y * tmp->p02z -
		tmp->p01z * tmp->p02y;
	tmp->ny = tmp->p01z * tmp->p02x -
		tmp->p01x * tmp->p02z;
	tmp->nz = tmp->p01x * tmp->p02y -
		tmp->p01y * tmp->p02x;
}

void	ft_event_playing_mode_player_wallblock_init(variable_list* l, player_move_list* tmp)
{
	tmp->move_x = 0;
	tmp->move_y = 0;
	tmp->move_z = 0;
	tmp->save_px = 100, tmp->save_py = 100, tmp->save_pz = 100;
	tmp->save_nx = -100, tmp->save_ny = -100, tmp->save_nz = -100;
	if (l->i.state[26]) // haut
	{
		tmp->move_x -= sin(l->p.h) * l->p.speed;
		tmp->move_z += cos(l->p.h) * l->p.speed;
	}
	else if (l->i.state[22]) // bas
	{
		tmp->move_x += sin(l->p.h) * l->p.speed;
		tmp->move_z -= cos(l->p.h) * l->p.speed;
	}
	if (l->i.state[4]) // gauche
	{
		tmp->move_x -= cos(l->p.h) * l->p.speed;
		tmp->move_z -= sin(l->p.h) * l->p.speed;
	}
	else if (l->i.state[7]) // droite
	{
		tmp->move_x += cos(l->p.h) * l->p.speed;
		tmp->move_z += sin(l->p.h) * l->p.speed;
	}
}
void	ft_event_playing_mode_player_wallblock_gravity(variable_list* l)
{
	l->gravity += 0.5;
	if (l->gravity > 10)
		l->gravity = 10;
	l->p.y -= l->gravity;
}
void	ft_event_playing_mode_player_wallblock(variable_list* l)
{
	player_move_list tmp;
	int ts;

	ft_event_playing_mode_player_wallblock_init(l, &tmp);
	ft_event_playing_mode_player_wallblock_gravity(l);
	l->p.z += tmp.move_z * l->p.speed;
	l->p.x += tmp.move_x * l->p.speed;
	if (l->i.state[20])
	{
		l->gravity = 0;
		l->p.y += 2;
	}

	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->g.object[l->t.group[ts]] == 0 && l->g.npc[l->t.group[ts]] == 0 && l->g.sprite[l->t.group[ts]] == 0)
		{
			ft_event_playing_mode_triangle_init(l, &tmp, ts);

			tmp.vx = 10;
			tmp.vz = 10;
			tmp.vy = 5;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 10;
			tmp.vz = -10;
			tmp.vy = 5;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = -10;
			tmp.vy = 5;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = 10;
			tmp.vy = 5;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 10;
			tmp.vz = 10;
			tmp.vy = -50;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 10;
			tmp.vz = -10;
			tmp.vy = -50;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = -10;
			tmp.vy = -50;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = 10;
			tmp.vy = -50;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);

			tmp.vx = 10;
			tmp.vz = 10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 10;
			tmp.vz = -10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = -10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = -10;
			tmp.vz = 10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);

			tmp.vx = -10;
			tmp.vz = 0;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 10;
			tmp.vz = 0;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 0;
			tmp.vz = -10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 0;
			tmp.vz = 10;
			tmp.vy = 0;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);

			tmp.vx = 0;
			tmp.vz = 0;
			tmp.vy = 5;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
			tmp.vx = 0;
			tmp.vz = 0;
			tmp.vy = -50;
			ft_event_playing_mode_player_vector_intersection(l, &tmp);
		}
	}
	/*
	tmp.p1x = l->p.x + -10;
	tmp.p1y = l->p.y + -49;
	tmp.p1z = l->p.z + 10;
	tmp.p2x = l->p.x + -10;
	tmp.p2y = l->p.y + 5;
	tmp.p2z = l->p.z + 10;
	tmp.p3x = l->p.x + 10;
	tmp.p3y = l->p.y + -49;
	tmp.p3z = l->p.z + 10;
	ft_event_playing_mode_player_hitbox_triangle_init(&tmp);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		tmp.vx = l->t.x2[ts] - l->t.x1[ts];
		tmp.vy = l->t.y2[ts] - l->t.y1[ts];
		tmp.vz = l->t.z2[ts] - l->t.z1[ts];
		tmp.p[0] = l->t.x1[ts];
		tmp.p[1] = l->t.y1[ts];
		tmp.p[2] = l->t.z1[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x3[ts] - l->t.x2[ts];
		tmp.vy = l->t.y3[ts] - l->t.y2[ts];
		tmp.vz = l->t.z3[ts] - l->t.z2[ts];
		tmp.p[0] = l->t.x2[ts];
		tmp.p[1] = l->t.y2[ts];
		tmp.p[2] = l->t.z2[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x1[ts] - l->t.x3[ts];
		tmp.vy = l->t.y1[ts] - l->t.y3[ts];
		tmp.vz = l->t.z1[ts] - l->t.z3[ts];
		tmp.p[0] = l->t.x3[ts];
		tmp.p[1] = l->t.y3[ts];
		tmp.p[2] = l->t.z3[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
	}
	tmp.p1x = l->p.x + 10;
	tmp.p1y = l->p.y + -49;
	tmp.p1z = l->p.z + 10;
	tmp.p2x = l->p.x + 10;
	tmp.p2y = l->p.y + 5;
	tmp.p2z = l->p.z + 10;
	tmp.p3x = l->p.x + 10;
	tmp.p3y = l->p.y + -49;
	tmp.p3z = l->p.z + -10;
	ft_event_playing_mode_player_hitbox_triangle_init(&tmp);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		tmp.vx = l->t.x2[ts] - l->t.x1[ts];
		tmp.vy = l->t.y2[ts] - l->t.y1[ts];
		tmp.vz = l->t.z2[ts] - l->t.z1[ts];
		tmp.p[0] = l->t.x1[ts];
		tmp.p[1] = l->t.y1[ts];
		tmp.p[2] = l->t.z1[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x3[ts] - l->t.x2[ts];
		tmp.vy = l->t.y3[ts] - l->t.y2[ts];
		tmp.vz = l->t.z3[ts] - l->t.z2[ts];
		tmp.p[0] = l->t.x2[ts];
		tmp.p[1] = l->t.y2[ts];
		tmp.p[2] = l->t.z2[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x1[ts] - l->t.x3[ts];
		tmp.vy = l->t.y1[ts] - l->t.y3[ts];
		tmp.vz = l->t.z1[ts] - l->t.z3[ts];
		tmp.p[0] = l->t.x3[ts];
		tmp.p[1] = l->t.y3[ts];
		tmp.p[2] = l->t.z3[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
	}
	tmp.p1x = l->p.x + 10;
	tmp.p1y = l->p.y + -49;
	tmp.p1z = l->p.z + -10;
	tmp.p2x = l->p.x + 10;
	tmp.p2y = l->p.y + 5;
	tmp.p2z = l->p.z + -10;
	tmp.p3x = l->p.x + -10;
	tmp.p3y = l->p.y + -49;
	tmp.p3z = l->p.z + -10;
	ft_event_playing_mode_player_hitbox_triangle_init(&tmp);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		tmp.vx = l->t.x2[ts] - l->t.x1[ts];
		tmp.vy = l->t.y2[ts] - l->t.y1[ts];
		tmp.vz = l->t.z2[ts] - l->t.z1[ts];
		tmp.p[0] = l->t.x1[ts];
		tmp.p[1] = l->t.y1[ts];
		tmp.p[2] = l->t.z1[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x3[ts] - l->t.x2[ts];
		tmp.vy = l->t.y3[ts] - l->t.y2[ts];
		tmp.vz = l->t.z3[ts] - l->t.z2[ts];
		tmp.p[0] = l->t.x2[ts];
		tmp.p[1] = l->t.y2[ts];
		tmp.p[2] = l->t.z2[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x1[ts] - l->t.x3[ts];
		tmp.vy = l->t.y1[ts] - l->t.y3[ts];
		tmp.vz = l->t.z1[ts] - l->t.z3[ts];
		tmp.p[0] = l->t.x3[ts];
		tmp.p[1] = l->t.y3[ts];
		tmp.p[2] = l->t.z3[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
	}
	tmp.p1x = l->p.x + -10;
	tmp.p1y = l->p.y + -49;
	tmp.p1z = l->p.z + -10;
	tmp.p2x = l->p.x + -10;
	tmp.p2y = l->p.y + 5;
	tmp.p2z = l->p.z + -10;
	tmp.p3x = l->p.x + -10;
	tmp.p3y = l->p.y + -49;
	tmp.p3z = l->p.z + 10;
	ft_event_playing_mode_player_hitbox_triangle_init(&tmp);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		tmp.vx = l->t.x2[ts] - l->t.x1[ts];
		tmp.vy = l->t.y2[ts] - l->t.y1[ts];
		tmp.vz = l->t.z2[ts] - l->t.z1[ts];
		tmp.p[0] = l->t.x1[ts];
		tmp.p[1] = l->t.y1[ts];
		tmp.p[2] = l->t.z1[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x3[ts] - l->t.x2[ts];
		tmp.vy = l->t.y3[ts] - l->t.y2[ts];
		tmp.vz = l->t.z3[ts] - l->t.z2[ts];
		tmp.p[0] = l->t.x2[ts];
		tmp.p[1] = l->t.y2[ts];
		tmp.p[2] = l->t.z2[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
		tmp.vx = l->t.x1[ts] - l->t.x3[ts];
		tmp.vy = l->t.y1[ts] - l->t.y3[ts];
		tmp.vz = l->t.z1[ts] - l->t.z3[ts];
		tmp.p[0] = l->t.x3[ts];
		tmp.p[1] = l->t.y3[ts];
		tmp.p[2] = l->t.z3[ts];
		ft_event_playing_mode_triangle_vector_intersection(l, &tmp);
	}
	*/
	//printf("->pos %f %f %f\n", tmp.save_px, tmp.save_py, tmp.save_pz);
	//printf("->neg %f %f %f\n", tmp.save_nx, tmp.save_ny, tmp.save_nz);
	//printf("->mov %f %f\n", tmp.move_x, tmp.move_z);

	if (tmp.save_py != 100 && tmp.save_ny != -100)
		l->p.y += l->gravity;
	else
	{
		if (tmp.save_py <= 5)
			l->p.y += tmp.save_py - 5;
		else if (tmp.save_ny == -50)
		{
			l->gravity = 0;
		}
		else if (tmp.save_ny > -50)
		{
			l->p.y += tmp.save_ny + 50;
			l->gravity = 0;
		}
	}
		if ((tmp.save_px != 100 || tmp.save_nx != -100) || (tmp.save_pz != 100 || tmp.save_nz != -100))
		{

			l->p.x -= tmp.move_x * l->p.speed;
			l->p.z -= tmp.move_z * l->p.speed;
			/*if ((tmp.save_px == 10 && tmp.move_x < 0) ||
				(tmp.save_nx == -10 && tmp.move_x > 0))
				l->p.x += tmp.move_x * l->p.speed;
			else if (tmp.save_px < 10 && tmp.save_nx == -100)
				l->p.x += tmp.save_px - 10;
			else if (tmp.save_nx > -10 && tmp.save_px == 100)
				l->p.x += tmp.save_nx + 10;*/
		}
		//else
		//	l->p.x += tmp.move_x * l->p.speed;

		/*if (tmp.save_pz != 100 || tmp.save_nz != -100)
		{
			l->p.x -= tmp.move_x * l->p.speed;
			l->p.z -= tmp.move_z * l->p.speed;
			/*if ((tmp.save_pz == 10 && tmp.move_z < 0) ||
				(tmp.save_nz == -10 && tmp.move_z > 0))
				l->p.z += tmp.move_z * l->p.speed;
			else if (tmp.save_pz < 10 && tmp.save_nz == -100)
				l->p.z += tmp.save_pz - 10;
			else if (tmp.save_nz > -10 && tmp.save_pz == 100)
				l->p.z += tmp.save_nz + 10;*/
		//}
		//else
		//	l->p.z += tmp.move_z * l->p.speed;
	
}

void	ft_event_playing_mode_player_crawl_or_squat
(variable_list* l)
{
	if (l->i.state[6])
	{
		if (l->p.player_squat_timer < 35)
			l->p.player_squat_timer += 5;
		l->p.speed *= 0.25;
	}
	else if (l->i.state[224])
	{
		if (l->p.player_squat_timer < 20)
			l->p.player_squat_timer += 5;
		l->p.speed *= 0.5;
	}
	else
	{
		if (l->p.player_squat_timer > 0)
			l->p.player_squat_timer -= 5;
	}
}

void	ft_event_playing_mode_player(variable_list* l)
{
	l->p.speed = 2;
	ft_event_playing_mode_player_crawl_or_squat(l);
	if (l->i.state[225]) //MAJ sprint
		l->p.speed = 3;
	if (l->i.state[26] + l->i.state[22] +
		l->i.state[7] + l->i.state[4] > 1)
		l->p.speed *= 0.75;
	ft_event_playing_mode_player_wallblock(l);
	if (l->i.state[8] &&
		l->pixels_distance[WDW2][WDH2] < 30)
	{
		//ft_action_on_input_check_list(l);
	}
}

void	ft_event_playing_mode(variable_list* l)
{

	ft_event_playing_mode_motion(l);
	ft_event_playing_mode_player(l);
}

void	ft_event_map_editor_mode_motion_right_click_on(variable_list* l)
{
	if (l->i.save_mouse_x == 0 && l->i.save_mouse_y == 0)
	{
		l->i.save_mouse_x = l->i.mouse_x;
		l->i.save_mouse_y = l->i.mouse_y;
	}
	else
	{
		l->p.h += ((double)l->i.save_mouse_x - l->i.mouse_x) / 360;
		l->p.v += ((double)l->i.save_mouse_y - l->i.mouse_y) / 360;
		l->i.save_mouse_x -= l->i.save_mouse_x - l->i.mouse_x;
		l->i.save_mouse_y -= l->i.save_mouse_y - l->i.mouse_y;
		SDL_WarpMouseInWindow(l->window, l->i.save_mouse_x, l->i.save_mouse_y);
		if (l->p.v > M_PI / 2)
			l->p.v = M_PI / 2;
		else if (l->p.v < -M_PI / 2)
			l->p.v = -M_PI / 2;
		if (l->p.h > M_PI * 2)
			l->p.h -= M_PI * 2;
		else if (l->p.h < 0)
			l->p.h += M_PI * 2;

	}
}

void	ft_event_map_editor_mode_motion_right_click_off(variable_list* l)
{

	SDL_WarpMouseInWindow(l->window, l->i.save_mouse_x, l->i.save_mouse_y);
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
}

void	ft_event_map_editor_mode_motion(variable_list* l)
{
	if (l->i.mouse == 4)
		ft_event_map_editor_mode_motion_right_click_on(l);
	else if (l->i.save_mouse_x != 0 || l->i.save_mouse_y != 0)
		ft_event_map_editor_mode_motion_right_click_off(l);
}

void	ft_event_map_editor_mode_moving(variable_list* l)
{

	if (l->i.state[26]) // haut
	{

		l->p.x -= sin(l->p.h) * l->p.speed;
		l->p.z += cos(l->p.h) * l->p.speed;
	}
	else if (l->i.state[22]) // bas
	{
		l->p.x += sin(l->p.h) * l->p.speed;
		l->p.z -= cos(l->p.h) * l->p.speed;
	}
	if (l->i.state[4]) // gauche
	{
		l->p.x -= cos(l->p.h) * l->p.speed;
		l->p.z -= sin(l->p.h) * l->p.speed;
	}
	else if (l->i.state[7]) // droite
	{
		l->p.x += cos(l->p.h) * l->p.speed;
		l->p.z += sin(l->p.h) * l->p.speed;
	}
}

void	ft_event_map_editor_mode_mouse_time_pressing_counter(variable_list* l)
{
	if (l->i.mouse == 0)
		l->i.mouse_time_pressing = 0;
	else
		l->i.mouse_time_pressing++;
}

void	ft_event_map_editor_mode_select_triangle(variable_list* l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->triangle_select =
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2];
}

void	ft_event_map_editor_mode_select_area(variable_list* l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->area_select = l->t.area[
			l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2]];
}

void	ft_event_map_editor_mode_select_group(variable_list* l)
{
	if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0 &&
		l->pixels_triangle[l->i.mouse_x / 2][l->i.mouse_y / 2] != -1)
		l->group_select = l->t.group[l->pixels_triangle[
			l->i.mouse_x / 2][l->i.mouse_y / 2]];
}

void	ft_event_map_editor_mode_select_on_click(variable_list* l)
{
	if (l->i.mouse == 1 && l->i.mouse_time_pressing == 1)
	{
		if (l->action_select[0][1])
			ft_event_map_editor_mode_select_triangle(l);
		else if (l->action_select[0][2])
			ft_event_map_editor_mode_select_area(l);
		else if (l->action_select[0][3])
			ft_event_map_editor_mode_select_group(l);
	}
}

void	ft_event_map_editor_mode_moving_y(variable_list* l)
{
	if (l->i.state[20])
		l->p.y += l->p.speed;
	else if (l->i.state[8])
		l->p.y -= l->p.speed;
}

void	ft_event_map_editor_mode(variable_list* l)
{
	l->p.speed = 4;
	ft_event_map_editor_mode_motion(l);
	ft_event_map_editor_mode_moving(l);
	ft_event_map_editor_mode_moving_y(l);
	ft_event_map_editor_mode_select_on_click(l);
}

void	ft_events(variable_list* l)
{
	l->i.scroll_up = 0;
	l->i.scroll_down = 0;
	l->i.key_input = 0;
	SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
	while (SDL_PollEvent(&l->event))
	{
		if (l->event.type == SDL_MOUSEWHEEL)
		{
			if (l->event.wheel.y > 0)
			{
				l->i.scroll_up = 1;
			}
			else if (l->event.wheel.y < 0)
			{
				l->i.scroll_down = 1;
			}
		}
		if (l->event.key.state != 0)
			l->i.key_input = l->event.key.state;
	}
	l->i.state = SDL_GetKeyboardState(NULL);
	l->i.mouse = SDL_GetMouseState(&l->i.mouse_x, &l->i.mouse_y);
	ft_event_map_editor_mode_mouse_time_pressing_counter(l);

	if (l->i.state[SDL_SCANCODE_ESCAPE] || l->event.type == SDL_QUIT)
		ft_free_and_exit(l);

	if (l->writing_mode == 0)
	{
		if (l->menu_mode == 1)
			ft_event_playing_mode(l);
		else if (l->menu_mode == 2)
			ft_event_map_editor_mode(l);
		if (l->i.state[53])
		{
			l->i.state[53] = 0;
			if (l->menu_mode == 2)
			{
				l->menu_mode = 1;
				SDL_ShowCursor(SDL_DISABLE);
				SDL_WarpMouseInWindow(l->window, (WDW2), (WDH2));
				l->hl.live_bar = l->p.start_hp;
				l->hl.ammo = l->p.start_ammo;
				l->hl.item_state[0] = l->p.start_item[0];
				l->hl.item_state[1] = l->p.start_item[1];
				l->hl.item_state[2] = l->p.start_item[2];
				l->hl.item_state[3] = l->p.start_item[3];
				l->hl.item_state[4] = l->p.start_item[4];
				l->hl.item_state[5] = l->p.start_item[5];
				l->hl.item_state[6] = l->p.start_item[6];
				l->hl.item_state[7] = l->p.start_item[7];
				l->hl.item_state[8] = l->p.start_item[8];
			}
			else
			{
				l->menu_mode = 2;
				int i;
				i = -1;
				while (++i < l->triangle_number)
					if (l->t.texture_opacity[i] == 0)
						l->t.texture_opacity[i] = 100;
				SDL_ShowCursor(SDL_ENABLE);
			}
		}
	}
}
