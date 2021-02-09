#include "header.h"

void	ft_map_editor_game_parameter_mission(variable_list* l)
{
	l->u.str_address = "MISSION";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_mission_kill_all_npc(variable_list* l)
{
	l->u.str_address = "<KILL ALL ENEMIES>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->mission[0])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_mission_steal_top_secret_box(variable_list* l)
{
	l->u.str_address = "<STEAL TOP SECRET BOX>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->mission[1])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_mission_destroy_computers(variable_list* l)
{
	l->u.str_address = "<DESTROY COMPUTERS>";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->mission[2])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_mission_steal_no_alarm(variable_list* l)
{
	l->u.str_address = "<NO ALARM>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->mission[3])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_npc(variable_list* l)
{
	l->u.str_address = "NPC";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_npc_health(variable_list* l)
{
	l->u.str_address = "HEALTH";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->npc_base_life, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_npc_damage(variable_list* l)
{
	l->u.str_address = "DAMAGE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->npc_base_damage, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_world(variable_list* l)
{
	l->u.str_address = "WORLD";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_world_gravity(variable_list* l)
{
	l->u.str_address = "GRAVITY";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->coef_gravity, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_game_parameter_world_fall_damage(variable_list* l)
{
	l->u.str_address = "<FALL DAMAGE>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->fall_damage)
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}