#include "header.h"

void	ft_initialize_variables(variable_list* l)
{
	int i, j;

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
	i = -1;
	while (++i < MAX_GROUPS)
	{
		l->g.sprite[i] = 0;
		l->g.npc[i] = 0;
		l->g.object[i] = 0;
		l->action_v1[i] = 0;
		l->g.sprite_orientation[i] = 0;
		l->g.npc_hp[i] = 100;
		l->g.npc_statement[i] = 0;
		l->g.exist[i] = 1;
		j = -1;
		while (++j < 57)
		{
			l->g.action_auto[i][j] = 0;
			l->g.action_enable[i][j] = 0;
			l->g.action_disable[i][j] = 0;
		}
	}

	i = -1;
	while (++i < WDW)
	{
		l->e.first_y[i] = WDH;
		l->e.last_y[i] = -1;
	}
	i = -1;
	while (++i < WDW)
	{
		j = -1;
		while (++j < WDH)
		{
			l->pixels_distance[i][j] = 999999;
			l->pixels_triangle[i][j] = -1;
		}
	}
	i = -1;
	while (++i < MAX_AREAS)
		l->area_list[i] = 0;


	i = -1;
	while (++i < 50)
	{
		j = -1;
		while (++j < 200)
		{
			l->action_select[i][j] = 0;
		}
	}




		l->i.save_mouse_x = 0;
		l->i.save_mouse_y = 0;
		l->triangle_number = 0;
		l->light_number = 0;
		l->texture_number = 0;
		l->group_number = 0;
		l->area_number = 0;

		l->writing_mode = 0;
		l->p.x = -163.22;
		l->p.y = 190;
		l->p.z = -243.15;
		l->p.h = 0;
		l->p.v = 0;
		l->p.r = 0;

		l->triangle_select = -1;
		l->area_select = -1;
		l->group_select = -1;
		l->light_select = -1;
		l->menu_select = 0;

		l->i.save_mouse_x = 0;
		l->i.save_mouse_y = 0;

		l->triangle_number = 0;
		l->light_number = 0;
		l->texture_number = 0;

		l->me.area_switch_value = 0;
		l->me.group_switch_value = 0;

		l->e.view_distance = (double)WDW2 / tan(M_PI / 4);
		l->gravity = 0;
		l->cooldown = 0;
		l->playing_mode = 0;
		l->map_editor_mode = 1;
		l->me.color_white = l->texture_colors[10];
		l->me.color_blue = l->texture_colors[14];
		l->me.color_red = l->texture_colors[15];
		l->me.color_green = l->texture_colors[9];
		l->i.state = SDL_GetKeyboardState(NULL);
		l->i.mouse = SDL_GetMouseState(&l->i.mouse_x, &l->i.mouse_y);
		//RVOLBERG

		//objet du hud
		l->hl.item_select = -1;
		l->menu_mode = 0;//

		l->p.start_x = l->p.x;
		l->p.start_y = l->p.y;
		l->p.start_z = l->p.z;
		l->p.start_hp = 100;
		l->p.start_ammo = 24;
		l->p.start_item[0] = 1;
		l->p.start_item[1] = 1;
		l->p.start_item[2] = 0;
		l->p.start_item[3] = 0;
		l->p.start_item[4] = 0;
		l->p.start_item[5] = 0;
		l->p.start_item[6] = 0;
		l->p.start_item[7] = 0;
		l->p.start_item[8] = 0;
		l->npc_base_life = 100;
		l->npc_base_damage = 1;
		l->mission[0] = 0;
		l->mission[1] = 1;
		l->mission[2] = 0;
		l->mission[3] = 0;
		l->coef_gravity = 1;
		l->fall_damage = 1;

		l->pen_size = 0;
		l->pen_texture = 0;
		l->pen_group = 0;
		l->pen_area = 0;
		l->pen_opacity = 100;
		l->pen_light = 100;


		l->view_only = 0;

}

void	ft_initialize_SDL(variable_list* l)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		printf("Failed to initialize SDL\n");
		free(l);
		exit(-1);
	}
	if (!(l->window = SDL_CreateWindow("Doom_nukem windows",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WDWF, WDHF, 0))) //SDL_WINDOW_FULLSCREEN
	{
		printf("Failed to open window\n");
		SDL_Quit();
		free(l);
		exit(-1);
	}
	if (!(l->window_surface = SDL_GetWindowSurface(l->window)))
	{
		printf("Failed to GetWindowSurface\n");
		SDL_DestroyWindow(l->window);
		SDL_Quit();
		free(l);
		exit(-1);
	}
	l->pixels = (Uint32*)l->window_surface->pixels;
}

