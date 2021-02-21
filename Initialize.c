#include "header.h"
void		ft_initialize_variables_triangles(variable_list *l)
{
	int i;

	i = -1;
	while (++i < MAX_TRIANGLES)
	{
		l->e.t_d[i] = 0;
		l->e.t_z1[i] = 0;
		l->e.t_z2[i] = 0;
		l->e.t_z3[i] = 0;
		l->e.t_x1[i] = 0;
		l->e.t_x2[i] = 0;
		l->e.t_x3[i] = 0;
		l->e.t_y1[i] = 0;
		l->e.t_y2[i] = 0;
		l->e.t_y3[i] = 0;
		l->e.t_id[i] = 0;
	}
}
void		ft_initialize_variables_groups(variable_list *l)
{
	int i;
	int j;

	i = -1;
	while (++i < MAX_GROUPS)
	{
		l->g.sprite[i] = 0;
		l->g.npc[i] = 0;
		l->g.no_block[i] = 0;
		l->action_v1[i] = 0;
		l->g.npc_o[i] = 0;
		l->g.npc_hp[i] = 3;
		l->g.npc_statement[i] = 0;
		l->g.npc_timer[i] = 1;
		l->g.exist[i] = 1;
		l->g.action_timer[i] = -1;
		l->g.action_statement[i] = 0;
		l->g.interact[i] = 0;
		j = -1;
		while (++j < 67)
		{
			l->g.action_enable[i][j] = 0;
			l->g.action_disable[i][j] = 0;

		}
	}
}
void		ft_initialize_variables_areas(variable_list *l)
{
	int i;

	i = -1;
	while (++i < MAX_AREAS)
	{
		l->link1[i] = -1;
		l->link2[i] = -1;
		l->link3[i] = -1;
		l->link4[i] = -1;
		l->link5[i] = -1;
		l->link6[i] = -1;
	}
}
void		ft_initialize_variables_1(variable_list *l)
{
	int i;
	int j;

	i = -1;
	while (++i < WDW)
	{
		l->e.first_y[i] = WDH;
		l->e.last_y[i] = -1;
	}
	i = -1;
	while (++i < 50)
	{
		j = -1;
		while (++j < 200)
			l->action_select[i][j] = 0;
	}
}
void		ft_initialize_variables_2(variable_list *l)
{
	l->player_area = 0;
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
	l->triangle_number = 0;
	l->texture_number = 0;
	l->group_number = 0;
	l->area_number = 0;
	l->p.x = -163.22;
	l->p.y = 190;
	l->p.z = -243.15;
	l->p.h = 0;
	l->p.v = 0;
	l->p.r = 0;
	l->writing_mode = 0;
	l->triangle_select = -1;
	l->area_select = -1;
	l->group_select = -1;
	l->menu_select = 0;
	l->i.save_mouse_x = 0;
	l->i.save_mouse_y = 0;
	l->texture_number = 0;
	l->me.area_switch_value = 1;
	l->me.group_switch_value = 1;
	l->e.view_distance = (double)WDW2 / tan(M_PI / 4);
	l->gravity = 0;
}
void		ft_initialize_variables_3(variable_list *l)
{
	l->cooldown = 0;
	l->me.color_white = l->texture_colors[10];
	l->me.color_blue = l->texture_colors[14];
	l->me.color_red = l->texture_colors[15];
	l->me.color_green = l->texture_colors[9];
	l->i.state = (Uint8*)SDL_GetKeyboardState(NULL);
	l->i.mouse = SDL_GetMouseState(&l->i.mouse_x, &l->i.mouse_y);
	l->menu_mode = 0;
	l->p.start_x = -375;
	l->p.start_y = 350;
	l->p.start_z = 840;
	l->p.start_hp = 100;
	l->p.start_item[0] = 1;
	l->p.start_item[1] = 1;
	l->p.start_item[2] = 0;
	l->p.start_item[3] = 0;
	l->p.start_item[4] = 0;
	l->p.start_item[5] = 0;
	l->p.hp = 100;
	l->p.animation_timer = 0;
	l->gr.gd = 0;
	l->npc_base_life = 3;
	l->npc_base_damage = 5;
	l->coef_gravity = 1;
}
void		ft_initialize_variables_4(variable_list *l)
{
	l->pe.pen_size = 0;
	l->pe.pen_texture = 0;
	l->pe.pen_group = 0;
	l->pe.pen_area = 0;
	l->pe.pen_opacity = 100;
	l->pe.pen_light = 100;
	l->view_only = 0;
	l->p.jump_timer = 0;
}
void		ft_initialize_skybox_1(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 43;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_2(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 43;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_3(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 45;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_4(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 45;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_5(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 47;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_6(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 47;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_7(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 48;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_8(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 48;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_9(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = 999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 46;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_10(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = 999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = 999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 46;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_11(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = -999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = -999999;
	l->t.x2[l->triangle_number] = -999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = 999999;
	l->t.x3[l->triangle_number] = 999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = -999999;
	l->t.texture_id[l->triangle_number] = 44;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = -100;
	l->t.texture_shift_y[l->triangle_number] = 0;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_skybox_12(variable_list *l)
{
	l->t.area[l->triangle_number] = 0;
	l->t.group[l->triangle_number] = 0;
	l->t.x1[l->triangle_number] = 999999;
	l->t.y1[l->triangle_number] = -999999;
	l->t.z1[l->triangle_number] = 999999;
	l->t.x2[l->triangle_number] = 999999;
	l->t.y2[l->triangle_number] = -999999;
	l->t.z2[l->triangle_number] = -999999;
	l->t.x3[l->triangle_number] = -999999;
	l->t.y3[l->triangle_number] = -999999;
	l->t.z3[l->triangle_number] = 999999;
	l->t.texture_id[l->triangle_number] = 44;
	l->t.texture_size_x[l->triangle_number] = 0.005;
	l->t.texture_size_y[l->triangle_number] = 0.005;
	l->t.texture_shift_x[l->triangle_number] = 0;
	l->t.texture_shift_y[l->triangle_number] = -100;
	l->t.texture_light[l->triangle_number] = 100;
	l->t.texture_opacity[l->triangle_number] = 100;
	l->t.texture_sides[l->triangle_number] = 0;
	l->triangle_number++;
}
void		ft_initialize_variables(variable_list *l)
{
	ft_initialize_variables_triangles(l);
	ft_initialize_variables_groups(l);
	ft_initialize_variables_areas(l);
	ft_initialize_variables_1(l);
	ft_initialize_variables_2(l);
	ft_initialize_variables_3(l);
	ft_initialize_variables_4(l);
	ft_initialize_skybox_1(l);
	ft_initialize_skybox_2(l);
	ft_initialize_skybox_3(l);
	ft_initialize_skybox_4(l);
	ft_initialize_skybox_5(l);
	ft_initialize_skybox_6(l);
	ft_initialize_skybox_7(l);
	ft_initialize_skybox_8(l);
	ft_initialize_skybox_9(l);
	ft_initialize_skybox_10(l);
	ft_initialize_skybox_11(l);
	ft_initialize_skybox_12(l);
}

void		ft_initialize_SDL(variable_list *l)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		_write(1, "Failed to initialize SDL\n", 26);
		free(l);
		exit(-1);
	}
	if (!(l->window = SDL_CreateWindow("Doom_nukem windows",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WDWF, WDHF, 0))) //SDL_WINDOW_FULLSCREEN
	{
		_write(1, "Failed to open window\n", 23);
		SDL_Quit();
		free(l);
		exit(-1);
	}
	if (!(l->window_surface = SDL_GetWindowSurface(l->window)))
	{
		_write(1, "Failed to GetWindowSurface\n", 28);
		SDL_DestroyWindow(l->window);
		SDL_Quit();
		free(l);
		exit(-1);
	}
	l->pixels = (Uint32*)l->window_surface->pixels;
}

void		ft_reset_arrays(variable_list *l)
{
	int i;
	int j;

	i = -1;
	while (++i < WDW)
	{
		j = -1;
		while (++j < WDH)
		{
			l->pixels_distance[i][j] = 9999999;
			l->pixels_triangle[i][j] = -1;
		}
	}
}
void		ft_map_reader_error(variable_list *l, char *file, double value, double min, double max)
{
	if (value < min || value > max)
	{
		free(file);
		ft_free_and_exit(l, "Load File Error\n");
	}
}
void		ft_reader(variable_list *l)
{
	FILE *stream;
	int fd;
	int size;
	char *file;
	int i;
	int j;
	int k;

	/// For mapping
	if ((fopen_s(&stream, "./FILE", "r")) != 0)
	{
		ft_free_and_exit(l, "Load File Error\n");
	}
	fseek(stream, 0, SEEK_END);
	size = ftell(stream);
	printf("Loaded file size: %d\n", size);
	fclose(stream);
	file = (char*)malloc((size + 1) * sizeof(char));
	if ((_sopen_s(&fd, "./FILE", 0,_SH_DENYNO, 0)) != 0)
	{
		ft_free_and_exit(l, "Load File Error\n");
	}
	_read(fd, file, size);
	file[size] = '\0';
	_close(fd);
	i = -1;
	l->texture_number = 49;
	while (++i < (1024 * 1024 * 4 * 49) && i <= size)
	{
		if (i % (1024 * 1024 * 4) == 0)
		{
			j = 0;
			l->texture_number--;
		}
		l->texture_colors[l->texture_number][j] = file[i];
		j++;
	}
	l->texture_number = 49;
	_write(1, "Textures OK.\n", 13);

	if (i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}

	while (i + 3 <= size && file[i + 3] != '#')
	{
		l->t.area[l->triangle_number] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.area[l->triangle_number], 1, MAX_AREAS - 1);
		l->t.group[l->triangle_number] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.group[l->triangle_number], 1, MAX_GROUPS - 1);
		l->t.x1[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.x1[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.y1[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.y1[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.z1[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.z1[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.x2[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.x2[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.y2[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.y2[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.z2[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.z2[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.x3[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.x3[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.y3[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.y3[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.z3[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.z3[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.texture_id[l->triangle_number] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_id[l->triangle_number], 0, (double)l->texture_number - 1);
		l->t.texture_size_x[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_size_x[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.texture_size_y[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_size_y[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.texture_shift_x[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_shift_x[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.texture_shift_y[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_shift_y[l->triangle_number], -MAX_GENERIC, MAX_GENERIC);
		l->t.texture_light[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_light[l->triangle_number], 0, 100);
		l->t.texture_opacity[l->triangle_number] = ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_opacity[l->triangle_number], 10, 100);
		l->t.texture_sides[l->triangle_number] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->t.texture_sides[l->triangle_number], -1, 1);
		l->triangle_number++;
	}
	_write(1, "Triangles OK.\n", 14);

	if (i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}

	i++;
	j = 0;
	while (i + 3 <= size && file[i + 3] != '#' && i <= size)
	{
		l->g.sprite[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->g.sprite[j], 0, 1);
		l->g.npc[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->g.npc[j], 0, 1);
		l->g.no_block[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->g.no_block[j], 0, 1);
		l->g.interact[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->g.interact[j], 0, 1);
		k = 0;
		while (++i <= size && file[i] != ',' && k < 57
			&& file[i] >= '!' && file[i] <= 'Z')
		{
			l->g.action_enable[j][k] = file[i];
			k++;
		}
		k = 0;
		while (++i <= size && file[i] != ',' && k < 57
			&& file[i] >= '!' && file[i] <= 'Z')
		{
			l->g.action_disable[j][k] = file[i];
			k++;
		}
		j++;
	}
	_write(1, "Groups OK.\n", 11);

	if (i == size)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}

	i++;
	j = 0;
	while (i + 3 <= size && file[i + 3] != '#')
	{
		l->link1[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link1[j], -1, MAX_AREAS - 1);
		l->link2[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link2[j], -1, MAX_AREAS - 1);
		l->link3[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link3[j], -1, MAX_AREAS - 1);
		l->link4[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link4[j], -1, MAX_AREAS - 1);
		l->link5[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link5[j], -1, MAX_AREAS - 1);
		l->link6[j] = (int)ft_atoi(l, file, &i);
		ft_map_reader_error(l, file, l->link6[j], -1, MAX_AREAS - 1);
		j++;
	}
	_write(1, "Areas OK.\n", 10);

	if (i != size - 6)
	{
		free(file);
		ft_free_and_exit(l, "FILE Error\n");
	}
	free(file);
}
void		ft_engine_set_window_blue_border_triangle1(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->pixels_triangle[j][i] == l->triangle_select)
			{
				l->pixels_color[j][i] = 0x0000FF;
				while (j < WDW && l->pixels_triangle[j][i] == l->triangle_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0x0000FF;
			}
			j++;
		}
		i++;
	}
}
void		ft_engine_set_window_blue_border_triangle2(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->pixels_triangle[i][j] == l->triangle_select)
			{
				l->pixels_color[i][j] = 0x0000FF;
				while (j < WDH && l->pixels_triangle[i][j] == l->triangle_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0x0000FF;
			}
			j++;
		}
		i++;
	}
}

void		ft_engine_set_window_red_border_area1(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->t.area[l->pixels_triangle[j][i]] == l->area_select)
			{
				l->pixels_color[j][i] = 0xFF0000;
				while (j < WDW && l->t.area[l->pixels_triangle[j][i]] == l->area_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0xFF0000;
			}
			j++;
		}
		i++;
	}
}
void		ft_engine_set_window_red_border_area2(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->t.area[l->pixels_triangle[i][j]] == l->area_select)
			{
				l->pixels_color[i][j] = 0xFF0000;
				while (j < WDH && l->t.area[l->pixels_triangle[i][j]] == l->area_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0xFF0000;
			}
			j++;
		}
		i++;
	}
}
void		ft_engine_set_window_green_border_group1(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDH)
	{
		j = 0;
		while (j < WDW)
		{
			if (l->t.group[l->pixels_triangle[j][i]] == l->group_select)
			{
				l->pixels_color[j][i] = 0x00FF00;
				while (j < WDW && l->t.group[l->pixels_triangle[j][i]] == l->group_select)
					j++;
				j--;
				l->pixels_color[j][i] = 0x00FF00;
			}
			j++;
		}
		i++;
	}
}
void		ft_engine_set_window_green_border_group2(variable_list *l)
{
	int i;
	int j;

	i = 0;
	while (i < WDW)
	{
		j = 0;
		while (j < WDH)
		{
			if (l->t.group[l->pixels_triangle[i][j]] == l->group_select)
			{
				l->pixels_color[i][j] = 0x00FF00;
				while (j < WDH && l->t.group[l->pixels_triangle[i][j]] == l->group_select)
					j++;
				j--;
				l->pixels_color[i][j] = 0x00FF00;
			}
			j++;
		}
		i++;
	}
}

void		ft_size_to_window(variable_list *l)
{
	int i;
	int j;
	int k;
	int n;

	i = 0;
	while (i < WDHF)
	{
		j = 0;
		while (j < WDWF)
		{
			k = -1;
			while (++k < 2)
			{
				n = -1;
				while (++n < 2)
					if (l->pixels_distance[j / 2][i / 2] > 0)
						l->pixels[(k + i) * (WDWF)+(j + n)] =
						l->pixels_color[j / 2][i / 2];
			}
			j += 2;
		}
		i += 2;
	}
}

void		ft_loop_menu_1(variable_list *l)
{
	ft_npc(l);
	ft_engine_play_p(l);
	ft_size_to_window(l);
	ft_hud_play(l);
	ft_action(l);
}

void		ft_loop_menu_2(variable_list *l)
{
	ft_engine_play_me(l);
	if (l->triangle_select != -1)
	{
		ft_engine_set_window_blue_border_triangle1(l);
		ft_engine_set_window_blue_border_triangle2(l);
	}
	else if (l->area_select != -1)
	{
		ft_engine_set_window_red_border_area1(l);
		ft_engine_set_window_red_border_area2(l);
	}
	else if (l->group_select != -1)
	{
		ft_engine_set_window_green_border_group1(l);
		ft_engine_set_window_green_border_group2(l);
	}
	ft_size_to_window(l);
	ft_map_editor(l);
}

void		ft_loop_menu_3(variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[33];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 0;
	l->u.wsy = 0;
	ft_put_texture(l);
	if (l->i.state[SDL_SCANCODE_RETURN])
		ft_free_and_exit(l, "You lose.\n");
}

void		ft_loop_menu_4(variable_list *l)
{
	l->u.action = -1;
	l->u.colors = l->texture_colors[36];
	l->u.tsx = 0;
	l->u.tex = 1024;
	l->u.tsy = 0;
	l->u.tey = 1024;
	l->u.sizex = (double)WDWF / 1024;
	l->u.sizey = (double)WDHF / 1024;
	l->u.size = 1;
	l->u.wsx = 0;
	l->u.wsy = 0;
	ft_put_texture(l);
	if (l->i.state[SDL_SCANCODE_RETURN])
		ft_free_and_exit(l, "You win.\n");
}
void		ft_loop(variable_list *l)
{
	while (1)
	{
		if (SDL_UpdateWindowSurface(l->window) < 0)
			ft_free_and_exit(l, "SDL_UpdateWindowSurface Error\n");
		ft_reset_arrays(l);
		if (l->menu_mode == 0)
			ft_hud_main_menu(l);
		else
		{
			if (l->menu_mode == 1)
				ft_loop_menu_1(l);
			else if (l->menu_mode == 2)
				ft_loop_menu_2(l);
			else if (l->menu_mode == 3)
				ft_loop_menu_3(l);
			else if (l->menu_mode == 4)
				ft_loop_menu_4(l);
			ft_get_time(l);
		}
		ft_events(l);
	}
}

int main(void)
{
	variable_list *l;

	if (!(l = malloc(sizeof(variable_list))))
		exit(-1);
	ft_initialize_variables(l);
	ft_initialize_SDL(l);
	ft_reader(l);
	ft_loop(l);
	return(0);
}