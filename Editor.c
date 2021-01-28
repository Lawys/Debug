#include "header.h"
void	ft_map_editor_tool_set_mult(variable_list* l)
{
	l->me.mult = 100;
	if (l->i.state[225])
		l->me.mult = 1000;
	else if (l->i.state[224])
		l->me.mult = 10000;
	if (l->i.state[226])
		l->me.mult = 1;
		
}
void	ft_map_editor_menu_background(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 1600;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 2.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);
}
void	ft_map_editor_submenu_background(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 820;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 34.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);
}


/*
void	ft_map_editor_paint_initialize(variable_list* l)
{
	l->triangle_select = -1;
	l->area_select = -1;
	l->group_select = -1;
	l->light_select = -1;
}

void	ft_map_editor_paint_parameters(variable_list* l)
{
	ft_map_editor_submenu_background(l);
}

void	ft_map_editor_paint_actions(variable_list* l)
{

}

void	ft_map_editor_paint(variable_list* l)
{
	if (l->action_select[0][7] == 2 && l->triangle_select != -1)
	{
		l->u.action = 0;
		l->action = 0;
		l->menu_select = 1;
		ft_map_editor_paint_parameters(l);
		ft_map_editor_paint_actions(l);
	}
	else if (l->action_select[0][7] == 1)
	{
		ft_map_editor_paint_initialize(l);
		l->action_select[0][7]++;
	}
}

void	ft_map_editor_action_light_initialize(variable_list* l)
{
	l->area_select = -1;
	l->group_select = -1;
	l->triangle_select = -1;
	if (l->light_select == -1)
		l->light_select = 0;
}

void	ft_map_editor_light(variable_list* l)
{
	ft_map_editor_action_light_initialize(l);
	ft_map_editor_action_select_4_put_texture_1(l);
	ft_map_editor_action_select_4_put_text_1(l);
	ft_map_editor_action_select_4_put_text_2(l);
	ft_map_editor_action_select_4_put_text_3(l);
	ft_map_editor_action_select_4_put_text_4(l);
	ft_map_editor_action_select_4_put_text_5(l);
	ft_map_editor_action_select_4_put_text_6(l);
	ft_map_editor_action_select_4_put_text_7(l);
}

void	ft_map_editor_action_check_free_area(variable_list* l)
{
	int i;

	l->me.new_area = 0;
	while (l->me.new_area < MAX_AREAS)
	{
		i = 0;
		while (i < l->triangle_number)
		{
			if (l->t.area[i] == l->me.new_area)
				break;
			i++;
		}
		if (i == l->triangle_number)
			break;
		l->me.new_area++;
	}
}



void	ft_map_editor_main_action_duplicate_triangle(variable_list* l)
{
	int tn;
	int ts;

	tn = l->triangle_number++;
	ts = l->triangle_select;
	l->t.area[tn] = l->t.area[ts];
	l->t.group[tn] = l->t.group[ts];
	l->t.x1[tn] = l->t.x1[ts];
	l->t.y1[tn] = l->t.y1[ts];
	l->t.z1[tn] = l->t.z1[ts];
	l->t.x2[tn] = l->t.x2[ts];
	l->t.y2[tn] = l->t.y2[ts];
	l->t.z2[tn] = l->t.z2[ts];
	l->t.x3[tn] = l->t.x3[ts];
	l->t.y3[tn] = l->t.y3[ts];
	l->t.z3[tn] = l->t.z3[ts];
	l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
	l->t.texture_light[tn] = l->t.texture_light[ts];
	l->t.texture_shift_x[tn] = l->t.texture_shift_x[ts];
	l->t.texture_shift_y[tn] = l->t.texture_shift_y[ts];
	l->t.texture_id[tn] = l->t.texture_id[ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
	l->t.texture_sides[tn] = l->t.texture_sides[ts];
	l->triangle_select = tn;
}

void	ft_map_editor_main_action_duplicate_area_list_groups
		(variable_list* l, int *end_group_list)
{
	int i;
	int j;

	i = -1;
	while (++i < l->triangle_number)
		l->me.groups[i] = -1;
	i = -1;
	*end_group_list = 0;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			j = -1;
			while (++j < l->triangle_number)
				if (l->me.groups[j] == l->t.group[i])
					break;
			if (j == l->triangle_number)
				l->me.groups[(*end_group_list)++] = l->t.group[i];
		}
}

void	ft_map_editor_main_action_duplicate_area(variable_list* l)
{
	int i;
	int end_group_list;

	ft_map_editor_action_check_free_area(l);
	if (l->me.new_area == MAX_AREAS)
		return;
	ft_map_editor_main_action_duplicate_area_list_groups
	(l, &end_group_list);
	i = -1;
	while (++i < end_group_list)
	{
		l->group_select = l->me.groups[i];

		ft_map_editor_main_action_duplicate_group_triangles(l);
		ft_map_editor_main_action_duplicate_group_lights(l);
	}
	l->group_select = -1;
	l->area_select = l->me.new_area;
}

void	ft_map_editor_main_action_duplicate_group_triangles_values
		(variable_list* l, int tn, int i)
{
	l->t.area[tn] = l->me.new_area;
	l->t.group[tn] = l->me.new_group;
	l->t.x1[tn] = l->t.x1[i];
	l->t.y1[tn] = l->t.y1[i];
	l->t.z1[tn] = l->t.z1[i];
	l->t.x2[tn] = l->t.x2[i];
	l->t.y2[tn] = l->t.y2[i];
	l->t.z2[tn] = l->t.z2[i];
	l->t.x3[tn] = l->t.x3[i];
	l->t.y3[tn] = l->t.y3[i];
	l->t.z3[tn] = l->t.z3[i];
	l->t.texture_size_x[tn] = l->t.texture_size_x[i];
	l->t.texture_size_y[tn] = l->t.texture_size_y[i];
	l->t.texture_light[tn] = l->t.texture_light[i];
	l->t.texture_shift_x[tn] = l->t.texture_shift_x[i];
	l->t.texture_shift_y[tn] = l->t.texture_shift_y[i];
	l->t.texture_id[tn] = l->t.texture_id[i];
	l->t.texture_opacity[tn] = l->t.texture_opacity[i];
	l->t.texture_sides[tn] = l->t.texture_sides[i];
}

void	ft_map_editor_main_action_duplicate_group_triangles
		(variable_list* l)
{
	int i;
	int end;
	int	tn;

	tn = l->triangle_number;
	end = tn;
	i = -1;
	while (++i < end)
	{
		if (tn == MAX_TRIANGLES)
		{
			l->triangle_number = tn - 1;
			return;
		}
		if (l->t.group[i] == l->group_select)
			ft_map_editor_main_action_duplicate_group_triangles_values
			(l, tn++, i);
	}
	l->triangle_number = tn;
}

void	ft_map_editor_main_action_duplicate_group_lights(variable_list* l)
{
	int i;
	int ln;
	int end;

	ln = l->light_number;
	end = ln;
	i = 0;
	while (i < ln)
	{
		if (l->light_group[i] == l->group_select)
		{
			l->light_area[ln] = l->me.new_area;
			l->light_group[ln] = l->me.new_group;
			l->light_x[ln] = l->light_x[i];
			l->light_y[ln] = l->light_y[i];
			l->light_z[ln] = l->light_z[i];
			l->light_range[ln] = l->light_range[i];
			l->light_number++;
		}
		i++;
	}
}

void	ft_map_editor_main_action_duplicate_group(variable_list* l)
{
	ft_map_editor_action_check_free_area(l);
	if (l->me.new_area == MAX_AREAS)
		return;

	ft_map_editor_main_action_duplicate_group_triangles(l);
	ft_map_editor_main_action_duplicate_group_lights(l);
	l->group_select = l->me.new_group;
}
void	ft_map_editor_main_action_duplicate_light(variable_list* l)
{
	l->light_area[l->light_number] = l->light_area[(int)l->light_select];
	l->light_group[l->light_number] = l->light_group[(int)l->light_select];
	l->light_x[l->light_number] = l->light_x[(int)l->light_select];
	l->light_y[l->light_number] = l->light_y[(int)l->light_select];
	l->light_z[l->light_number] = l->light_z[(int)l->light_select];
	l->light_range[l->light_number] = l->light_range[(int)l->light_select];
	l->light_select = l->light_number;
	l->light_number++;
}

void	ft_map_editor_main_action_duplicate_selection(variable_list* l)
{

	{
		if (l->triangle_select != -1)
		{
			ft_map_editor_main_action_duplicate_triangle(l);
			if (l->triangle_number == MAX_TRIANGLES)
				l->triangle_number--;
		}
		else if (l->area_select != -1)
			ft_map_editor_main_action_duplicate_area(l);
		else if (l->group_select != -1)
			ft_map_editor_main_action_duplicate_group(l);
		else if (l->light_select != -1)
			ft_map_editor_main_action_duplicate_light(l);
	}
}

void	ft_map_editor_main_action_delete_selection_triangle(variable_list* l)
{
	--l->triangle_number;
	l->t.area[l->triangle_select] = l->t.area[l->triangle_number];
	l->t.group[l->triangle_select] = l->t.group[l->triangle_number];
	l->t.x1[l->triangle_select] = l->t.x1[l->triangle_number];
	l->t.y1[l->triangle_select] = l->t.y1[l->triangle_number];
	l->t.z1[l->triangle_select] = l->t.z1[l->triangle_number];
	l->t.x2[l->triangle_select] = l->t.x2[l->triangle_number];
	l->t.y2[l->triangle_select] = l->t.y2[l->triangle_number];
	l->t.z2[l->triangle_select] = l->t.z2[l->triangle_number];
	l->t.x3[l->triangle_select] = l->t.x3[l->triangle_number];
	l->t.y3[l->triangle_select] = l->t.y3[l->triangle_number];
	l->t.z3[l->triangle_select] = l->t.z3[l->triangle_number];
	l->t.texture_size_x[l->triangle_select] = l->t.texture_size_x[l->triangle_number];
	l->t.texture_size_y[l->triangle_select] = l->t.texture_size_y[l->triangle_number];
	l->t.texture_light[l->triangle_select] = l->t.texture_light[l->triangle_number];
	l->t.texture_shift_x[l->triangle_select] = l->t.texture_shift_x[l->triangle_number];
	l->t.texture_shift_y[l->triangle_select] = l->t.texture_shift_y[l->triangle_number];
	l->t.texture_id[l->triangle_select] = l->t.texture_id[l->triangle_number];
	l->t.texture_opacity[l->triangle_select] = l->t.texture_opacity[l->triangle_number];
	l->t.texture_sides[l->triangle_select] = l->t.texture_sides[l->triangle_number];
	l->triangle_select = -1;
}

void	ft_map_editor_main_action_delete_selection_area(variable_list* l)
{
	l->me.i = 0;
	while (l->me.i < l->triangle_number)
	{
		if (l->t.area[l->me.i] == l->area_select)
		{
			l->triangle_number--;
			l->t.area[l->me.i] = l->t.area[l->triangle_number];
			l->t.group[l->me.i] = l->t.group[l->triangle_number];
			l->t.x1[l->me.i] = l->t.x1[l->triangle_number];
			l->t.y1[l->me.i] = l->t.y1[l->triangle_number];
			l->t.z1[l->me.i] = l->t.z1[l->triangle_number];
			l->t.x2[l->me.i] = l->t.x2[l->triangle_number];
			l->t.y2[l->me.i] = l->t.y2[l->triangle_number];
			l->t.z2[l->me.i] = l->t.z2[l->triangle_number];
			l->t.x3[l->me.i] = l->t.x3[l->triangle_number];
			l->t.y3[l->me.i] = l->t.y3[l->triangle_number];
			l->t.z3[l->me.i] = l->t.z3[l->triangle_number];
			l->t.texture_size_x[l->me.i] = l->t.texture_size_x[l->triangle_number];
			l->t.texture_size_y[l->me.i] = l->t.texture_size_y[l->triangle_number];
			l->t.texture_light[l->me.i] = l->t.texture_light[l->triangle_number];
			l->t.texture_shift_x[l->me.i] = l->t.texture_shift_x[l->triangle_number];
			l->t.texture_shift_y[l->me.i] = l->t.texture_shift_y[l->triangle_number];
			l->t.texture_id[l->me.i] = l->t.texture_id[l->triangle_number];
			l->t.texture_opacity[l->me.i] = l->t.texture_opacity[l->triangle_number];
			l->t.texture_sides[l->me.i] = l->t.texture_sides[l->triangle_number];
			l->me.i--;
		}
		l->me.i++;
	}
	l->me.i = 0;
	while (l->me.i < l->light_number)
	{
		if (l->light_area[l->me.i] == l->area_select)
		{
			l->light_number--;
			l->light_area[l->me.i] = l->light_area[l->light_number];
			l->light_group[l->me.i] = l->light_group[l->light_number];
			l->light_x[l->me.i] = l->light_x[l->light_number];
			l->light_y[l->me.i] = l->light_y[l->light_number];
			l->light_z[l->me.i] = l->light_z[l->light_number];
			l->light_range[l->me.i] = l->light_range[l->light_number];
			l->me.i--;
		}
		l->me.i++;
	}
	l->area_select = -1;
}

void	ft_map_editor_main_action_delete_selection_group(variable_list* l)
{
	l->me.i = 0;
	while (l->me.i < l->triangle_number)
	{
		if (l->t.group[l->me.i] == l->group_select)
		{
			l->triangle_number--;
			l->t.area[l->me.i] = l->t.area[l->triangle_number];
			l->t.group[l->me.i] = l->t.group[l->triangle_number];
			l->t.x1[l->me.i] = l->t.x1[l->triangle_number];
			l->t.y1[l->me.i] = l->t.y1[l->triangle_number];
			l->t.z1[l->me.i] = l->t.z1[l->triangle_number];
			l->t.x2[l->me.i] = l->t.x2[l->triangle_number];
			l->t.y2[l->me.i] = l->t.y2[l->triangle_number];
			l->t.z2[l->me.i] = l->t.z2[l->triangle_number];
			l->t.x3[l->me.i] = l->t.x3[l->triangle_number];
			l->t.y3[l->me.i] = l->t.y3[l->triangle_number];
			l->t.z3[l->me.i] = l->t.z3[l->triangle_number];
			l->t.texture_size_x[l->me.i] = l->t.texture_size_x[l->triangle_number];
			l->t.texture_size_y[l->me.i] = l->t.texture_size_y[l->triangle_number];
			l->t.texture_light[l->me.i] = l->t.texture_light[l->triangle_number];
			l->t.texture_shift_x[l->me.i] = l->t.texture_shift_x[l->triangle_number];
			l->t.texture_shift_y[l->me.i] = l->t.texture_shift_y[l->triangle_number];
			l->t.texture_id[l->me.i] = l->t.texture_id[l->triangle_number];
			l->t.texture_opacity[l->me.i] = l->t.texture_opacity[l->triangle_number];
			l->t.texture_sides[l->me.i] = l->t.texture_sides[l->triangle_number];
			l->me.i--;
		}
		l->me.i++;
	}
	l->me.i = 0;
	while (l->me.i < l->light_number)
	{
		if (l->light_group[l->me.i] == l->group_select)
		{
			l->light_number--;
			l->light_area[l->me.i] = l->light_area[l->light_number];
			l->light_group[l->me.i] = l->light_group[l->light_number];
			l->light_x[l->me.i] = l->light_x[l->light_number];
			l->light_y[l->me.i] = l->light_y[l->light_number];
			l->light_z[l->me.i] = l->light_z[l->light_number];
			l->light_range[l->me.i] = l->light_range[l->light_number];
			l->me.i--;
		}
		l->me.i++;
	}
	l->group_select = -1;
}

void	ft_map_editor_main_action_delete_selection_light(variable_list* l)
{
	l->light_number--;
	l->light_area[(int)l->light_select] = l->light_area[l->light_number];
	l->light_group[(int)l->light_select] = l->light_group[l->light_number];
	l->light_x[(int)l->light_select] = l->light_x[l->light_number];
	l->light_y[(int)l->light_select] = l->light_y[l->light_number];
	l->light_z[(int)l->light_select] = l->light_z[l->light_number];
	l->light_range[(int)l->light_select] = l->light_range[l->light_number];
	l->light_select = -1;
}


void    ft_map_editor_paint_create_mode_initialize_triangle_1
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	l->fme_pml.x[0] = l->t.x3[tmp->ts] +
		(l->t.x2[tmp->ts] - l->t.x1[tmp->ts]);
	l->fme_pml.y[0] = l->t.y3[tmp->ts] +
		(l->t.y2[tmp->ts] - l->t.y1[tmp->ts]);
	l->fme_pml.z[0] = l->t.z3[tmp->ts] +
		(l->t.z2[tmp->ts] - l->t.z1[tmp->ts]);
	l->fme_pml.x[1] = l->t.x3[tmp->ts];
	l->fme_pml.y[1] = l->t.y3[tmp->ts];
	l->fme_pml.z[1] = l->t.z3[tmp->ts];
	l->fme_pml.x[2] = l->t.x2[tmp->ts];
	l->fme_pml.y[2] = l->t.y2[tmp->ts];
	l->fme_pml.z[2] = l->t.z2[tmp->ts];
}

void    ft_map_editor_paint_create_mode_initialize_triangle_2
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	l->fme_pml.x[3] = l->t.x1[tmp->ts];
	l->fme_pml.y[3] = l->t.y1[tmp->ts];
	l->fme_pml.z[3] = l->t.z1[tmp->ts];
	l->fme_pml.x[4] = l->t.x1[tmp->ts] -
		(l->t.x3[tmp->ts] - l->t.x1[tmp->ts]);
	l->fme_pml.y[4] = l->t.y1[tmp->ts] -
		(l->t.y3[tmp->ts] - l->t.y1[tmp->ts]);
	l->fme_pml.z[4] = l->t.z1[tmp->ts] -
		(l->t.z3[tmp->ts] - l->t.z1[tmp->ts]);
	l->fme_pml.x[5] = l->t.x2[tmp->ts];
	l->fme_pml.y[5] = l->t.y2[tmp->ts];
	l->fme_pml.z[5] = l->t.z2[tmp->ts];
}

void    ft_map_editor_paint_create_mode_initialize_triangle_3
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	l->fme_pml.x[6] = l->t.x1[tmp->ts];
	l->fme_pml.y[6] = l->t.y1[tmp->ts];
	l->fme_pml.z[6] = l->t.z1[tmp->ts];
	l->fme_pml.x[7] = l->t.x3[tmp->ts];
	l->fme_pml.y[7] = l->t.y3[tmp->ts];
	l->fme_pml.z[7] = l->t.z3[tmp->ts];
	l->fme_pml.x[8] = l->t.x1[tmp->ts] -
		(l->t.x2[tmp->ts] - l->t.x1[tmp->ts]);
	l->fme_pml.y[8] = l->t.y1[tmp->ts] -
		(l->t.y2[tmp->ts] - l->t.y1[tmp->ts]);
	l->fme_pml.z[8] = l->t.z1[tmp->ts] -
		(l->t.z2[tmp->ts] - l->t.z1[tmp->ts]);
}

int    ft_map_editor_paint_create_mode_check_triangle_1
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int i;
	int j;
	int counter;

	i = 0;
	while (i < l->triangle_number)
	{
		counter = 0;
		j = 0;
		while (j < 3)
		{
			if ((l->t.x1[i] == l->fme_pml.x[j] &&
				l->t.y1[i] == l->fme_pml.y[j] &&
				l->t.z1[i] == l->fme_pml.z[j]) ||
				(l->t.x2[i] == l->fme_pml.x[j] &&
					l->t.y2[i] == l->fme_pml.y[j] &&
					l->t.z2[i] == l->fme_pml.z[j]) ||
				(l->t.x3[i] == l->fme_pml.x[j] &&
					l->t.y3[i] == l->fme_pml.y[j] &&
					l->t.z3[i] == l->fme_pml.z[j]))
				counter++;
			j++;
		}
		if (counter == 3)
			return(-1);
		i++;
	}
	return(i);
}

void    ft_map_editor_paint_create_mode_triangle_1
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int tn;

	tn = l->triangle_number++;
	l->t.area[tn] = l->t.area[tmp->ts];
	l->t.group[tn] = l->t.group[tmp->ts];
	l->t.x1[tn] = l->fme_pml.x[0];
	l->t.y1[tn] = l->fme_pml.y[0];
	l->t.z1[tn] = l->fme_pml.z[0];
	l->t.x2[tn] = l->fme_pml.x[1];
	l->t.y2[tn] = l->fme_pml.y[1];
	l->t.z2[tn] = l->fme_pml.z[1];
	l->t.x3[tn] = l->fme_pml.x[2];
	l->t.y3[tn] = l->fme_pml.y[2];
	l->t.z3[tn] = l->fme_pml.z[2];
	l->t.texture_size_x[tn] = l->t.texture_size_x[tmp->ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[tmp->ts];
	l->t.texture_light[tn] = l->t.texture_light[tmp->ts];
	l->t.texture_shift_x[tn] = -(l->t.texture_size_x[tmp->ts] +
		l->t.texture_shift_x[tmp->ts]);
	l->t.texture_shift_y[tn] = -(l->t.texture_size_y[tmp->ts] +
		l->t.texture_shift_y[tmp->ts]);
	l->t.texture_id[tn] = l->t.texture_id[tmp->ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[tmp->ts];
	l->t.texture_sides[tn] = l->t.texture_sides[tmp->ts];
}

int    ft_map_editor_paint_create_mode_check_triangle_2
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int i;
	int j;
	int counter;

	i = 0;
	while (i < l->triangle_number)
	{
		counter = 0;
		j = 3;
		while (j < 6)
		{
			if ((l->t.x1[i] == l->fme_pml.x[j] &&
				l->t.y1[i] == l->fme_pml.y[j] &&
				l->t.z1[i] == l->fme_pml.z[j]) ||
				(l->t.x2[i] == l->fme_pml.x[j] &&
					l->t.y2[i] == l->fme_pml.y[j] &&
					l->t.z2[i] == l->fme_pml.z[j]) ||
				(l->t.x3[i] == l->fme_pml.x[j] &&
					l->t.y3[i] == l->fme_pml.y[j] &&
					l->t.z3[i] == l->fme_pml.z[j]))
				counter++;
			j++;
		}
		if (counter == 3)
			return(-1);
		i++;
	}
	return(i);
}

void    ft_map_editor_paint_create_mode_triangle_2
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int tn;

	tn = l->triangle_number++;
	l->t.area[tn] = l->t.area[tmp->ts];
	l->t.group[tn] = l->t.group[tmp->ts];
	l->t.x1[tn] = l->fme_pml.x[3];
	l->t.y1[tn] = l->fme_pml.y[3];
	l->t.z1[tn] = l->fme_pml.z[3];
	l->t.x2[tn] = l->fme_pml.x[4];
	l->t.y2[tn] = l->fme_pml.y[4];
	l->t.z2[tn] = l->fme_pml.z[4];
	l->t.x3[tn] = l->fme_pml.x[5];
	l->t.y3[tn] = l->fme_pml.y[5];
	l->t.z3[tn] = l->fme_pml.z[5];
	l->t.texture_size_x[tn] = l->t.texture_size_x[tmp->ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[tmp->ts];
	l->t.texture_light[tn] =
		(int)(l->t.texture_light[tmp->ts] + 90) % 360;
	l->t.texture_shift_x[tn] = l->t.texture_shift_y[tmp->ts];
	l->t.texture_shift_y[tn] = -l->t.texture_shift_x[tmp->ts];
	l->t.texture_id[tn] = l->t.texture_id[tmp->ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[tmp->ts];
	l->t.texture_sides[tn] = l->t.texture_sides[tmp->ts];
}

int    ft_map_editor_paint_create_mode_check_triangle_3
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int i;
	int j;
	int counter;

	i = 0;
	while (i < l->triangle_number)
	{
		counter = 0;
		j = 6;
		while (j < 9)
		{
			if ((l->t.x1[i] == l->fme_pml.x[j] &&
				l->t.y1[i] == l->fme_pml.y[j] &&
				l->t.z1[i] == l->fme_pml.z[j]) ||
				(l->t.x2[i] == l->fme_pml.x[j] &&
					l->t.y2[i] == l->fme_pml.y[j] &&
					l->t.z2[i] == l->fme_pml.z[j]) ||
				(l->t.x3[i] == l->fme_pml.x[j] &&
					l->t.y3[i] == l->fme_pml.y[j] &&
					l->t.z3[i] == l->fme_pml.z[j]))
				counter++;
			j++;
		}
		if (counter == 3)
			return(-1);
		i++;
	}
	return(i);
}

void    ft_map_editor_paint_create_mode_triangle_3
(variable_list* l, map_editor_paint_create_mode_list* tmp)
{
	int tn;

	tn = l->triangle_number++;
	l->t.area[tn] = l->t.area[tmp->ts];
	l->t.group[tn] = l->t.group[tmp->ts];
	l->t.x1[tn] = l->fme_pml.x[6];
	l->t.y1[tn] = l->fme_pml.y[6];
	l->t.z1[tn] = l->fme_pml.z[6];
	l->t.x2[tn] = l->fme_pml.x[7];
	l->t.y2[tn] = l->fme_pml.y[7];
	l->t.z2[tn] = l->fme_pml.z[7];
	l->t.x3[tn] = l->fme_pml.x[8];
	l->t.y3[tn] = l->fme_pml.y[8];
	l->t.z3[tn] = l->fme_pml.z[8];
	l->t.texture_size_x[tn] = l->t.texture_size_x[tmp->ts];
	l->t.texture_size_y[tn] = l->t.texture_size_y[tmp->ts];
	l->t.texture_light[tn] =
		(int)(l->t.texture_light[tmp->ts] + 90) % 360;
	l->t.texture_shift_x[tn] = -l->t.texture_shift_y[tmp->ts];
	l->t.texture_shift_y[tn] = l->t.texture_shift_x[tmp->ts];
	l->t.texture_id[tn] = l->t.texture_id[tmp->ts];
	l->t.texture_opacity[tn] = l->t.texture_opacity[tmp->ts];
	l->t.texture_sides[tn] = l->t.texture_sides[tmp->ts];
}

void    ft_map_editor_paint_create_mode(variable_list* l)
{
	map_editor_paint_create_mode_list tmp;

	tmp.ts = l->triangle_select;
	ft_map_editor_paint_create_mode_initialize_triangle_1(l, &tmp);
	ft_map_editor_paint_create_mode_initialize_triangle_2(l, &tmp);
	ft_map_editor_paint_create_mode_initialize_triangle_3(l, &tmp);
	if (l->triangle_number == MAX_TRIANGLES - 1)
		return;
	if (ft_map_editor_paint_create_mode_check_triangle_1(l, &tmp) != -1)
		ft_map_editor_paint_create_mode_triangle_1(l, &tmp);
	if (l->triangle_number == MAX_TRIANGLES - 1)
		return;
	if (ft_map_editor_paint_create_mode_check_triangle_2(l, &tmp) != -1)
		ft_map_editor_paint_create_mode_triangle_2(l, &tmp);
	if (l->triangle_number == MAX_TRIANGLES - 1)
		return;
	if (ft_map_editor_paint_create_mode_check_triangle_3(l, &tmp) != -1)
		ft_map_editor_paint_create_mode_triangle_3(l, &tmp);
	l->triangle_select = -1;
}

void	ft_map_editor_menu_initialize(variable_list* l)
{

}

void	ft_map_editor_menu_actions(variable_list* l)
{
}*/

