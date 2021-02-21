#include "header.h"

void		ft_engine_play_calculate_me_opacity(variable_list* l, int i, int j)
{
	int area;

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

void		ft_engine_play_calculate_me(variable_list* l)
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
	ft_engine_play_calculate_me_opacity(l, i, j);
}

void		ft_engine_play_calculate_p_opacity(variable_list* l, int i, int j)
{
	int area;

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

void		ft_engine_play_calculate_p(variable_list* l)
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
	ft_engine_play_calculate_p_opacity(l, i, j);
}

void		ft_engine_play_calculate_pixels_initialize_part_1
(variable_list* l, s_engine_play_calculate_pixels_tmp* tmp)
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
	tmp->mx = (int)l->e.max_x;
	tmp->my = (int)l->e.max_y;
	tmp->p = l->pixels;
}
