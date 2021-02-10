#include "header.h"

void	ft_map_editor_paint_parameters(variable_list* l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_paint_parameter_mode(l);
	ft_map_editor_paint_parameter_delete(l);
	ft_map_editor_paint_parameter_texture(l);
	ft_map_editor_paint_parameter_group(l);
	ft_map_editor_paint_parameter_area(l);
	ft_map_editor_paint_parameter_opacity(l);
	ft_map_editor_paint_parameter_light(l);
}
void	ft_map_editor_paint_actions(variable_list* l)
{
	ft_map_editor_paint_action_delete(l);
	ft_map_editor_paint_action_texture(l);
	ft_map_editor_paint_action_group(l);
	ft_map_editor_paint_action_area(l);
	ft_map_editor_paint_action_opacity(l);
	ft_map_editor_paint_action_light(l);
}

void	ft_map_editor_paint(variable_list* l)
{
	if (l->action_select[0][7] == 1)
	{
		l->menu_select = 7;
		l->action = 0;
		ft_map_editor_paint_parameters(l);
		l->action = 0;
		ft_map_editor_paint_actions(l);
	}
}