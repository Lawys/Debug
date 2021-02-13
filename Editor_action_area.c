#include "header.h"

void	ft_map_editor_area_action_select_area(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->area_select, 1, MAX_AREAS - 1);
}
void	ft_map_editor_area_action_switch_area(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->me.area_switch_value, 1, MAX_AREAS - 1);
		if (l->i.state[40] || l->i.state[88]) //ENTER
		{
			i = 0;
			while (i < l->triangle_number)
			{
				if (l->t.area[i] == l->area_select)
					l->t.area[i] = l->me.area_switch_value;
				i++;
			}
			l->area_select = l->me.area_switch_value;
			l->i.state[40] = 0;
			l->i.state[88] = 0;
			l->me.area_switch_value = 1;
		}
	}
}

void	ft_map_editor_area_action_position_x_up(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.x1[i] += l->me.mult / 100;
			l->t.x2[i] += l->me.mult / 100;
			l->t.x3[i] += l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_x_down(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.x1[i] -= l->me.mult / 100;
			l->t.x2[i] -= l->me.mult / 100;
			l->t.x3[i] -= l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_x(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_x_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_x_down(l);
	}
}
void	ft_map_editor_area_action_position_y_up(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.y1[i] += l->me.mult / 100;
			l->t.y2[i] += l->me.mult / 100;
			l->t.y3[i] += l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_y_down(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.y1[i] -= l->me.mult / 100;
			l->t.y2[i] -= l->me.mult / 100;
			l->t.y3[i] -= l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_y(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_y_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_y_down(l);
	}
}
void	ft_map_editor_area_action_position_z_up(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.z1[i] += l->me.mult / 100;
			l->t.z2[i] += l->me.mult / 100;
			l->t.z3[i] += l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_z_down(variable_list* l)
{
	int i;

	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			l->t.z1[i] -= l->me.mult / 100;
			l->t.z2[i] -= l->me.mult / 100;
			l->t.z3[i] -= l->me.mult / 100;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_z(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_z_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_z_down(l);
	}
}
void	ft_map_editor_area_action_position_calculate_center(variable_list* l)
{
	int c;
	int i;

	l->me.x = 0;
	l->me.y = 0;
	l->me.z = 0;
	c = 0;
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
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
}
void	ft_map_editor_area_action_position_h_up(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
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
		i++;
	}
}
void	ft_map_editor_area_action_position_h_down(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
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
		i++;
	}
}
void	ft_map_editor_area_action_position_h(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_h_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_h_down(l);
	}
}
void	ft_map_editor_area_action_position_v_up(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_vdown(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_v(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_v_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_vdown(l);
	}
}
void	ft_map_editor_area_action_position_l_up(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_l_down(variable_list* l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = 0;
	while (i < l->triangle_number)
	{
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) + (l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) + (l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) + (l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) + (l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) + (l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) + (l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
		i++;
	}
}
void	ft_map_editor_area_action_position_l(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_l_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_l_down(l);
	}
}
void	ft_map_editor_area_action_position_size_recall(variable_list* l)
{
	double xyz[3];
	int ts;
	double p[3];

	p[0] = l->me.x;
	p[1] = l->me.y;
	p[2] = l->me.z;
	ft_map_editor_area_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->t.area[ts] == l->area_select)
		{
			xyz[0] = l->me.x - p[0];
			xyz[1] = l->me.y - p[1];
			xyz[2] = l->me.z - p[2];
			l->t.x1[ts] -= xyz[0];
			l->t.x2[ts] -= xyz[0];
			l->t.x3[ts] -= xyz[0];
			l->t.y1[ts] -= xyz[1];
			l->t.y2[ts] -= xyz[1];
			l->t.y3[ts] -= xyz[1];
			l->t.z1[ts] -= xyz[2];
			l->t.z2[ts] -= xyz[2];
			l->t.z3[ts] -= xyz[2];
		}
	}
}
void	ft_map_editor_area_action_position_size_up(variable_list* l)
{
	int ts;

	ft_map_editor_area_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->t.area[ts] == l->area_select)
		{
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
		}
	}
	ft_map_editor_area_action_position_size_recall(l);
}
void	ft_map_editor_area_action_position_size_down(variable_list* l)
{
	int ts;

	ft_map_editor_area_action_position_calculate_center(l);
	ts = -1;
	while (++ts < l->triangle_number)
	{
		if (l->t.area[ts] == l->area_select)
		{
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
		}
	}
	ft_map_editor_area_action_position_size_recall(l);
}
void	ft_map_editor_area_action_position_size(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_size_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_size_down(l);
	}
}

void	ft_map_editor_area_action_link1(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link1[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_link2(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link2[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_link3(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link3[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_link4(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link4[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_link5(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link5[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_link6(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_int(l, &l->link6[l->area_select], 1, MAX_AREAS - 1);
	}
}

void	ft_map_editor_area_action_delete(variable_list* l)
{
	int tn;
	int ts;

	if (l->action_select[l->menu_select][++l->action])
	{
		l->action_select[l->menu_select][l->action] = 0;
		ts = -1;
		while (++ts < l->triangle_number)
		{
			if (l->t.area[ts] == l->area_select)
			{
				tn = --l->triangle_number;
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
				ts--;
			}
		}
		l->area_select = -1;
	}
}
/*void	ft_map_editor_area_action_paint_delete(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
			{
				l->triangle_select = l->t.list[i];
				if (l->triangle_select < l->triangle_number)
					ft_map_editor_main_action_delete_selection_triangle(l);
			}
		}
	}
}
void	ft_map_editor_area_action_paint_create(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
			{
				l->triangle_select = l->t.list[i];
				if (l->triangle_select < l->triangle_number)
				{
				}//ft_map_editor_paint_create_triangles(l);
			}
		}
	}
}
void	ft_map_editor_area_action_paint_texture(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_map_editor_paint_selected_texture(l);
		ft_value_editing_double(l, &l->paint_texture_select, 0, l->texture_number);
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
				if (l->t.list[i] < l->triangle_number)
					l->t.texture_id[l->t.list[i]] = (int)l->paint_texture_select;
		}
	}
}
void	ft_map_editor_area_action_paint_opacity(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->paint_opacity_select, 0, 100);
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
				if (l->t.list[i] < l->triangle_number)
					l->t.texture_opacity[l->t.list[i]] = (int)l->paint_opacity_select;
		}
	}
}
void	ft_map_editor_area_action_paint_area(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->paint_area_select, 0, MAX_GROUPS - 1);
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
				if (l->t.list[i] < l->triangle_number)
					l->t.area[l->t.list[i]] = (int)l->paint_area_select;
		}
	}
}
void	ft_map_editor_area_action_paint_area(variable_list* l)
{
	int i;

	if (l->action_select[l->menu_select][++l->action])
	{
		ft_value_editing_double(l, &l->paint_area_select, 0, MAX_AREAS - 1);
		ft_map_editor_paint_size(l);
		if (l->pixels_distance[l->i.mouse_x / 2][l->i.mouse_y / 2] > 0)
		{
			ft_map_editor_paint_pixels_initialize(l);
			ft_map_editor_paint_area_triangle_list(l);
			i = -1;
			while (l->t.list[++i] != -1)
				if (l->t.list[i] < l->triangle_number)
					l->t.area[l->t.list[i]] = (int)l->paint_area_select;
		}
	}
}
*/