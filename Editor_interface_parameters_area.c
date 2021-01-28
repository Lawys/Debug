#include "header.h"

void	ft_map_editor_area_parameter_area(variable_list* l)
{
	l->u.str_address = "AREA";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_area_id(variable_list* l)
{
	l->u.str_address = "ID";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->area_select, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_switch(variable_list* l)
{
	l->u.str_address = ">>";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->me.area_switch_value, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position(variable_list* l)
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

void	ft_map_editor_area_parameter_position_x(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_y(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_z(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_h(variable_list* l)
{
	l->u.str_address = "H";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_v(variable_list* l)
{
	l->u.str_address = "V";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_l(variable_list* l)
{
	l->u.str_address = "L";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_position_size(variable_list* l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_options(variable_list* l)
{
	l->u.str_address = "OPTIONS";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_red;
	ft_put_text(l);
}

void	ft_map_editor_area_parameter_delete(variable_list* l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}