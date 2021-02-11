#include "header.h"

void ft_map_editor_game_action_mission_kill_all_npc(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->mission[0] == 0)
			l->mission[0] = 1;
		else
			l->mission[0] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_game_action_mission_destroy_computers(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->mission[1] == 0)
			l->mission[1] = 1;
		else
			l->mission[1] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_game_action_mission_steal_top_secret_box(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->mission[2] == 0)
			l->mission[2] = 1;
		else
			l->mission[2] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_game_action_npc_health(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->npc_base_life, 0, 10000);
}

void ft_map_editor_game_action_npc_damage(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->npc_base_damage, 0, 100);
}

void ft_map_editor_game_action_world_gravity(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->coef_gravity, 0, 2);
}

void ft_map_editor_game_action_world_fall_damage(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->fall_damage == 0)
			l->fall_damage = 1;
		else
			l->fall_damage = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}
