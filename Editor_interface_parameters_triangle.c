#include "header.h"

void	ft_map_editor_triangle_parameter_triangle(variable_list* l)
{
	l->u.str_address = "TRIANGLE";
	l->u.wsx = 37;
	l->u.wsy = 74.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_triangle_id(variable_list* l)
{
	l->u.str_address = "ID";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->triangle_select, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_area(variable_list* l)
{
	l->u.str_address = "AREA";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.area[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_group(variable_list* l)
{
	l->u.str_address = "GROUP";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.group[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position(variable_list* l)
{
	l->u.str_address = "POSITION";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = -1;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_x_all(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.size = 1;
	l->u.action = ++l->action;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_y_all(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_z_all(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_size(variable_list* l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_rotation(variable_list* l)
{
	l->u.str_address = "ROTATION";
	l->u.wsx += 1;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_h(variable_list* l)
{
	l->u.str_address = "H";
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_v(variable_list* l)
{
	l->u.str_address = "V";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_l(variable_list* l)
{
	l->u.str_address = "L";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_x_1(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.x1[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_y_1(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.y1[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_z_1(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.z1[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}


void	ft_map_editor_triangle_parameter_position_x_2(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.x2[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_y_2(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.y2[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_z_2(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.z2[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}


void	ft_map_editor_triangle_parameter_position_x_3(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.x3[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_y_3(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.y3[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_position_z_3(variable_list* l)
{
	l->u.str_address = "Z";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.z3[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture(variable_list* l)
{
	l->u.str_address = "TEXTURE";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_id(variable_list* l)
{
	l->u.str_address = "ID";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_id[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_light(variable_list* l)
{
	l->u.str_address = "LIGHT";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_light[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_opacity(variable_list* l)
{
	l->u.str_address = "OPACITY";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_opacity[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_size(variable_list* l)
{
	l->u.str_address = "SIZE";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_blue;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_size_x(variable_list* l)
{
	l->u.str_address = "X";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_size_x[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_size_y(variable_list* l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_size_y[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_shift(variable_list* l)
{
	l->u.str_address = "SHIFT";
	l->u.wsx += 1;
	l->u.size = 0.80;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_blue;
	l->u.action = -1;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_shift_x(variable_list* l)
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

void	ft_map_editor_triangle_parameter_texture_shift_y(variable_list* l)
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

void	ft_map_editor_triangle_parameter_texture_size_adapt(variable_list* l)
{
	l->u.str_address = "AUTO TEXTURE";
	l->u.wsy += 2.5;
	l->u.action = -1;
	l->u.wsx = 37;
	l->u.colors = l->me.color_red;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_size_stretch(variable_list* l)
{
	l->u.str_address = "<STRETCH>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_size_repeat(variable_list* l)
{
	l->u.str_address = "<REPEAT>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_size_adapt_x(variable_list* l)
{
	l->u.str_address = "<X>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
void	ft_map_editor_triangle_parameter_texture_size_adapt_y(variable_list* l)
{
	l->u.str_address = "<Y>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}


void	ft_map_editor_triangle_parameter_texture_sides(variable_list* l)
{
	l->u.str_address = "SIDES";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l, l->t.texture_sides[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_options(variable_list* l)
{
	l->u.str_address = "OPTIONS";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = -1;

	l->u.colors = l->me.color_red;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_create_new(variable_list* l)
{
	l->u.str_address = "<NEW>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_create_square(variable_list* l)
{
	l->u.str_address = "<SQUARE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_duplicate(variable_list* l)
{
	l->u.str_address = "<DUPLICATE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_delete(variable_list* l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void	ft_map_editor_triangle_parameter_texture_view(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[(int)l->t.texture_id[l->triangle_select]];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024 * ((double)WDHF / (double)WDWF);
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 0.11;
	l->u.wsx = 88;
	l->u.wsy = 74.5;
	ft_put_texture(l);
}
