#include "header.h"
void	ft_map_editor_tool_set_mult(variable_list* l)
{
	l->me.mult = 100;
	if (l->i.state[225])
		l->me.mult = 1000;
	else if (l->i.state[224])
		l->me.mult = 10000;
	if (l->i.state[226])
		l->me.mult = 1;
		
}
void	ft_map_editor_menu_background(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 1600;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 2.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);

}
void	ft_map_editor_submenu_background(variable_list* l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[16];
	l->u.tsx = 250;
	l->u.tex = 777;
	l->u.tsy = 415;
	l->u.tey = 674;
	l->u.sizex = (double)WDWF / 820;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 34.5;
	l->u.wsy = 72.5;
	ft_put_texture(l);
}

void	ft_map_editor_menu_parameters(variable_list* l)
{

	ft_map_editor_menu_background(l);
	ft_map_editor_menu_parameter_triangle(l);
	ft_map_editor_menu_parameter_area(l);
	ft_map_editor_menu_parameter_group(l);
	ft_map_editor_menu_parameter_light(l);
	ft_map_editor_menu_parameter_player(l);
	ft_map_editor_menu_parameter_game(l);
	ft_map_editor_menu_parameter_paint(l);
	ft_map_editor_menu_parameter_view_only(l);
}
void	ft_map_editor_menu(variable_list* l)
{
	int i;
	int j;

	if (l->action_select[0][0] == 1)
	{
		l->menu_select = 0;
		l->action = 0;
		ft_map_editor_menu_parameters(l);
		TMP_map_editor_menu_parameter_save_map(l);
		l->action = 0;
		if (l->action_select[0][8])
		{
			ft_value_editing_int(l, &l->view_only, 0, MAX_AREAS - 1);
		}
		TMP_map_editor_save_map(l);
	}
	else if (l->action_select[0][0] == 0)
	{
		l->triangle_select = -1;
		l->area_select = -1;
		l->group_select = -1;
		l->light_select = -1;
		l->action_select[0][0]++;
	}
}

void	ft_map_editor(variable_list* l)
{
	l->writing_mode = 0;
	ft_map_editor_tool_set_mult(l);
	ft_map_editor_menu(l);
	ft_map_editor_triangle(l);
	ft_map_editor_area(l);
	ft_map_editor_group(l);
	//ft_map_editor_light(l);
	ft_map_editor_player(l);
	ft_map_editor_game(l);
	ft_map_editor_paint(l);
}

void	TMP_map_editor_save_map(variable_list* l)
{
	if (l->action_select[0][9] == 1)
	{
		int i;
		int buffer_size;
		char buffer[15];
		int stream;
		buffer_size = 15;

		printf("Saving...\n");
		if ((_sopen_s(&stream, "./map/triangle", O_RDWR | _O_CREAT,
			_SH_DENYNO, _S_IREAD | _S_IWRITE)) != 0)
		{
			printf("Load File Error\n");
			ft_free_and_exit(l);
		}
		printf("Triangle number: %d\n", l->triangle_number);
		_write(stream, "area,group,(POSITIONS)x,y,z,x,y,z,x,y,z,(TEXTURE)id,sizex,sizey,shiftx,shifty,light,opacity,sides\0", 97);
		i = 12;
		while (i < l->triangle_number)
		{
			_write(stream, ",\n\0", 2);
			buffer_size = ft_itoa(l, l->t.area[i], buffer), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.group[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z1[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.x3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.y3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.z3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_id[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_size_x[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_size_y[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_shift_x[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_shift_y[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_light[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_opacity[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->t.texture_sides[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			i++;
		}
		_write(stream, ",\0\0", 2);
		_close(stream);

		if ((_sopen_s(&stream, "./map/group", O_RDWR | _O_CREAT,
			_SH_DENYNO, _S_IREAD | _S_IWRITE)) != 0)
		{
			printf("Load File Error\n");
			ft_free_and_exit(l);
		}
		_write(stream, "sprite,npc,object,action_enable,action_disable\0", 46);
		i = -1;
		while (++i < MAX_GROUPS)
		{
			_write(stream, ",\n\0", 2);
			buffer_size = ft_itoa(l, l->g.sprite[i], buffer), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->g.npc[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->g.object[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			_write(stream, ",\0", 1), _write(stream, l->g.action_enable[i], sizeof(l->g.action_enable[i]));
			_write(stream, ",\0", 1), _write(stream, l->g.action_disable[i], sizeof(l->g.action_disable[i]));
		}
		_write(stream, ",\0\0", 2);
		_close(stream);

		if ((_sopen_s(&stream, "./map/area", O_RDWR | _O_CREAT,
			_SH_DENYNO, _S_IREAD | _S_IWRITE)) != 0)
		{
			printf("Load File Error\n");
			ft_free_and_exit(l);
		}
		_write(stream, "link,link,link,link,link,link\0", 29);
		i = -1;
		while (++i < MAX_AREAS)
		{
			_write(stream, ",\n\0", 2);
			buffer_size = ft_itoa(l, l->link1[i], buffer), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->link2[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->link3[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->link4[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->link5[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
			buffer_size = ft_itoa(l, l->link6[i], buffer), _write(stream, ",\0", 1), _write(stream, buffer, buffer_size);
		}
		_write(stream, ",\0\0", 2);
		_close(stream);


		printf("Done.\n");
		l->action_select[0][9] = 0;
	}
}
