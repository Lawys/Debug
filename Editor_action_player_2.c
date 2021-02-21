#include "header.h"

void		ft_map_editor_player_action_item_pistol(variable_list *l)
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

void		ft_map_editor_player_action_item_grenade(variable_list *l)
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

void		ft_map_editor_player_action_item_telecommand(variable_list *l)
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

void		ft_map_editor_player_action_item_access_card(variable_list *l)
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

void		ft_map_editor_player_action_item_top_secret_box(variable_list *l)
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
