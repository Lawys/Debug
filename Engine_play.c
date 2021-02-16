#include "header.h"

void	ft_engine_calculate_triangles_distance(variable_list* l)
{
	int i;
	int end;
	double* address[4];
	int* id;

	i = 0;
	end = l->triangle_number;
	address[0] = &l->e.t_d;
	address[1] = &l->e.t_z1;
	address[2] = &l->e.t_z2;
	address[3] = &l->e.t_z3;
	id = &l->e.t_id;
	while (i < end)
	{
		address[0][i] = address[1][i];
		if (address[2][i] > address[0][i])
			address[0][i] = address[2][i];
		if (address[3][i] > address[0][i])
			address[0][i] = address[3][i];
		id[i] = i;
		i++;
	}
}


void	ft_engine_set_x_y_z(variable_list* l, double* x, double* y, double* z)
{
	*x = l->e.xp * l->e.c_h + (l->e.zp) * l->e.s_h;
	*z = -l->e.xp * l->e.s_h + (l->e.zp) * l->e.c_h;
	*y = l->e.yp * l->e.c_v - (*z) * l->e.s_v;
	*z = l->e.yp * l->e.s_v + (*z) * l->e.c_v;
	*y *= -1;
}

void	ft_engine_set_angles_value(variable_list* l)
{
	l->e.c_h = cos(l->p.h);
	l->e.s_h = sin(l->p.h);
	l->e.c_v = cos(l->p.v);
	l->e.s_v = sin(l->p.v);
	l->e.c_l = cos(l->p.r);
	l->e.s_l = sin(l->p.r);
}

void	ft_engine_set_sprite_points(variable_list* l, engine_sprite_list* tmp, int ts)
{
	double x;
	double z;

	x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts] + (l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]))) / 4;
	z = l->t.z1[ts];
	tmp->angle = -l->p.h;
	tmp->cos = cos(tmp->angle);
	tmp->sin = sin(tmp->angle);

	tmp->x1 = (l->t.x1[ts] - x) * tmp->cos + (l->t.z1[ts] - z) * tmp->sin + x;
	tmp->z1 = -(l->t.x1[ts] - x) * tmp->sin + (l->t.z1[ts] - z) * tmp->cos + z;
	tmp->x2 = (l->t.x2[ts] - x) * tmp->cos + (l->t.z2[ts] - z) * tmp->sin + x;
	tmp->z2 = -(l->t.x2[ts] - x) * tmp->sin + (l->t.z2[ts] - z) * tmp->cos + z;
	tmp->x3 = (l->t.x3[ts] - x) * tmp->cos + (l->t.z3[ts] - z) * tmp->sin + x;
	tmp->z3 = -(l->t.x3[ts] - x) * tmp->sin + (l->t.z3[ts] - z) * tmp->cos + z;

	l->e.xp = tmp->x1 - l->p.x;
	l->e.yp = l->t.y1[ts] - l->p.y;
	l->e.zp = tmp->z1 - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x1[ts], &l->e.t_y1[ts], &l->e.t_z1[ts]);
	l->e.xp = tmp->x2 - l->p.x;
	l->e.yp = l->t.y2[ts] - l->p.y;
	l->e.zp = tmp->z2 - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x2[ts], &l->e.t_y2[ts], &l->e.t_z2[ts]);
	l->e.xp = tmp->x3 - l->p.x;
	l->e.yp = l->t.y3[ts] - l->p.y;
	l->e.zp = tmp->z3 - l->p.z;
	ft_engine_set_x_y_z(l, &l->e.t_x3[ts], &l->e.t_y3[ts], &l->e.t_z3[ts]);
}
void	ft_engine_sprite_struct_init(engine_sprite_list* tmp)
{
	int i;

	i = -1;
	while (++i < MAX_GROUPS)
	{
		tmp->init[i] = 0;
	}
}
void	ft_engine_set_triangles_points(variable_list* l)
{
	engine_sprite_list* tmp;
	int ts;
	int tn;

	if (!(tmp = malloc(sizeof(engine_sprite_list))))
		ft_free_and_exit(l);

	ft_engine_sprite_struct_init(tmp);
	tn = l->triangle_number;
	ts = -1;
	while (++ts < tn)
	{
		if (l->g.sprite[l->t.group[ts]] == 1 || l->g.npc[l->t.group[ts]] == 1)// || l->g.no_block[l->t.group[ts]] == 1)
			ft_engine_set_sprite_points(l, tmp, ts);
		else
		{
			l->e.xp = l->t.x1[ts] - l->p.x;
			l->e.yp = l->t.y1[ts] - l->p.y;
			l->e.zp = l->t.z1[ts] - l->p.z;
			ft_engine_set_x_y_z(l, &l->e.t_x1[ts], &l->e.t_y1[ts], &l->e.t_z1[ts]);
			l->e.xp = l->t.x2[ts] - l->p.x;
			l->e.yp = l->t.y2[ts] - l->p.y;
			l->e.zp = l->t.z2[ts] - l->p.z;
			ft_engine_set_x_y_z(l, &l->e.t_x2[ts], &l->e.t_y2[ts], &l->e.t_z2[ts]);
			l->e.xp = l->t.x3[ts] - l->p.x;
			l->e.yp = l->t.y3[ts] - l->p.y;
			l->e.zp = l->t.z3[ts] - l->p.z;
			ft_engine_set_x_y_z(l, &l->e.t_x3[ts], &l->e.t_y3[ts], &l->e.t_z3[ts]);
		}
	}
	free(tmp);
}

