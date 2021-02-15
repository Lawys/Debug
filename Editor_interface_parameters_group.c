#include "header.h"

void	ft_map_editor_group_parameter_group(variable_list* l)
{
	l->u.str_address = "GROUP";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_group_id(variable_list* l)
{
	l->u.str_address = "ID";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->group_select, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_switch(variable_list* l)
{
	l->u.str_address = ">>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->me.group_switch_value, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position(variable_list* l)
{
	l->u.str_address = "POSITION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_x(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_y(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_z(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_h(variable_list* l)
{
	l->u.str_address = "H";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_v(variable_list* l)
{
	l->u.str_address = "V";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_l(variable_list* l)
{
	l->u.str_address = "L";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_position_size(variable_list* l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_action(variable_list* l)
{
	l->u.str_address = "ACTION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_enable(variable_list* l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "ENABLE";
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_disable(variable_list* l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "DISABLE";
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_flag(variable_list* l)
{
	l->u.str_address = "FLAG";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_sprite(variable_list* l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.sprite[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<SPRITE>";
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_npc(variable_list* l)
{
	l->u.action = ++l->action;
	if (l->g.npc[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<NPC>";
	l->u.wsx += 0.5;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_no_block(variable_list* l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.no_block[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<NO BLOCK>";
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_interact(variable_list* l)
{
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	if (l->g.interact[l->group_select] == 0)
	{
		l->u.colors = l->me.color_blue;
		l->u.colors_on = l->me.color_green;
	}
	else
	{
		l->u.colors = l->me.color_green;
		l->u.colors_on = l->me.color_green;
	}
	l->u.str_address = "<INTERACT>";
	ft_put_text(l);
}



void	ft_map_editor_group_parameter_options(variable_list* l)
{
	l->u.str_address = "OPTIONS";
	l->u.wsx = 37;
	l->u.wsy = 94.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_red;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_group_parameter_create_npc(variable_list* l)
{
	l->u.str_address = "<CREATE NPC>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_duplicate(variable_list* l)
{
	l->u.str_address = "<DUPLICATE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_group_parameter_delete(variable_list* l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}