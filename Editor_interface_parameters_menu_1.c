#include "header.h"

void		ft_map_editor_menu_parameter_triangle(variable_list* l)
{
	l->u.str_address = "TRIANGLE";
	l->u.wsx = 4.5;
	l->u.wsy = 74.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_area(variable_list* l)
{
	l->u.str_address = "AREA";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_group(variable_list* l)
{
	l->u.str_address = "GROUP";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_light(variable_list* l)
{
	l->u.str_address = "LIGHT";
	l->u.wsx = 4.5;
	l->u.wsy += 3;
	++l->action;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_player(variable_list* l)
{
	l->u.str_address = "PLAYER";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}
