#include "header.h"

void	ft_map_editor_area_parameters(variable_list* l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_area_parameter_area(l);
	ft_map_editor_area_parameter_area_id(l);
	ft_map_editor_area_parameter_switch(l);
	ft_map_editor_area_parameter_position(l);
	ft_map_editor_area_parameter_position_x(l);
	ft_map_editor_area_parameter_position_y(l);
	ft_map_editor_area_parameter_position_z(l);
	ft_map_editor_area_parameter_link(l);
	ft_map_editor_area_parameter_link1(l);
	ft_map_editor_area_parameter_link2(l);
	ft_map_editor_area_parameter_link3(l);
	ft_map_editor_area_parameter_link4(l);
	ft_map_editor_area_parameter_link5(l);
	ft_map_editor_area_parameter_link6(l);
	/*ft_map_editor_area_parameter_position_h(l);
	ft_map_editor_area_parameter_position_v(l);
	ft_map_editor_area_parameter_position_l(l);
	ft_map_editor_area_parameter_position_size(l);*/
	ft_map_editor_area_parameter_options(l);
	ft_map_editor_area_parameter_delete(l);
}
void	ft_map_editor_area_actions(variable_list* l)
{
	ft_map_editor_area_action_select_area(l);
	ft_map_editor_area_action_switch_area(l);
	ft_map_editor_area_action_position_x(l);
	ft_map_editor_area_action_position_y(l);
	ft_map_editor_area_action_position_z(l);
	ft_map_editor_area_action_link1(l);
	ft_map_editor_area_action_link2(l);
	ft_map_editor_area_action_link3(l);
	ft_map_editor_area_action_link4(l);
	ft_map_editor_area_action_link5(l);
	ft_map_editor_area_action_link6(l);
	/*ft_map_editor_area_action_position_h(l);
	ft_map_editor_area_action_position_v(l);
	ft_map_editor_area_action_position_l(l);
	ft_map_editor_area_action_position_size(l);*/
	ft_map_editor_area_action_delete(l);
}

void	ft_map_editor_area(variable_list* l)
{
	if (l->action_select[0][2] == 1 && l->area_select != -1)
	{
		l->triangle_select = -1;
		l->group_select = -1;
		l->menu_select = 2;
		l->action = 0;
		ft_map_editor_area_parameters(l);
		l->action = 0;
		ft_map_editor_area_actions(l);
	}
}