int	ft_engine_play_calculate_skip_triangles_behind_player(variable_list* l)
{
	int i;
	double* distance;

	distance = l->e.t_d;
	i = -1;
	while (distance[++i] < 1 && i < l->triangle_number)
		continue;
	return(i);
}

void	ft_engine_play_calculate_initialize_points_vectors_normals(variable_list* l)
{
	int ts;

	ts = l->e.t_s;
	l->e.tmp_z1 = l->e.t_z1[ts];
	l->e.tmp_z2 = l->e.t_z2[ts];
	l->e.tmp_z3 = l->e.t_z3[ts];
	l->e.tmp_x1 = l->e.t_x1[ts];
	l->e.tmp_x2 = l->e.t_x2[ts];
	l->e.tmp_x3 = l->e.t_x3[ts];
	l->e.tmp_y1 = l->e.t_y1[ts];
	l->e.tmp_y2 = l->e.t_y2[ts];
	l->e.tmp_y3 = l->e.t_y3[ts];
	l->e.v1x = l->e.tmp_x2 - l->e.tmp_x1;
	l->e.v2x = l->e.tmp_x3 - l->e.tmp_x1;
	l->e.v1y = l->e.tmp_y2 - l->e.tmp_y1;
	l->e.v2y = l->e.tmp_y3 - l->e.tmp_y1;
	l->e.v1z = l->e.tmp_z2 - l->e.tmp_z1;
	l->e.v2z = l->e.tmp_z3 - l->e.tmp_z1;
	l->e.nx = l->e.v1y * l->e.v2z - l->e.v1z * l->e.v2y;
	l->e.ny = l->e.v1z * l->e.v2x - l->e.v1x * l->e.v2z;
	l->e.nz = l->e.v1x * l->e.v2y - l->e.v1y * l->e.v2x;
	l->e.t_normal = (l->e.tmp_y1 * l->e.ny + l->e.tmp_x1 * l->e.nx + l->e.tmp_z1 * l->e.nz);
}
void	ft_engine_play_calculate_points_to_front_reference_1(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x1[ts];
	y = l->e.t_y1[ts];
	z = l->e.t_z1[ts];
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y1 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x1 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z1 = 1;
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 1;
}
void	ft_engine_play_calculate_points_to_front_reference_2(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x2[ts];
	y = l->e.t_y2[ts];
	z = l->e.t_z2[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y2 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x2 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z2 = 1;
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 2;
}
void	ft_engine_play_calculate_points_to_front_reference_3(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x3[ts];
	y = l->e.t_y3[ts];
	z = l->e.t_z3[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y3 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x3 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z3 = 1;
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y4 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x4 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z4 = 1;
	l->e.ref = 3;
}
void	ft_engine_play_calculate_points_to_front_no_reference_1(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x1[ts];
	y = l->e.t_y1[ts];
	z = l->e.t_z1[ts];
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y1 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x1 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z1 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference_2(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x1[ts];
	y = l->e.t_y1[ts];
	z = l->e.t_z1[ts];
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y1 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x1 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z1 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference_3(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x2[ts];
	y = l->e.t_y2[ts];
	z = l->e.t_z2[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y2 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x2 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z2 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference_4(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x2[ts];
	y = l->e.t_y2[ts];
	z = l->e.t_z2[ts];
	t = (z - 1) / -(l->e.t_z3[ts] - z);
	l->e.tmp_y2 = y + (l->e.t_y3[ts] - y) * t;
	l->e.tmp_x2 = x + (l->e.t_x3[ts] - x) * t;
	l->e.tmp_z2 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference_5(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x3[ts];
	y = l->e.t_y3[ts];
	z = l->e.t_z3[ts];
	t = (z - 1) / -(l->e.t_z1[ts] - z);
	l->e.tmp_y3 = y + (l->e.t_y1[ts] - y) * t;
	l->e.tmp_x3 = x + (l->e.t_x1[ts] - x) * t;
	l->e.tmp_z3 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference_6(variable_list* l)
{
	double t;
	double x;
	double y;
	double z;
	int ts;

	ts = l->e.t_s;
	x = l->e.t_x3[ts];
	y = l->e.t_y3[ts];
	z = l->e.t_z3[ts];
	t = (z - 1) / -(l->e.t_z2[ts] - z);
	l->e.tmp_y3 = y + (l->e.t_y2[ts] - y) * t;
	l->e.tmp_x3 = x + (l->e.t_x2[ts] - x) * t;
	l->e.tmp_z3 = 1;
}
void	ft_engine_play_calculate_points_to_front_no_reference(variable_list* l)
{
	int ts;
	double z1;
	double z2;
	double z3;

	ts = l->e.t_s;
	z1 = l->e.t_z1[ts];
	z2 = l->e.t_z2[ts];
	z3 = l->e.t_z3[ts];
	if (z1 < 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_1(l);
	else if (z1 < 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_2(l);
	if (z2 < 1 && z1 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_3(l);
	else if (z2 < 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_4(l);
	if (z3 < 1 && z1 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_5(l);
	else if (z3 < 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_no_reference_6(l);
}
void	ft_engine_play_calculate_points_to_front(variable_list* l)
{
	int ts;
	double z1;
	double z2;
	double z3;

	ts = l->e.t_s;
	z1 = l->e.t_z1[ts];
	z2 = l->e.t_z2[ts];
	z3 = l->e.t_z3[ts];
	if (z1 < 1 && z2 >= 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_reference_1(l);
	else if (z2 < 1 && z1 >= 1 && z3 >= 1)
		ft_engine_play_calculate_points_to_front_reference_2(l);
	else if (z3 < 1 && z1 >= 1 && z2 >= 1)
		ft_engine_play_calculate_points_to_front_reference_3(l);
	else
		ft_engine_play_calculate_points_to_front_no_reference(l);
}
void	ft_engine_play_calculate_pixel_points(variable_list* l)
{
	double t;

	t = -l->e.view_distance / -l->e.tmp_z1;
	l->e.p_y1 = l->e.tmp_y1 * t + WDH2;
	l->e.p_x1 = l->e.tmp_x1 * t + WDW2;
	t = -l->e.view_distance / -l->e.tmp_z2;
	l->e.p_y2 = l->e.tmp_y2 * t + WDH2;
	l->e.p_x2 = l->e.tmp_x2 * t + WDW2;
	t = -l->e.view_distance / -l->e.tmp_z3;
	l->e.p_y3 = l->e.tmp_y3 * t + WDH2;
	l->e.p_x3 = l->e.tmp_x3 * t + WDW2;
	l->e.min_x = l->e.p_x1;
	if (l->e.p_x2 < l->e.min_x)
		l->e.min_x = l->e.p_x2;
	if (l->e.p_x3 < l->e.min_x)
		l->e.min_x = l->e.p_x3;
	l->e.max_x = l->e.p_x1;
	if (l->e.p_x2 > l->e.max_x)
		l->e.max_x = l->e.p_x2;
	if (l->e.p_x3 > l->e.max_x)
		l->e.max_x = l->e.p_x3;
}
void	ft_engine_play_calculate_pixel_points_p4(variable_list* l)
{
	double t;
	double* min_x;
	double* max_x;
	double x4;

	t = -l->e.view_distance / -l->e.tmp_z4;
	l->e.p_y4 = l->e.tmp_y4 * t;
	l->e.p_x4 = l->e.tmp_x4 * t;
	l->e.p_x4 += WDW2;
	l->e.p_y4 += WDH2;
	min_x = &l->e.min_x;
	max_x = &l->e.max_x;
	x4 = l->e.p_x4;
	if (x4 < *min_x)
		*min_x = x4;
	if (x4 > *max_x)
		*max_x = x4;
}

void	ft_engine_play_calculate_triangle_line_1_2(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x2;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y2;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_line_1_3(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x3;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y3;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_line_2_3(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x2;
	x[1] = l->e.p_x3;
	y[0] = l->e.p_y2;
	y[1] = l->e.p_y3;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_line_1_4(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x1;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y1;
	y[1] = l->e.p_y4;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_line_2_4(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x2;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y2;
	y[1] = l->e.p_y4;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_line_3_4(variable_list* l, int i, double* first_y, double* last_y)
{
	double x[2];
	double y[2];
	double t;
	double v;

	x[0] = l->e.p_x3;
	x[1] = l->e.p_x4;
	y[0] = l->e.p_y3;
	y[1] = l->e.p_y4;
	t = (x[0] - i) / -(x[1] - x[0]);
	v = y[0] + (y[1] - y[0]) * t;
	if (t >= 0 && t <= 1)
	{
		if (v < *first_y)
			*first_y = v;
		if (v > *last_y)
			*last_y = v;
	}
}
void	ft_engine_play_calculate_triangle_limits_no_reference(variable_list* l)
{
	int x;
	double max_x;
	double* first_y;
	double* last_y;
	int check;

	x = l->e.min_x - 1.;
	max_x = l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;
	check = 0;
	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_1_3(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_2_3(l, x, &first_y[x], &last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1 + 0.0;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
		if (first_y[x] < WDH)
			check = 1;
	}
}
void	ft_engine_play_calculate_triangle_limits_reference_1(variable_list* l)
{
	int x;
	int max_x;
	double* first_y;
	double* last_y;

	x = l->e.min_x - 1;
	max_x = l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;

	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_2_3(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_3_4(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_1_4(l, x, &first_y[x], &last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
	}
}
void	ft_engine_play_calculate_triangle_limits_reference_2(variable_list* l)
{
	int x;
	double max_x;
	double* first_y;
	double* last_y;

	x = l->e.min_x - 1.;
	max_x = l->e.max_x;
	first_y = l->e.first_y;
	last_y = l->e.last_y;
	while (++x <= max_x)
	{
		ft_engine_play_calculate_triangle_line_1_2(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_1_3(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_3_4(l, x, &first_y[x], &last_y[x]);
		ft_engine_play_calculate_triangle_line_2_4(l, x, &first_y[x], &last_y[x]);
		if (first_y[x] < 0)
			first_y[x] = -1;
		if (last_y[x] >= WDH)
			last_y[x] = WDH - 1.;
	}
}

void	ft_engine_play_calculate_if_appear(variable_list* l)
{
	l->e.ref = 0;
	ft_engine_play_calculate_points_to_front(l);
	ft_engine_play_calculate_pixel_points(l);
	if (l->e.ref > 0)
		ft_engine_play_calculate_pixel_points_p4(l);
	if (l->e.min_x < 0)
		l->e.min_x = 0;
	if (l->e.max_x >= WDW)
		l->e.max_x = WDW - 1.;
	//if (l->e.min_x >= WDW || l->e.max_x < 0)
		//return;
	if (l->e.ref == 0)
		ft_engine_play_calculate_triangle_limits_no_reference(l);
	else if (l->e.ref == 1)
		ft_engine_play_calculate_triangle_limits_reference_1(l);
	else if (l->e.ref > 1)
		ft_engine_play_calculate_triangle_limits_reference_2(l);


}

void	ft_engine_play_calculate_me(variable_list* l)
{
	int i;
	int j;
	int area;

	j = ft_engine_play_calculate_skip_triangles_behind_player(l);
	i = j - 1;
	while (++i < l->triangle_number)
	{
		l->e.t_s = l->e.t_id[i];
		area = l->t.area[l->e.t_s];
		if ((area == 0 || l->view_only == 0 || area == l->view_only) &&
			l->g.exist[l->t.group[l->e.t_s]] &&
			l->t.texture_opacity[l->e.t_s] == 100)
			{
				ft_engine_play_calculate_initialize_points_vectors_normals(l);
				if (l->t.texture_sides[l->e.t_s] == 1 && l->e.t_normal < 0 ||
					(l->t.texture_sides[l->e.t_s] == -1 && l->e.t_normal > 0) ||
					l->t.texture_sides[l->e.t_s] == 0)
				{
					ft_engine_play_calculate_if_appear(l);
					ft_engine_play_calculate_pixels(l);
				}
			}
	}
	while (--i >= j)
	{
		l->e.t_s = l->e.t_id[i];
		area = l->t.area[l->e.t_s];
		if (l->t.texture_opacity[l->e.t_s] < 100 &&
			(area == 0 || l->view_only == 0 || area == l->view_only) &&
			l->g.exist[l->t.group[l->e.t_s]])
		{
			ft_engine_play_calculate_initialize_points_vectors_normals(l);
			if (l->t.texture_sides[l->e.t_s] == 1 && l->e.t_normal < 0 ||
				(l->t.texture_sides[l->e.t_s] == -1 && l->e.t_normal > 0) ||
				l->t.texture_sides[l->e.t_s] == 0)
			{
				ft_engine_play_calculate_if_appear(l);
				ft_engine_play_calculate_pixels_opacity(l);
			}
		}
	}
}

void	ft_engine_play_calculate_p(variable_list* l)
{
	int i;
	int j;
	int area;

	j = ft_engine_play_calculate_skip_triangles_behind_player(l);
	i = j - 1;
	while (++i < l->triangle_number)
	{
		l->e.t_s = l->e.t_id[i];
		area = l->t.area[l->e.t_s];
		if ((area == 0 || l->player_area == area ||
			l->link1[l->player_area] == area ||
			l->link2[l->player_area] == area ||
			l->link3[l->player_area] == area ||
			l->link4[l->player_area] == area ||
			l->link5[l->player_area] == area ||
			l->link6[l->player_area] == area) &&
			l->g.exist[l->t.group[l->e.t_s]] &&
			l->t.texture_opacity[l->e.t_s] == 100)
		{
			ft_engine_play_calculate_initialize_points_vectors_normals(l);
			if (l->t.texture_sides[l->e.t_s] == 1 && l->e.t_normal < 0 ||
				(l->t.texture_sides[l->e.t_s] == -1 && l->e.t_normal > 0) ||
				l->t.texture_sides[l->e.t_s] == 0)
			{
				ft_engine_play_calculate_if_appear(l);
				ft_engine_play_calculate_pixels(l);
			}
		}
	}
	while (--i >= j)
	{
		l->e.t_s = l->e.t_id[i];
		area = l->t.area[l->e.t_s];
		if (l->t.texture_opacity[l->e.t_s] < 100 &&
			(area == 0 || l->player_area == area ||
			l->link1[l->player_area] == area ||
			l->link2[l->player_area] == area ||
			l->link3[l->player_area] == area ||
			l->link4[l->player_area] == area ||
			l->link5[l->player_area] == area ||
			l->link6[l->player_area] == area) &&
			l->g.exist[l->t.group[l->e.t_s]])
		{
			ft_engine_play_calculate_initialize_points_vectors_normals(l);
			if (l->t.texture_sides[l->e.t_s] == 1 && l->e.t_normal < 0 ||
				(l->t.texture_sides[l->e.t_s] == -1 && l->e.t_normal > 0) ||
				l->t.texture_sides[l->e.t_s] == 0)
			{
				ft_engine_play_calculate_if_appear(l);
				ft_engine_play_calculate_pixels_opacity(l);
			}
		}
	}
}


void	ft_engine_play_calculate_pixels_initialize_part_1(variable_list* l, s_engine_play_calculate_pixels_tmp* tmp)
{
	tmp->t_s = l->e.t_s;
	tmp->t_n = l->e.t_normal;
	tmp->vd = l->e.view_distance;
	tmp->nx = l->e.nx;
	tmp->ny = l->e.ny;
	tmp->nz = l->e.nz;
	tmp->v1x = l->e.v1x;
	tmp->v1y = l->e.v1y;
	tmp->v1z = l->e.v1z;
	tmp->fy = l->e.first_y;
	tmp->ly = l->e.last_y;
	tmp->mx = l->e.max_x;
	tmp->my = l->e.max_y;
	tmp->p = l->pixels;
}
void	ft_engine_play_calculate_pixels_initialize_part_2(variable_list* l, s_engine_play_calculate_pixels_tmp* tmp)
{
	int ts;

	ts = tmp->t_s;
	tmp->nzvd = tmp->vd * tmp->nz;
	tmp->l = l->t.texture_light[ts] / 100.;
	tmp->v4x = (tmp->v1y * tmp->nz - tmp->ny * tmp->v1z);
	tmp->v4y = (tmp->v1z * tmp->nx - tmp->nz * tmp->v1x);
	tmp->v4z = (tmp->v1x * tmp->ny - tmp->nx * tmp->v1y);
	tmp->d01 = sqrt(tmp->v1x * tmp->v1x + tmp->v1y * tmp->v1y + tmp->v1z * tmp->v1z);
	tmp->d04 = sqrt(tmp->v4x * tmp->v4x + tmp->v4y * tmp->v4y + tmp->v4z * tmp->v4z);
	tmp->t_x1 = l->e.t_x1[ts];
	tmp->t_y1 = l->e.t_y1[ts];
	tmp->t_z1 = l->e.t_z1[ts];
	tmp->c = l->texture_colors[(int)l->t.texture_id[ts]];
	tmp->ttsix = l->t.texture_size_x[ts] / 100;
	tmp->ttshx = l->t.texture_shift_x[ts] * 10.24;
	tmp->ttsiy = l->t.texture_size_y[ts] / 100;
	tmp->ttshy = l->t.texture_shift_y[ts] * 10.24;
	tmp->o = l->t.texture_opacity[ts] / 100;
}
void	ft_engine_play_calculate_pixels_initialize_part_3(variable_list* l, s_engine_play_calculate_pixels_tmp* tmp)
{
	int ts;
	double center;

	ts = tmp->t_s;
	if (l->g.npc[l->t.group[ts]] == 1)
	{
		center = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts] + (l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]))) / 4;
		tmp->s = -atan2(center - l->p.x, l->t.z1[ts] - l->p.z);
		tmp->s = ((int)((tmp->s / M_PI * 180 - 202.5 + l->g.sprite_orientation[l->t.group[ts]]) / 45) * 128.);
		tmp->ss = -l->g.npc_statement[l->t.group[ts]] * 132;
	}
	else
	{
		tmp->s = 0;
		tmp->ss = 0;
	}
}

void	ft_engine_play_calculate_pixels_while_y(variable_list* l, s_engine_play_calculate_pixels_tmp* s)
{
	while (++s->y <= s->my)
	{
		s->t_d = s->t_n / -(((double)s->y - WDH2) * s->ny +
			((double)s->x - WDW2) * s->nx + s->nzvd);
		s->c_x = ((double)s->x - WDW2) * s->t_d;
		s->c_y = ((double)s->y - WDH2) * s->t_d;
		s->c_z = s->vd * s->t_d;
		s->t_d = sqrt(s->c_x * s->c_x + s->c_y * s->c_y + s->c_z * s->c_z);
		if (s->t_d <= l->pixels_distance[s->x][s->y])
		{
			s->v = (((abs((((s->v4x * (s->c_x + s->t_x1) + s->v4y * (s->c_y +
				s->t_y1) + s->v4z * (s->c_z + s->t_z1)) / s->d04) * 10.24) *
				s->ttsiy + s->ttshy) + (int)s->s) & 1023) + ((abs((((
					s->v1x * (s->c_x + s->t_x1) + s->v1y * (s->c_y + s->t_y1) +
					s->v1z * (s->c_z + s->t_z1)) / s->d01) * 10.24) * s->ttsix -
					s->ttshx) + s->ss) & 1023) * 1024) * 4 + 138;
			if (s->c[s->v + 3] != 0)
			{
				l->pixels_distance[s->x][s->y] = s->t_d;
				l->pixels_triangle[s->x][s->y] = s->t_s;
				l->pixels_color[s->x][s->y] = (int)(s->l * s->c[s->v]) + (int)(s->l * s->c[s->v
					+ 1]) * 256 + (int)(s->l * s->c[s->v + 2]) * 65536;
			}
		}
	}
}

void	ft_engine_play_calculate_pixels(variable_list* l)
{
	s_engine_play_calculate_pixels_tmp tmp;
	int i;

	ft_engine_play_calculate_pixels_initialize_part_1(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_2(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_3(l, &tmp);
	tmp.t_d = -1;
	tmp.x = l->e.min_x - 1;
	while (++tmp.x <= tmp.mx)
	{
		tmp.y = tmp.fy[tmp.x];
		tmp.my = tmp.ly[tmp.x];
		ft_engine_play_calculate_pixels_while_y(l, &tmp);
		tmp.fy[tmp.x] = WDH;
		tmp.ly[tmp.x] = -1;
	}
}

void	ft_engine_play_calculate_pixels_while_y_opacity_color(variable_list* l, s_engine_play_calculate_pixels_tmp* s)
{
	l->pixels_distance[s->x][s->y] = s->t_d;
	l->pixels_triangle[s->x][s->y] = s->t_s;
	l->pixels_color[s->x][s->y] =
		(int)(s->l * s->c[s->v] * s->o) + (int)((l->pixels_color[s->x][s->y] & 0xff) * (1 - s->o)) +
		((int)(s->l * s->c[s->v + 1] * s->o) + (int)(((l->pixels_color[s->x][s->y] >> 8) & 0xff) * (1 - s->o))) * 256 +
		((int)(s->l * s->c[s->v + 2] * s->o) + (int)(((l->pixels_color[s->x][s->y] >> 16) & 0xff) * (1 - s->o))) * 65536;
}

void	ft_engine_play_calculate_pixels_while_y_opacity(variable_list* l, s_engine_play_calculate_pixels_tmp* s)
{
	while (++s->y <= s->my)
	{
		s->t_d = s->t_n / -(((double)s->y - WDH2) * s->ny +
			((double)s->x - WDW2) * s->nx + s->nzvd);
		s->c_x = ((double)s->x - WDW2) * s->t_d;
		s->c_y = ((double)s->y - WDH2) * s->t_d;
		s->c_z = s->vd * s->t_d;
		s->t_d = sqrt(s->c_x * s->c_x + s->c_y * s->c_y + s->c_z * s->c_z);
		if (s->t_d <= l->pixels_distance[s->x][s->y])
		{
			s->v = (((abs((((s->v4x * (s->c_x + s->t_x1) + s->v4y * (s->c_y +
				s->t_y1) + s->v4z * (s->c_z + s->t_z1)) / s->d04) * 10.24) *
				s->ttsiy + s->ttshy) + (int)s->s) & 1023) + ((abs((((
					s->v1x * (s->c_x + s->t_x1) + s->v1y * (s->c_y + s->t_y1) +
					s->v1z * (s->c_z + s->t_z1)) / s->d01) * 10.24) * s->ttsix -
					s->ttshx) + s->ss) & 1023) * 1024) * 4 + 138;
			if (s->c[s->v + 3] != 0)
				ft_engine_play_calculate_pixels_while_y_opacity_color(l, s);
		}
	}
}

void	ft_engine_play_calculate_pixels_opacity(variable_list* l)
{
	s_engine_play_calculate_pixels_tmp tmp;
	int i;

	ft_engine_play_calculate_pixels_initialize_part_1(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_2(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_3(l, &tmp);
	tmp.t_d = -1;
	tmp.x = l->e.min_x - 1;
	while (++tmp.x <= tmp.mx)
	{
		tmp.y = tmp.fy[tmp.x];
		tmp.my = tmp.ly[tmp.x];
		ft_engine_play_calculate_pixels_while_y_opacity(l, &tmp);
		tmp.fy[tmp.x] = WDH;
		tmp.ly[tmp.x] = -1;
	}
}

 void	ft_engine_play_p(variable_list* l)
{
	ft_engine_set_angles_value(l);
	ft_engine_set_triangles_points(l);
	ft_engine_calculate_triangles_distance(l);
	ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	ft_engine_play_calculate_p(l);
	l->pixels_color[WDW2][WDH2] = 0x00FF00;
}

 void	ft_engine_play_me(variable_list* l)
 {
	 ft_engine_set_angles_value(l);
	 ft_engine_set_triangles_points(l);
	 ft_engine_calculate_triangles_distance(l);
	 ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	 ft_engine_play_calculate_me(l);
	 l->pixels_color[WDW2][WDH2] = 0x00FF00;
 }