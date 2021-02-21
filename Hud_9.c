#include "header.h"

void		ft_hud_main_menu_play(variable_list *l)
{
	int i;

	l->p.x = l->p.start_x;
	l->p.y = l->p.start_y;
	l->p.z = l->p.start_z;
	l->p.hp = l->p.start_hp;
	l->p.item[0] = l->p.start_item[0];
	l->p.item[1] = l->p.start_item[1];
	l->p.item[2] = l->p.start_item[2];
	l->p.item[3] = l->p.start_item[3];
	l->p.item[4] = l->p.start_item[4];
	l->p.item[5] = l->p.start_item[5];
	i = -1;
	while (++i < 6)
		if (l->p.item[i] == 1)
		{
			l->p.item[i] = 2;
			break;
		}
	SDL_ShowCursor(0);
	l->menu_mode = 1;
}

void		ft_hud_main_menu_editor(variable_list *l)
{
	int i;

	i = -1;
	while (++i < MAX_GROUPS)
		l->g.exist[i] = 1;
	SDL_ShowCursor(1);
	l->menu_mode = 2;
}

void		ft_hud_main_menu(variable_list *l)
{
	ft_hud_main_menu_display(l);
	if (l->i.mouse == 1 && l->i.mouse_time_pressing == 1)
	{
		if (l->i.mouse_x > (308. * WDHF) / 1024 &&
			l->i.mouse_x < (743. * WDWF) / 1024)
			if (l->i.mouse_y > (359. * WDHF) / 1024 &&
				l->i.mouse_y < (499. * WDHF) / 1024)
				ft_hud_main_menu_play(l); //GAME
			else if (l->i.mouse_y > (529. * WDHF) / 1024 &&
				l->i.mouse_y < (668. * WDHF) / 1024)
				ft_hud_main_menu_editor(l); //EDITOR
			else if (l->i.mouse_y > (698. * WDHF) / 1024 &&
				l->i.mouse_y < (838. * WDHF) / 1024)
				ft_free_and_exit(l, "EXIT\n"); //EXIT
	}
}
