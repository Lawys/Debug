#include "header.h"

void		ft_engine_play_calculate_pixels_while_y_opacity
(variable_list* l, s_engine_play_calculate_pixels_tmp* s)
{
	while (++s->y <= s->my)
	{
		s->t_d = s->t_n / -(((double)s->y - WDH2) * s->ny +
			((double)s->x - WDW2) * s->nx + s->nzvd);
		s->c_x = ((double)s->x - WDW2) * s->t_d;
		s->c_y = ((double)s->y - WDH2) * s->t_d;
		s->c_z = s->vd * s->t_d;
		s->t_d = sqrt(s->c_x * s->c_x + s->c_y * s->c_y + s->c_z * s->c_z);
		if (s->t_d <= l->pixels_distance[s->x][s->y] ||
			l->t.texture_opacity[l->pixels_triangle[s->x][s->y]] < 100) //move skybox IMPORTANT
		{
			s->v = ((((int)fabs((((s->v4x * (s->c_x + s->t_x1) + s->v4y * (s->c_y +
				s->t_y1) + s->v4z * (s->c_z + s->t_z1)) / s->d04) * 10.24) *
				s->ttsiy + s->ttshy) + (int)s->s) & 1023) + (((int)fabs((((
					s->v1x * (s->c_x + s->t_x1) + s->v1y * (s->c_y + s->t_y1) +
					s->v1z * (s->c_z + s->t_z1)) / s->d01) * 10.24) * s->ttsix -
					s->ttshx) + s->ss) & 1023) * 1024) * 4;
			if (s->c[s->v + 3] != 0)
				ft_engine_play_calculate_pixels_while_y_opacity_color(l, s);
		}
	}
}

void		ft_engine_play_calculate_pixels_opacity(variable_list* l)
{
	s_engine_play_calculate_pixels_tmp tmp;

	ft_engine_play_calculate_pixels_initialize_part_1(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_2(l, &tmp);
	ft_engine_play_calculate_pixels_initialize_part_3(l, &tmp);
	tmp.t_d = -1;
	tmp.x = (int)(l->e.min_x - 1);
	while (++tmp.x <= tmp.mx)
	{
		tmp.y = (int)tmp.fy[tmp.x];
		tmp.my = (int)tmp.ly[tmp.x];
		ft_engine_play_calculate_pixels_while_y_opacity(l, &tmp);
		tmp.fy[tmp.x] = WDH;
		tmp.ly[tmp.x] = -1;
	}
}

void		ft_engine_play_p(variable_list* l)
{
	ft_engine_set_angles_value(l);
	ft_engine_set_triangles_points(l);
	ft_engine_calculate_triangles_distance(l);
	ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	ft_engine_play_calculate_p(l);
	l->pixels_color[WDW2][WDH2] = 0x00FF00;
}

void		ft_engine_play_me(variable_list* l)
{
	ft_engine_set_angles_value(l);
	ft_engine_set_triangles_points(l);
	ft_engine_calculate_triangles_distance(l);
	ft_quick_sort(l->e.t_id, l->e.t_d, l->triangle_number);
	ft_engine_play_calculate_me(l);
	l->pixels_color[WDW2][WDH2] = 0x00FF00;
}
