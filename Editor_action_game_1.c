#include "header.h"

void		ft_map_editor_game_action_npc_health(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->npc_base_life, 1, 10);
}

void		ft_map_editor_game_action_npc_damage(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->npc_base_damage, 1, 10);
}

void		ft_map_editor_game_action_world_gravity(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_double(l, &l->coef_gravity, 0, 2);
}