void	ft_map_editor_menu_parameters(variable_list* l)
{
	l->action = 0;
	ft_map_editor_menu_background(l);
	ft_map_editor_menu_parameter_triangle(l);
	ft_map_editor_menu_parameter_area(l);
	ft_map_editor_menu_parameter_group(l);
	ft_map_editor_menu_parameter_light(l);
	ft_map_editor_menu_parameter_player(l);
	ft_map_editor_menu_parameter_game(l);
	ft_map_editor_menu_parameter_paint(l);
}
void	ft_map_editor_menu(variable_list* l)
{
	int i;
	int j;

	if (l->action_select[0][0] == 1)
	{
		l->menu_select = 0;
		ft_map_editor_menu_parameters(l);
		//ft_map_editor_menu_actions(l);
		//
		TMP_map_editor_menu_parameter_save_map(l);
		TMP_map_editor_menu_parameter_clean_errors(l);
		TMP_map_editor_save_map(l);
		TMP_map_editor_clean_errors(l);
		//
	}
	else if (l->action_select[0][0] == 0)
	{
		l->triangle_select = -1;
		l->triangle_select = -1;
		l->group_select = -1;
		l->light_select = -1;
		l->action_select[0][0]++;
	}
}

void	ft_map_editor(variable_list* l)
{
	ft_map_editor_tool_set_mult(l);
	//l->writing_mode = 0;
	ft_map_editor_menu(l);
	ft_map_editor_triangle(l);
	ft_map_editor_area(l);
	ft_map_editor_group(l);
	//ft_map_editor_light(l);
	//ft_map_editor_paint(l);
}

