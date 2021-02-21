#include "header.h"

void		ft_map_editor_area_action_position_v_up(variable_list *l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
}

void		ft_map_editor_area_action_position_vdown(variable_list *l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z1[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z1[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z2[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z2[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.z3[i] - l->me.z) * sin(l->me.angle) + l->me.y;
			l->t.z3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.z3[i] - l->me.z) * cos(l->me.angle) + l->me.z;
			l->t.y3[i] = tmp;
		}
}

void		ft_map_editor_area_action_position_v(variable_list *l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->i.scroll_up)
			ft_map_editor_area_action_position_v_up(l);
		else if (l->i.scroll_down)
			ft_map_editor_area_action_position_vdown(l);
	}
}

void		ft_map_editor_area_action_position_l_up(variable_list *l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = (M_PI / 180) * (l->me.mult / 100);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
}

void		ft_map_editor_area_action_position_l_down(variable_list *l)
{
	double tmp;
	int i;

	ft_map_editor_area_action_position_calculate_center(l);
	l->me.angle = -(M_PI / 180) * (l->me.mult / 100);
	i = -1;
	while (++i < l->triangle_number)
		if (l->t.area[i] == l->area_select)
		{
			tmp = (l->t.y1[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x1[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x1[i] = -(l->t.y1[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x1[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y1[i] = tmp;
			tmp = (l->t.y2[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x2[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x2[i] = -(l->t.y2[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x2[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y2[i] = tmp;
			tmp = (l->t.y3[i] - l->me.y) * cos(l->me.angle) +
				(l->t.x3[i] - l->me.x) * sin(l->me.angle) + l->me.y;
			l->t.x3[i] = -(l->t.y3[i] - l->me.y) * sin(l->me.angle) +
				(l->t.x3[i] - l->me.x) * cos(l->me.angle) + l->me.x;
			l->t.y3[i] = tmp;
		}
}