void	ft_read_all(variable_list* l)
{
	ft_map_reader(l);
	ft_bmp_reader(l, "./img/img0.bmp");
	ft_bmp_reader(l, "./img/img1.bmp");
	ft_bmp_reader(l, "./img/img2.bmp");
	ft_bmp_reader(l, "./img/img3.bmp");
	ft_bmp_reader(l, "./img/img4.bmp");
	ft_bmp_reader(l, "./img/img5.bmp");
	ft_bmp_reader(l, "./img/img6.bmp");
	ft_bmp_reader(l, "./img/img7.bmp");
	ft_bmp_reader(l, "./img/img8.bmp");
	ft_bmp_reader(l, "./img/img9.bmp");
	ft_bmp_reader(l, "./img/img10.bmp");
	ft_bmp_reader(l, "./img/img11.bmp");
	ft_bmp_reader(l, "./img/img12.bmp");
	ft_bmp_reader(l, "./img/img13.bmp");
	ft_bmp_reader(l, "./img/img14.bmp");
	ft_bmp_reader(l, "./img/img15.bmp");
	ft_bmp_reader(l, "./img/img16.bmp");
	ft_bmp_reader(l, "./img/img17.bmp");
	ft_bmp_reader(l, "./img/img18.bmp");
	ft_bmp_reader(l, "./img/img19.bmp");
	ft_bmp_reader(l, "./img/img20.bmp");
	ft_bmp_reader(l, "./img/img21.bmp");
	ft_bmp_reader(l, "./img/img22.bmp");
	ft_bmp_reader(l, "./img/img23.bmp");
	ft_bmp_reader(l, "./img/img24.bmp");
	ft_bmp_reader(l, "./img/img25.bmp");
	ft_bmp_reader(l, "./img/img26.bmp");
	ft_bmp_reader(l, "./img/img27.bmp");
	ft_bmp_reader(l, "./img/img28.bmp");
	ft_bmp_reader(l, "./img/img29.bmp");
	ft_bmp_reader(l, "./img/img30.bmp");
	ft_bmp_reader(l, "./img/img31.bmp");
	ft_bmp_reader(l, "./img/img32.bmp");
	ft_bmp_reader(l, "./img/img33.bmp");
	ft_bmp_reader(l, "./img/img34.bmp");
	ft_bmp_reader(l, "./img/img35.bmp");
	ft_bmp_reader(l, "./img/img36.bmp");
	ft_bmp_reader(l, "./img/img37.bmp");
	ft_bmp_reader(l, "./img/img38.bmp");
	ft_bmp_reader(l, "./img/img39.bmp");
	ft_bmp_reader(l, "./img/img40.bmp");
	ft_bmp_reader(l, "./img/img41.bmp");
	ft_bmp_reader(l, "./img/img42.bmp");
}

void	ft_reset_arrays(variable_list* l)
{
	int i;
	int j;
	//Uint32* p;

	//p = l->pixels;
	i = -1;
	while (++i < WDW)
	{
		j = -1;
		while (++j < WDH)
		{
			l->pixels_distance[i][j] = 999999;
			l->pixels_triangle[i][j] = -1;
			//l->pixels[i + j * WDW] = 0;
			l->pixels_color[i][j] = 0x0055FF;
		}
	}
}