void	TMP_map_editor_save_map(variable_list* l)
{
	if (l->action_select[0][9] == 1)
	{
		int i;
		int buffer_size;
		char buffer[15];
		int stream;
		buffer_size = 15;

		printf("Saving...\n");
		if ((_sopen_s(&stream, "./txt/triangle.txt", O_RDWR | _O_CREAT,
			_SH_DENYNO, _S_IREAD | _S_IWRITE)) != 0)
		{
			printf("Load File Error\n");
			ft_free_and_exit(l);
		}
		printf("Triangle number: %d\n", l->triangle_number);
		_write(stream, "area,group,(POSITIONS)x,y,z,x,y,z,x,y,z,(TEXTURE)id,sizex,sizey,shiftx,shifty,light,opacity,sides\0", 97);
		i = 0;
		while (i < l->triangle_number)
		{
			_write(stream, ",\n\0", 2);
			buffer_size = ft_itoa(l, l->t.area[i], buffer), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.group[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_id[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_size_x[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_size_y[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_shift_x[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_shift_y[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_light[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_opacity[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_sides[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			i++;
		}
		_write(stream, "\0", 1);
		_close(stream);

		if ((_sopen_s(&stream, "./txt/group.txt", O_RDWR | _O_CREAT,
			_SH_DENYNO, _S_IREAD | _S_IWRITE)) != 0)
		{
			printf("Load File Error\n");
			ft_free_and_exit(l);
		}
		_write(stream, "id,sprite,\0", 10);
		i = 0;
		while (i < MAX_GROUPS)
		{
			if (l->g.sprite[i] > 0)
			{
				_write(stream, ",\n\0", 2);
				buffer_size = ft_itoa(l, (double)i, buffer), _write(stream, buffer, buffer_size);
				buffer_size = ft_itoa(l, l->g.sprite[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
				buffer_size = ft_itoa(l, l->g.npc[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
				buffer_size = ft_itoa(l, l->g.object[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			}
			i++;
		}
		_write(stream, "\0", 1);
		_close(stream);


		printf("Done.\n");
		l->action_select[0][9] = 0;
	}
}

void	TMP_map_editor_clean_errors(variable_list* l)
{
	if (l->action_select[0][10] == 1)
	{
		double c;
		int n = 0, f = 0, d = 0;
		int i = 0, j = 0;
		double x, y, z;

		printf("Checking for errors...\n");
		printf("%d\n", l->triangle_number);
		while (i < l->triangle_number)
		{
			l->e.v1x = l->t.x2[i] - l->t.x1[i];
			l->e.v2x = l->t.x3[i] - l->t.x1[i];
			l->e.v1y = l->t.y2[i] - l->t.y1[i];
			l->e.v2y = l->t.y3[i] - l->t.y1[i];
			l->e.v1z = l->t.z2[i] - l->t.z1[i];
			l->e.v2z = l->t.z3[i] - l->t.z1[i];
			l->e.d01 = sqrtf(l->e.v1x * l->e.v1x + l->e.v1y * l->e.v1y + l->e.v1z * l->e.v1z);
			l->e.d02 = sqrtf(l->e.v2x * l->e.v2x + l->e.v2y * l->e.v2y + l->e.v2z * l->e.v2z);
			if (l->t.texture_opacity[i] == 0)
			{
				l->triangle_select = i;
				--l->triangle_number;
				l->t.area[l->triangle_select] = l->t.area[l->triangle_number];
				l->t.group[l->triangle_select] = l->t.group[l->triangle_number];
				l->t.x1[l->triangle_select] = l->t.x1[l->triangle_number];
				l->t.y1[l->triangle_select] = l->t.y1[l->triangle_number];
				l->t.z1[l->triangle_select] = l->t.z1[l->triangle_number];
				l->t.x2[l->triangle_select] = l->t.x2[l->triangle_number];
				l->t.y2[l->triangle_select] = l->t.y2[l->triangle_number];
				l->t.z2[l->triangle_select] = l->t.z2[l->triangle_number];
				l->t.x3[l->triangle_select] = l->t.x3[l->triangle_number];
				l->t.y3[l->triangle_select] = l->t.y3[l->triangle_number];
				l->t.z3[l->triangle_select] = l->t.z3[l->triangle_number];
				l->t.texture_size_x[l->triangle_select] = l->t.texture_size_x[l->triangle_number];
				l->t.texture_size_y[l->triangle_select] = l->t.texture_size_y[l->triangle_number];
				l->t.texture_light[l->triangle_select] = l->t.texture_light[l->triangle_number];
				l->t.texture_shift_x[l->triangle_select] = l->t.texture_shift_x[l->triangle_number];
				l->t.texture_shift_y[l->triangle_select] = l->t.texture_shift_y[l->triangle_number];
				l->t.texture_id[l->triangle_select] = l->t.texture_id[l->triangle_number];
				l->t.texture_opacity[l->triangle_select] = l->t.texture_opacity[l->triangle_number];
				l->t.texture_sides[l->triangle_select] = l->t.texture_sides[l->triangle_number];
				l->triangle_select = -1;
				f++;
			}
			j = 0;
			if (l->t.x1[i] - l->t.x2[i] == 0 && l->t.x1[i] - l->t.x3[i] == 0)
				j++;
			if (l->t.y1[i] - l->t.y2[i] == 0 && l->t.y1[i] - l->t.y3[i] == 0)
				j++;
			if (l->t.z1[i] - l->t.z2[i] == 0 && l->t.z1[i] - l->t.z3[i] == 0)
				j++;
			if (j > 1)
			{
				l->triangle_select = i;
				--l->triangle_number;
				l->t.area[l->triangle_select] = l->t.area[l->triangle_number];
				l->t.group[l->triangle_select] = l->t.group[l->triangle_number];
				l->t.x1[l->triangle_select] = l->t.x1[l->triangle_number];
				l->t.y1[l->triangle_select] = l->t.y1[l->triangle_number];
				l->t.z1[l->triangle_select] = l->t.z1[l->triangle_number];
				l->t.x2[l->triangle_select] = l->t.x2[l->triangle_number];
				l->t.y2[l->triangle_select] = l->t.y2[l->triangle_number];
				l->t.z2[l->triangle_select] = l->t.z2[l->triangle_number];
				l->t.x3[l->triangle_select] = l->t.x3[l->triangle_number];
				l->t.y3[l->triangle_select] = l->t.y3[l->triangle_number];
				l->t.z3[l->triangle_select] = l->t.z3[l->triangle_number];
				l->t.texture_size_x[l->triangle_select] = l->t.texture_size_x[l->triangle_number];
				l->t.texture_size_y[l->triangle_select] = l->t.texture_size_y[l->triangle_number];
				l->t.texture_light[l->triangle_select] = l->t.texture_light[l->triangle_number];
				l->t.texture_shift_x[l->triangle_select] = l->t.texture_shift_x[l->triangle_number];
				l->t.texture_shift_y[l->triangle_select] = l->t.texture_shift_y[l->triangle_number];
				l->t.texture_id[l->triangle_select] = l->t.texture_id[l->triangle_number];
				l->t.texture_opacity[l->triangle_select] = l->t.texture_opacity[l->triangle_number];
				l->t.texture_sides[l->triangle_select] = l->t.texture_sides[l->triangle_number];
				l->triangle_select = -1;
				d++;
			}
			j = 0;
			while (j < l->triangle_number)
			{
				if (l->t.x1[j] == l->t.x1[i] &&
					l->t.x2[j] == l->t.x2[i] &&
					l->t.x3[j] == l->t.x3[i] &&
					l->t.z1[j] == l->t.z1[i] &&
					l->t.z2[j] == l->t.z2[i] &&
					l->t.z3[j] == l->t.z3[i] &&
					l->t.y1[j] == l->t.y1[i] &&
					l->t.y2[j] == l->t.y2[i] &&
					l->t.y3[j] == l->t.y3[i] &&
					j != i)
				{
					l->triangle_select = i;
					--l->triangle_number;
					l->t.area[l->triangle_select] = l->t.area[l->triangle_number];
					l->t.group[l->triangle_select] = l->t.group[l->triangle_number];
					l->t.x1[l->triangle_select] = l->t.x1[l->triangle_number];
					l->t.y1[l->triangle_select] = l->t.y1[l->triangle_number];
					l->t.z1[l->triangle_select] = l->t.z1[l->triangle_number];
					l->t.x2[l->triangle_select] = l->t.x2[l->triangle_number];
					l->t.y2[l->triangle_select] = l->t.y2[l->triangle_number];
					l->t.z2[l->triangle_select] = l->t.z2[l->triangle_number];
					l->t.x3[l->triangle_select] = l->t.x3[l->triangle_number];
					l->t.y3[l->triangle_select] = l->t.y3[l->triangle_number];
					l->t.z3[l->triangle_select] = l->t.z3[l->triangle_number];
					l->t.texture_size_x[l->triangle_select] = l->t.texture_size_x[l->triangle_number];
					l->t.texture_size_y[l->triangle_select] = l->t.texture_size_y[l->triangle_number];
					l->t.texture_light[l->triangle_select] = l->t.texture_light[l->triangle_number];
					l->t.texture_shift_x[l->triangle_select] = l->t.texture_shift_x[l->triangle_number];
					l->t.texture_shift_y[l->triangle_select] = l->t.texture_shift_y[l->triangle_number];
					l->t.texture_id[l->triangle_select] = l->t.texture_id[l->triangle_number];
					l->t.texture_opacity[l->triangle_select] = l->t.texture_opacity[l->triangle_number];
					l->t.texture_sides[l->triangle_select] = l->t.texture_sides[l->triangle_number];
					l->triangle_select = -1;
					n++;
				}
				j++;
			}

			i++;
		}
		printf("%d no opacity triangles deleted.\n", f);
		printf("%d supperposed triangles deleted.\n", n);
		printf("%d invisible triangles deleted.\n", d);
		printf("%d\n", l->triangle_number);
		l->action_select[0][10] = 0;
	}
}
