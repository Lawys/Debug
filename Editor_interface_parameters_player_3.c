#include "header.h"

void		ft_map_editor_player_parameter_item_access_card(variable_list* l)
{
	l->u.str_address = "<ACCESS CARD>";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[4])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}

void		ft_map_editor_player_parameter_item_top_secret_box(variable_list* l)
{
	l->u.str_address = "<TOP SECRET BOX>";
	l->u.action = ++l->action;
	l->u.colors_on = l->me.color_green;
	if (l->p.start_item[5])
		l->u.colors = l->me.color_green;
	else
		l->u.colors = l->me.color_blue;
	ft_put_text(l);
}
