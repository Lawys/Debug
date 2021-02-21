#include "header.h"

void		ft_map_editor_menu_parameter_game(variable_list* l)
{
	l->u.str_address = "GAME";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_paint(variable_list* l)
{
	l->u.str_address = "PAINT";
	l->u.wsx = 4.5;
	l->u.action = ++l->action;
	l->u.wsy += 3;
	ft_put_text(l);
}

void		ft_map_editor_menu_parameter_view_only(variable_list* l)
{
	l->u.str_address = "VIEW ONLY AREA";
	l->u.wsx = 4.5;
	l->u.action = ++l->action;
	l->u.wsy += 3;
	l->u.size = 0.80;
	ft_put_text(l);
	ft_itoa(l, l->view_only, l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 1;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
