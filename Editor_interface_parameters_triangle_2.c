#include "header.h"

void		ft_map_editor_triangle_parameter_position_x_all(variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.size = 1;
	l->u.action = ++l->action;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_y_all(variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_z_all(variable_list *l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_size(variable_list *l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_rotation(variable_list *l)
{
	l->u.str_address = "ROTATION";
	l->u.wsx += 1;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
