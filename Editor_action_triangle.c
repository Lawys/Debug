#include "header.h"

void	ft_map_editor_triangle_action_triangle(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->triangle_select, 12, l->triangle_number - 1);
}
void	ft_map_editor_triangle_action_area(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.area[l->triangle_select], 1, MAX_AREAS - 1);
}
void	ft_map_editor_triangle_action_group(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.group[l->triangle_select], 1, MAX_GROUPS - 1);
}

void	ft_map_editor_triangle_action_position_x_all(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.x1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.x3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
	}
}
void	ft_map_editor_triangle_action_position_y_all(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.y1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.y3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
	}
}
void	ft_map_editor_triangle_action_position_z_all(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.z1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.z2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
		ft_value_editing_double(l, &l->t.z3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
	}
}
void	ft_map_editor_triangle_action_position_calculate_center(variable_list* l)
{
	int ts;

	ts = l->triangle_select;
	l->me.x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts]) / 3;
	l->me.y = (l->t.y1[ts] + l->t.y2[ts] + l->t.y3[ts]) / 3;
	l->me.z = (l->t.z1[ts] + l->t.z2[ts] + l->t.z3[ts]) / 3;
}
void	ft_map_editor_triangle_action_position_size_recall(variable_list* l)
{
	int ts;
	double x;
	double y;
	double z;

	ts = l->triangle_select;
	x = (l->t.x1[ts] + l->t.x2[ts] + l->t.x3[ts]) / 3 - l->me.x;
	y = (l->t.y1[ts] + l->t.y2[ts] + l->t.y3[ts]) / 3 - l->me.y;
	z = (l->t.z1[ts] + l->t.z2[ts] + l->t.z3[ts]) / 3 - l->me.z;
	l->t.x1[ts] -= x;
	l->t.x2[ts] -= x;
	l->t.x3[ts] -= x;
	l->t.y1[ts] -= y;
	l->t.y2[ts] -= y;
	l->t.y3[ts] -= y;
	l->t.z1[ts] -= z;
	l->t.z2[ts] -= z;
	l->t.z3[ts] -= z;
}
void	ft_map_editor_triangle_action_position_size_up(variable_list* l)
{
	int ts;
	ft_map_editor_triangle_action_position_calculate_center(l);
	ts = l->triangle_select;
	l->t.x1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.x2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.x3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.y3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z1[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z2[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.z3[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_x[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_y[ts] /= 1 + 0.00001 * l->me.mult;
	ft_map_editor_triangle_action_position_size_recall(l);
}
void	ft_map_editor_triangle_action_position_size_down(variable_list* l)
{
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	ts = l->triangle_select;
	l->t.x1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.x2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.x3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.y3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z1[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z2[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.z3[ts] /= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_x[ts] *= 1 + 0.00001 * l->me.mult;
	l->t.texture_size_y[ts] *= 1 + 0.00001 * l->me.mult;
	ft_map_editor_triangle_action_position_size_recall(l);
}
void	ft_map_editor_triangle_action_position_size(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_size_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_size_down(l);
	}
}

void	ft_map_editor_triangle_action_position_h_up(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.x1[ts] - l->me.x) * cos(l->me.angle) + (l->t.z1[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z1[ts] = -(l->t.x1[ts] - l->me.x) * sin(l->me.angle) + (l->t.z1[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x1[ts] = tmp;
	tmp = (l->t.x2[ts] - l->me.x) * cos(l->me.angle) + (l->t.z2[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z2[ts] = -(l->t.x2[ts] - l->me.x) * sin(l->me.angle) + (l->t.z2[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x2[ts] = tmp;
	tmp = (l->t.x3[ts] - l->me.x) * cos(l->me.angle) + (l->t.z3[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z3[ts] = -(l->t.x3[ts] - l->me.x) * sin(l->me.angle) + (l->t.z3[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_h_down(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.x1[ts] - l->me.x) * cos(l->me.angle) + (l->t.z1[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z1[ts] = -(l->t.x1[ts] - l->me.x) * sin(l->me.angle) + (l->t.z1[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x1[ts] = tmp;
	tmp = (l->t.x2[ts] - l->me.x) * cos(l->me.angle) + (l->t.z2[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z2[ts] = -(l->t.x2[ts] - l->me.x) * sin(l->me.angle) + (l->t.z2[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x2[ts] = tmp;
	tmp = (l->t.x3[ts] - l->me.x) * cos(l->me.angle) + (l->t.z3[ts] - l->me.z) * sin(l->me.angle) + l->me.x;
	l->t.z3[ts] = -(l->t.x3[ts] - l->me.x) * sin(l->me.angle) + (l->t.z3[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.x3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_h(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action] == 1)
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_h_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_h_down(l);
	}
}
void	ft_map_editor_triangle_action_position_v_up(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) + (l->t.z1[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) + (l->t.z1[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) + (l->t.z2[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) + (l->t.z2[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) + (l->t.z3[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) + (l->t.z3[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_vdown(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) + (l->t.z1[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) + (l->t.z1[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) + (l->t.z2[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) + (l->t.z2[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) + (l->t.z3[ts] - l->me.z) * sin(l->me.angle) + l->me.y;
	l->t.z3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) + (l->t.z3[ts] - l->me.z) * cos(l->me.angle) + l->me.z;
	l->t.y3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_v(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action] == 1)
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_v_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_vdown(l);
	}
}
void	ft_map_editor_triangle_action_position_l_up(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) + (l->t.x1[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) + (l->t.x1[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) + (l->t.x2[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) + (l->t.x2[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) + (l->t.x3[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) + (l->t.x3[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_l_down(variable_list* l)
{
	double tmp;
	int ts;

	ft_map_editor_triangle_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100) * 0.9;
	ts = l->triangle_select;
	tmp = (l->t.y1[ts] - l->me.y) * cos(l->me.angle) + (l->t.x1[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x1[ts] = -(l->t.y1[ts] - l->me.y) * sin(l->me.angle) + (l->t.x1[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y1[ts] = tmp;
	tmp = (l->t.y2[ts] - l->me.y) * cos(l->me.angle) + (l->t.x2[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x2[ts] = -(l->t.y2[ts] - l->me.y) * sin(l->me.angle) + (l->t.x2[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y2[ts] = tmp;
	tmp = (l->t.y3[ts] - l->me.y) * cos(l->me.angle) + (l->t.x3[ts] - l->me.x) * sin(l->me.angle) + l->me.y;
	l->t.x3[ts] = -(l->t.y3[ts] - l->me.y) * sin(l->me.angle) + (l->t.x3[ts] - l->me.x) * cos(l->me.angle) + l->me.x;
	l->t.y3[ts] = tmp;
}
void	ft_map_editor_triangle_action_position_l(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action] == 1)
	{
		if (l->i.scroll_up)
			ft_map_editor_triangle_action_position_l_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_triangle_action_position_l_down(l);
	}
}


void	ft_map_editor_triangle_action_position_x_1(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->t.x1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
	}
}
void	ft_map_editor_triangle_action_position_y_1(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_z_1(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z1[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_x_2(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.x2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_y_2(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_z_2(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z2[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_x_3(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.x3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_y_3(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.y3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_position_z_3(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.z3[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_texture(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.texture_id[l->triangle_select], 0, l->texture_number - 1);
}
void	ft_map_editor_triangle_action_texture_light(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_light[l->triangle_select], 0, 100);
}
void	ft_map_editor_triangle_action_texture_opacity(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_opacity[l->triangle_select], 10, 100);
}
void	ft_map_editor_triangle_action_texture_size_x(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_size_x[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_texture_size_y(variable_list * l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_size_y[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_texture_size_stretch(variable_list* l)
{
	double dist12;
	double dist13;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		l->t.texture_size_y[ts] = 100 / (dist13 / 100);
		l->action_select[l->menu_select][l->action] = 0;
	}
}
void	ft_map_editor_triangle_action_texture_size_repeat(variable_list* l)
{
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		l->t.texture_size_x[ts] = 100;
		l->t.texture_size_y[ts] = 100;
		l->action_select[l->menu_select][l->action] = 0;
	}
}
void	ft_map_editor_triangle_action_texture_size_adapt_y(variable_list* l)
{
	double dist12;
	double dist13;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		if (dist12 < dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist12 / 100);
			l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		}
		else if (dist12 > dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist13 / 100);
			l->t.texture_size_x[ts] = 100 / (dist13 / 100);
		}
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void	ft_map_editor_triangle_action_texture_size_adapt_x(variable_list* l)
{
	double dist12;
	double dist13;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		if (dist12 < dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist13 / 100);
			l->t.texture_size_x[ts] = 100 / (dist13 / 100);
		}
		else if (dist12 > dist13)
		{
			l->t.texture_size_y[ts] = 100 / (dist12 / 100);
			l->t.texture_size_x[ts] = 100 / (dist12 / 100);
		}
		l->action_select[l->menu_select][l->action] = 0;
	}
}
void	ft_map_editor_triangle_action_texture_shift_x(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_shift_x[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_texture_shift_y(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->t.texture_shift_y[l->triangle_select], -MAX_GENERIC, MAX_GENERIC);
}
void	ft_map_editor_triangle_action_texture_sides(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->t.texture_sides[l->triangle_select], -1, 1);
}

void	ft_map_editor_triangle_action_create_new(variable_list* l)
{
	int tn;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return;
		ft_map_editor_group_action_check_free_group(l);
		if (l->me.new_group == MAX_GROUPS)
			return;
		tn = l->triangle_number++;
		l->t.area[tn] = 0;
		l->t.group[tn] = l->me.new_group;
		l->t.x1[tn] = (int)l->p.x;
		l->t.y1[tn] = (int)l->p.y;
		l->t.z1[tn] = (int)l->p.z;
		l->t.x2[tn] = (int)l->p.x;
		l->t.y2[tn] = (int)l->p.y + 10.;
		l->t.z2[tn] = (int)l->p.z;
		l->t.x3[tn] = (int)l->p.x + 10.;
		l->t.y3[tn] = (int)l->p.y;
		l->t.z3[tn] = (int)l->p.z;
		l->t.texture_size_x[tn] = 100;
		l->t.texture_size_y[tn] = 100;
		l->t.texture_light[tn] = 100;
		l->t.texture_shift_x[tn] = 0;
		l->t.texture_shift_y[tn] = 0;
		l->t.texture_id[tn] = 0;
		l->t.texture_opacity[tn] = 100;
		l->t.texture_sides[tn] = 0;
		l->triangle_select = tn;
	}
}

void	ft_map_editor_triangle_action_create_square(variable_list* l)
{
	int tn;
	int ts;
	double dist12;
	double dist13;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return;
		tn = l->triangle_number++;
		ts = l->triangle_select;
		dist12 = sqrt((l->t.x2[ts] - l->t.x1[ts]) * (l->t.x2[ts] - l->t.x1[ts]) +
			(l->t.y2[ts] - l->t.y1[ts]) * (l->t.y2[ts] - l->t.y1[ts]) +
			(l->t.z2[ts] - l->t.z1[ts]) * (l->t.z2[ts] - l->t.z1[ts]));
		dist13 = sqrt((l->t.x3[ts] - l->t.x1[ts]) * (l->t.x3[ts] - l->t.x1[ts]) +
			(l->t.y3[ts] - l->t.y1[ts]) * (l->t.y3[ts] - l->t.y1[ts]) +
			(l->t.z3[ts] - l->t.z1[ts]) * (l->t.z3[ts] - l->t.z1[ts]));
		l->t.area[tn] = l->t.area[ts];
		l->t.group[tn] = l->t.group[ts];
		l->t.x1[tn] = l->t.x2[ts] + (l->t.x3[ts] - l->t.x1[ts]);
		l->t.y1[tn] = l->t.y2[ts] + (l->t.y3[ts] - l->t.y1[ts]);
		l->t.z1[tn] = l->t.z2[ts] + (l->t.z3[ts] - l->t.z1[ts]);
		l->t.x2[tn] = l->t.x3[ts];
		l->t.y2[tn] = l->t.y3[ts];
		l->t.z2[tn] = l->t.z3[ts];
		l->t.x3[tn] = l->t.x2[ts];
		l->t.y3[tn] = l->t.y2[ts];
		l->t.z3[tn] = l->t.z2[ts];
		l->t.texture_size_x[tn] = l->t.texture_size_x[ts];
		l->t.texture_size_y[tn] = l->t.texture_size_y[ts];
		l->t.texture_light[tn] = l->t.texture_light[ts];
		l->t.texture_shift_x[tn] = -(l->t.texture_shift_x[ts] + dist12 * l->t.texture_size_x[ts] / 100);
		l->t.texture_shift_y[tn] = -(l->t.texture_shift_y[ts] + dist13 * l->t.texture_size_y[ts] / 100);
		l->t.texture_id[tn] = l->t.texture_id[ts];
		l->t.texture_opacity[tn] = l->t.texture_opacity[ts];
		l->t.texture_sides[tn] = l->t.texture_sides[ts];
		l->triangle_select = tn;
	}
}

void	ft_map_editor_triangle_action_duplicate(variable_list* l)
{
	int tn;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == MAX_TRIANGLES - 1)
			return;
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
}

void	ft_map_editor_triangle_action_delete(variable_list* l)
{
	int tn;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		if (l->triangle_number == 0)
			return;
		tn = --l->triangle_number;
		ts = l->triangle_select;
		l->t.area[ts] = l->t.area[tn];
		l->t.group[ts] = l->t.group[tn];
		l->t.x1[ts] = l->t.x1[tn];
		l->t.y1[ts] = l->t.y1[tn];
		l->t.z1[ts] = l->t.z1[tn];
		l->t.x2[ts] = l->t.x2[tn];
		l->t.y2[ts] = l->t.y2[tn];
		l->t.z2[ts] = l->t.z2[tn];
		l->t.x3[ts] = l->t.x3[tn];
		l->t.y3[ts] = l->t.y3[tn];
		l->t.z3[ts] = l->t.z3[tn];
		l->t.texture_size_x[ts] = l->t.texture_size_x[tn];
		l->t.texture_size_y[ts] = l->t.texture_size_y[tn];
		l->t.texture_light[ts] = l->t.texture_light[tn];
		l->t.texture_shift_x[ts] = l->t.texture_shift_x[tn];
		l->t.texture_shift_y[ts] = l->t.texture_shift_y[tn];
		l->t.texture_id[ts] = l->t.texture_id[tn];
		l->t.texture_opacity[ts] = l->t.texture_opacity[tn];
		l->t.texture_sides[ts] = l->t.texture_sides[tn];
		l->triangle_select = -1;
	}
}
