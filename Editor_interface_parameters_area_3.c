#include "header.h"

void		ft_map_editor_area_parameter_position_size(variable_list *l)
{
	l->u.str_address = "SIZE";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link(variable_list *l)
{
	l->u.str_address = "LINK";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	l->u.action = -1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link1(variable_list *l)
{
	ft_itoa(l, l->link1[l->area_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link2(variable_list *l)
{
	ft_itoa(l, l->link2[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link3(variable_list *l)
{
	ft_itoa(l, l->link3[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}
