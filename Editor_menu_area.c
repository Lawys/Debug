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
		l->menu_select = 2;
		l->action = 0;
		ft_map_editor_area_parameters(l);
		l->action = 0;
		ft_map_editor_area_actions(l);
	}
	else
		l->area_select = -1;
}