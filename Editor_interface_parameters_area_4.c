#include "header.h"

void		ft_map_editor_area_parameter_link4(variable_list* l)
{
	ft_itoa(l, l->link4[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link5(variable_list* l)
{
	ft_itoa(l, l->link5[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_link6(variable_list* l)
{
	ft_itoa(l, l->link6[l->area_select], l->me.str);
	l->u.action = ++l->action;
	l->u.wsx += 1;
	ft_put_text(l);
}

void		ft_map_editor_area_parameter_options(variable_list* l)
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

void		ft_map_editor_area_parameter_delete(variable_list* l)
{
	l->u.str_address = "<DELETE>";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}