void	ft_map_reader(variable_list* l)
{
	FILE* stream;
	int fd;
	int size;
	char *file;
	int i;
	int j;
	int k;

	/// For mapping
	if ((fopen_s(&stream, "./map/triangle", "r")) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	fseek(stream, 0, SEEK_END);
	size = ftell(stream);
	printf("Loaded file size: %d\n", size);
	fclose(stream);
	file = (char*)malloc((size + 1) * sizeof(char));
	if ((_sopen_s(&fd, "./map/triangle", 0,_SH_DENYNO, 0)) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	_read(fd, file, size);
	file[size] = '\0';
	_close(fd);
	i = 0;
	while (file[i] != '\0')
	{
		l->t.area[l->triangle_number] = (int)ft_atoi(l, file, &i);
		l->t.group[l->triangle_number] = (int)ft_atoi(l, file, &i);
		l->t.x1[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.y1[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.z1[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.x2[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.y2[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.z2[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.x3[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.y3[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.z3[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_id[l->triangle_number] = (int)ft_atoi(l, file, &i);
		l->t.texture_size_x[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_size_y[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_shift_x[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_shift_y[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_light[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_opacity[l->triangle_number] = ft_atoi(l, file, &i);
		l->t.texture_sides[l->triangle_number] = (int)ft_atoi(l, file, &i);
		l->triangle_number++;
		i++;
	}
	free(file);
	/// For mapping
	if ((fopen_s(&stream, "./map/group", "r")) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	fseek(stream, 0, SEEK_END);
	size = ftell(stream);
	printf("Loaded file size: %d\n", size);
	fclose(stream);
	file = (char*)malloc((size + 1) * sizeof(char));
	if ((_sopen_s(&fd, "./map/group", 0, _SH_DENYNO, 0)) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	_read(fd, file, size);
	file[size] = '\0';
	_close(fd);
	i = 0;
	j = 0;
	while (file[i] != '\0')
	{
		j = (int)ft_atoi(l, file, &i);
		l->g.sprite[j] = (int)ft_atoi(l, file, &i);
		l->g.npc[j] = (int)ft_atoi(l, file, &i);
		l->g.object[j] = (int)ft_atoi(l, file, &i);
		l->g.sprite_orientation[j] = (int)ft_atoi(l, file, &i);
		l->g.npc_statement[j] = 1;
		k = 0;
		while (file[++i] != ',')
		{
			l->g.action_auto[j][k] = file[i];
			k++;
		}
		k = 0;
		while (file[++i] != ',')
		{
			l->g.action_enable[j][k] = file[i];
			k++;
		}
		k = 0;
		while (file[++i] != ',')
		{
			l->g.action_disable[j][k] = file[i];
			k++;
		}
		i++;
	}
	free(file);

	/// For mapping
	/*if ((fopen_s(&stream, "./map/area", "r")) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	fseek(stream, 0, SEEK_END);
	size = ftell(stream);
	printf("Loaded file size: %d\n", size);
	fclose(stream);
	file = (char*)malloc((size + 1) * sizeof(char));
	if ((_sopen_s(&fd, "./map/area", 0, _SH_DENYNO, 0)) != 0)
	{
		printf("Load File Error\n");
		ft_free_and_exit(l);
	}
	_read(fd, file, size);
	file[size] = '\0';
	_close(fd);
	i = 0;
	j = 0;
	while (file[i] != '\0')
	{
		j++;
		i++;
	}
	free(file);*/
	/// For mapping
}
void	ft_engine_set_window_blue_border_triangle(variable_list* l)
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
void	ft_engine_set_window_red_border_area(variable_list* l)
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
void	ft_engine_set_window_green_border_group(variable_list* l)
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
void	ft_size_to_window(variable_list* l)
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
					{
							l->pixels[(k + i) * (WDWF)+(j + n)] =
							l->pixels_color[j / 2][i / 2];
					}
			}
			j += 2;
		}
		i += 2;
	}
}
void	ft_loop(variable_list* l)
{
	ft_init_npc(l);
	l->menu_mode = 0;
	while (1)
	{
		if (SDL_UpdateWindowSurface(l->window) < 0)
			ft_free_and_exit(l);
		ft_reset_arrays(l);
		if (l->menu_mode == 0)
			ft_main_menu_clic(l);
		else
		{
			if (l->menu_mode == 1)
				ft_event_playing_hud(l) , ft_get_npc(l), npc_attack(l);
			else if (l->menu_mode == 2)
				ft_map_editor(l);

			ft_engine_play(l);

			if (l->triangle_select != -1)
				ft_engine_set_window_blue_border_triangle(l);
			else if (l->area_select != -1)
				ft_engine_set_window_red_border_area(l);
			else if (l->group_select != -1)
				ft_engine_set_window_green_border_group(l);

			ft_size_to_window(l);
		}
		ft_events(l);
		ft_get_time(l);
		ft_action_auto(l);

	}
}

int main()
{
	variable_list* l;

	if (!(l = malloc(sizeof(variable_list))))
		exit(-1);
	ft_initialize_variables(l);
	ft_initialize_SDL(l);
	ft_read_all(l);
	ft_main_menu_clic(l);
	ft_loop(l);
	return(0);
}