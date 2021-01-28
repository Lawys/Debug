#include "header.h"

void	ft_map_editor_group_parameters(variable_list* l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_group_parameter_group(l);
	ft_map_editor_group_parameter_group_id(l);
	ft_map_editor_group_parameter_switch(l);
	ft_map_editor_group_parameter_position(l);
	ft_map_editor_group_parameter_position_x(l);
	ft_map_editor_group_parameter_position_y(l);
	ft_map_editor_group_parameter_position_z(l);
	ft_map_editor_group_parameter_position_h(l);
	ft_map_editor_group_parameter_position_v(l);
	ft_map_editor_group_parameter_position_l(l);
	ft_map_editor_group_parameter_position_size(l);
	ft_map_editor_group_parameter_modes(l);
	ft_map_editor_group_parameter_sprite(l);
	ft_map_editor_group_parameter_npc(l);
	ft_map_editor_group_parameter_object(l);
	ft_map_editor_group_parameter_options(l);
	ft_map_editor_group_parameter_create_npc(l);
	ft_map_editor_group_parameter_duplicate(l);
	ft_map_editor_group_parameter_delete(l);
}

void	ft_map_editor_group_actions(variable_list* l)
{
	ft_map_editor_group_action_select_group(l);
	ft_map_editor_group_action_switch_group(l);
	ft_map_editor_group_action_position_x(l);
	ft_map_editor_group_action_position_y(l);
	ft_map_editor_group_action_position_z(l);
	ft_map_editor_group_action_position_h(l);
	ft_map_editor_group_action_position_v(l);
	ft_map_editor_group_action_position_l(l);
	ft_map_editor_group_action_position_size(l);
	ft_map_editor_group_action_sprite(l);
	ft_map_editor_group_action_object(l);
	ft_map_editor_group_action_create_npc(l);
	ft_map_editor_group_action_duplicate(l);
	ft_map_editor_group_action_delete(l);
}

void	ft_map_editor_group(variable_list* l)
{
	if (l->action_select[0][3] == 1 && l->group_select != -1)
	{
		l->menu_select = 3;
		l->action = 0;
		ft_map_editor_group_parameters(l);
		l->action = 0;
		ft_map_editor_group_actions(l);
	}
	else
		l->group_select = -1;
}