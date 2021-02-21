#include "header.h"

void		ft_map_editor_group_parameter_position_size(variable_list* l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_action(variable_list* l)
{
	l->u.str_address = "ACTION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_enable(variable_list* l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "ENABLE";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_disable(variable_list* l)
{
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.str_address = "DISABLE";
	ft_put_text(l);
}

void		ft_map_editor_group_parameter_flag(variable_list* l)
{
	l->u.str_address = "FLAG";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.action = -1;
	l->u.colors = l->me.color_white;
	ft_put_text(l);
}
