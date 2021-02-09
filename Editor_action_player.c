#include "header.h"


void ft_map_editor_player_action_x(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_x, -MAX_GENERIC, MAX_GENERIC);
}

void ft_map_editor_player_action_y(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_y, -MAX_GENERIC, MAX_GENERIC);
}

void ft_map_editor_player_action_z(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_z, -MAX_GENERIC, MAX_GENERIC);
}

void ft_map_editor_player_action_hp(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_hp, 0, 100);
}

void ft_map_editor_player_action_ammo(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
		ft_value_editing_int(l, &l->p.start_ammo, 0, 24);
}

void ft_map_editor_player_action_item_bare_hands(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[0] == 0)
			l->p.start_item[0] = 1;
		else
			l->p.start_item[0] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_player_action_item_pistol(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[1] == 0)
			l->p.start_item[1] = 1;
		else
			l->p.start_item[1] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_player_action_item_grenade(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[2] == 0)
			l->p.start_item[2] = 1;
		else
			l->p.start_item[2] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_player_action_item_telecommand(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[3] == 0)
			l->p.start_item[3] = 1;
		else
			l->p.start_item[3] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_player_action_item_access_card(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[4] == 0)
			l->p.start_item[4] = 1;
		else
			l->p.start_item[4] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}

void ft_map_editor_player_action_item_top_secret_box(variable_list* l)
{
	if (l->action_select[l->menu_select][++l->action])
	{
		if (l->p.start_item[5] == 0)
			l->p.start_item[5] = 1;
		else
			l->p.start_item[5] = 0;
		l->action_select[l->menu_select][l->action] = 0;
	}
}