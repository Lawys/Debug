#include "header.h"

void	ft_map_editor_player_parameter_position(variable_list* l)
{
	l->u.str_address = "POSITION";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_x(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->p.start_x, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_y(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->p.start_y, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_z(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->p.start_z, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_provision(variable_list* l)
{
	l->u.str_address = "PROVISION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_hp(variable_list* l)
{
	l->u.str_address = "HEALTH";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->p.start_hp, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_ammo(variable_list* l)
{
	l->u.str_address = "AMMO";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->p.start_ammo, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item(variable_list* l)
{
	l->u.str_address = "ITEM";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_bare_hands(variable_list* l)
{
	l->u.str_address = "<BARE HANDS>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[0])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_pistol(variable_list* l)
{
	l->u.str_address = "<PISTOL>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[1])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_grenade(variable_list* l)
{
	l->u.str_address = "<GRENADE>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[2])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_telecommand(variable_list* l)
{
	l->u.str_address = "<TELECOMMAND>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[3])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_access_card(variable_list* l)
{
	l->u.str_address = "<ACCESS CARD>";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[4])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
void	ft_map_editor_player_parameter_item_top_secret_box(variable_list* l)
{
	l->u.str_address = "<TOP SECRET BOX>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[5])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}