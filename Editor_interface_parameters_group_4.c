#include "header.h"

void		ft_map_editor_group_parameter_sprite(variable_list* l)
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

void		ft_map_editor_group_parameter_npc(variable_list* l)
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

void		ft_map_editor_group_parameter_no_block(variable_list* l)
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

void		ft_map_editor_group_parameter_interact(variable_list* l)
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

void		ft_map_editor_group_parameter_options(variable_list* l)
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
