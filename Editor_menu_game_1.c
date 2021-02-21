#include "header.h"

void		ft_map_editor_game_parameters(variable_list *l)
{
	ft_map_editor_submenu_background(l);
	ft_map_editor_game_parameter_npc(l);
	ft_map_editor_game_parameter_npc_health(l);
	ft_map_editor_game_parameter_npc_damage(l);
	ft_map_editor_game_parameter_world(l);
	ft_map_editor_game_parameter_world_gravity(l);
}

void		ft_map_editor_game_actions(variable_list *l)
{
	ft_map_editor_game_action_npc_health(l);
	ft_map_editor_game_action_npc_damage(l);
	ft_map_editor_game_action_world_gravity(l);
}

void		ft_map_editor_game(variable_list *l)
{
	if (l->action_select[0][6] == 1)
	{
		l->triangle_select = -1;
		l->group_select = -1;
		l->area_select = -1;
		l->menu_select = 6;
		l->action = 0;
		ft_map_editor_game_parameters(l);
		l->action = 0;
		ft_map_editor_game_actions(l);
	}
}
