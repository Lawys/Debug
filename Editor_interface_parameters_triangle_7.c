#include "header.h"

void		ft_map_editor_triangle_parameter_texture_shift_x(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_shift_x[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_shift_y(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_shift_y[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_adapt(variable_list* l)
{
	l->u.str_address = "AUTO TEXTURE";
	l->u.wsy += 2.5;
	l->u.action = -1;
	l->u.wsx = 37;
	l->u.colors = l->me.color_red;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_stretch(variable_list* l)
{
	l->u.str_address = "<STRETCH>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_texture_size_repeat(variable_list* l)
{
	l->u.str_address = "<REPEAT>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
