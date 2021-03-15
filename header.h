/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:29:55 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 16:20:36 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <io.h>
#include <stdio.h>
# include <SDL.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WDWF 1024
# define WDHF 768
# define WDW 512
# define WDH 384
# define WDW2 256
# define WDH2 192

# define MAX_TRIANGLES 1500
# define MAX_GROUPS 1000
# define MAX_LIGHTS 200
# define MAX_AREAS 100
# define MAX_GENERIC 9999

typedef struct		s_list_15
{
	double			nx;
	double			ny;
	double			nz;
	double			angle;
	double			p01x;
	double			p02x;
	double			p01y;
	double			p02y;
	double			p01z;
	double			p02z;
	double			p1x;
	double			p2x;
	double			p3x;
	double			p1y;
	double			p2y;
	double			p3y;
	double			p1z;
	double			p2z;
	double			p3z;
	double			t;
	double			u;
	double			v;
	double			save;
	double			h;
	double			vx;
	double			vy;
	double			vz;
	double			move_x;
	double			move_y;
	double			move_z;
	double			x1;
	double			x2;
	double			x3;
	double			x4;
	double			y1;
	double			y2;
	double			y3;
	double			y4;
	double			save_px;
	double			save_py;
	double			save_pz;
	double			save_nx;
	double			save_ny;
	double			save_nz;
	double			p[3];
	int				i;
}					t_player_move_list;

typedef struct		s_list_14
{
	double			nzvd;
	double			t_n;
	double			d01;
	double			d04;
	double			c_x;
	double			c_y;
	double			c_z;
	double			vd;
	double			t_d;
	double			t_z1;
	double			t_x1;
	double			t_y1;
	double			v1x;
	double			v4x;
	double			v1y;
	double			v4y;
	double			v1z;
	double			v4z;
	double			nx;
	double			ny;
	double			nz;
	double			ttsix;
	double			ttshx;
	double			ttsiy;
	double			ttshy;
	double			l;
	double			o;
	Uint32			*p;
	int				*t_id;
	unsigned char	*c;
	double			*fy;
	double			*ly;
	double			s;
	int				ss;
	int				x;
	int				y;
	int				mx;
	int				my;
	int				v;
	int				t_s;
}					t_engine_play_calculate_pixels_tmp;

typedef struct		s_list_13
{
	double			d01;
	double			d02;
	double			d04;
	double			t_cos;
	double			t_sin;
	double			t_x;
	double			t_y;
	double			t;
	double			nzvd;
	double			c_x;
	double			c_y;
	double			c_z;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			first_y[WDW];
	double			last_y[WDW];
	double			p_x1;
	double			p_x2;
	double			p_x3;
	double			p_x4;
	double			p_y1;
	double			p_y2;
	double			p_y3;
	double			p_y4;
	double			t_normal;
	double			view_distance;
	double			t_d[MAX_TRIANGLES];
	double			t_z1[MAX_TRIANGLES];
	double			t_z2[MAX_TRIANGLES];
	double			t_z3[MAX_TRIANGLES];
	double			t_x1[MAX_TRIANGLES];
	double			t_x2[MAX_TRIANGLES];
	double			t_x3[MAX_TRIANGLES];
	double			t_y1[MAX_TRIANGLES];
	double			t_y2[MAX_TRIANGLES];
	double			t_y3[MAX_TRIANGLES];
	double			tmp_z1;
	double			tmp_z2;
	double			tmp_z3;
	double			tmp_z4;
	double			tmp_x1;
	double			tmp_x2;
	double			tmp_x3;
	double			tmp_x4;
	double			tmp_y1;
	double			tmp_y2;
	double			tmp_y3;
	double			tmp_y4;
	double			v1x;
	double			v2x;
	double			v4x;
	double			v1y;
	double			v2y;
	double			v4y;
	double			v1z;
	double			v2z;
	double			v4z;
	double			nx;
	double			ny;
	double			nz;
	double			xp;
	double			yp;
	double			zp;
	double			c_h;
	double			s_h;
	double			c_v;
	double			s_v;
	double			c_l;
	double			s_l;
	int				t_id[MAX_TRIANGLES];
	int				i;
	int				j;
	int				inc;
	int				v;
	int				t_s;
	int				ref;
	int				x;
	int				y;
}					t_engine_list;

typedef struct		s_list_12
{
	double			sizex;
	double			sizey;
	double			size;
	unsigned char	*colors;
	double			tsx;
	double			tsy;
	double			wsx;
	double			wsy;
	int				action;
}					t_map_editor_put_text_pixel_list;

typedef struct		s_list_11
{
	double			mult;
	double			endx;
	double			endy;
	double			x;
	double			y;
	double			z;
	double			angle;
	unsigned char	*color_white;
	unsigned char	*color_blue;
	unsigned char	*color_red;
	unsigned char	*color_green;
	int				xf;
	int				yf;
	int				area_switch_value;
	int				group_switch_value;
	int				action;
	int				menu;
	int				new_area;
	int				new_group;
	char			str[15];
}					t_editor_list;

typedef struct		s_list_10
{
	double			sizex;
	double			sizey;
	double			size;
	double			wsx;
	double			wsy;
	double			wex;
	double			wey;
	double			time;
	double			frametime;
	double			old_time;
	char			str[15];
	char			*str_address;
	unsigned char	*colors;
	unsigned char	*colors_on;
	int				action;
	int				tsx;
	int				tex;
	int				tsy;
	int				tey;
}					t_utility_list;

typedef struct		s_list_9
{
	Uint8			*state;
	int				save_mouse_x;
	int				save_mouse_y;
	int				mouse;
	int				mouse_y;
	int				mouse_x;
	int				mouse_time_pressing;
	int				scroll_up;
	int				scroll_down;
	int				key_input;
}					t_input_list;

typedef struct		s_list_8
{
	double			x;
	double			y;
	double			z;
	double			h;
	double			v;
	double			r;
	double			speed;
	double			player_size;
	double			jump_timer;
	int				start_x;
	int				start_y;
	int				start_z;
	int				start_hp;
	int				start_ammo;
	int				start_item[6];
	int				interact;
	int				hp;
	int				item[6];
	int				animation_timer;
}					t_player_list;

typedef struct		s_list_7
{
	double			x1[MAX_TRIANGLES];
	double			y1[MAX_TRIANGLES];
	double			z1[MAX_TRIANGLES];
	double			x2[MAX_TRIANGLES];
	double			y2[MAX_TRIANGLES];
	double			z2[MAX_TRIANGLES];
	double			x3[MAX_TRIANGLES];
	double			y3[MAX_TRIANGLES];
	double			z3[MAX_TRIANGLES];
	double			texture_opacity[MAX_TRIANGLES];
	double			texture_light[MAX_TRIANGLES];
	double			texture_size_x[MAX_TRIANGLES];
	double			texture_size_y[MAX_TRIANGLES];
	double			texture_shift_x[MAX_TRIANGLES];
	double			texture_shift_y[MAX_TRIANGLES];
	int				texture_id[MAX_TRIANGLES];
	int				texture_sides[MAX_TRIANGLES];
	int				area[MAX_TRIANGLES];
	int				group[MAX_TRIANGLES];
}					t_triangle_list;

typedef struct		s_list_6
{
	int				sprite[MAX_GROUPS];
	int				npc_o[MAX_GROUPS];
	int				npc[MAX_GROUPS];
	int				npc_timer[MAX_GROUPS];
	int				npc_hp[MAX_GROUPS];
	int				npc_statement[MAX_GROUPS];
	int				no_block[MAX_GROUPS];
	int				interact[MAX_GROUPS];
	int				exist[MAX_GROUPS];
	int				action_timer[MAX_GROUPS];
	int				action_statement[MAX_GROUPS];
	char			action_enable[MAX_GROUPS][67];
	char			action_disable[MAX_GROUPS][67];
}					t_group_list;

typedef struct		s_list_5
{
	double			gx;
	double			gy;
	double			gz;
	double			sx;
	double			sy;
	double			sz;
	double			gd;
	int				ts;
}					t_grenade_list;

typedef struct		s_list_4
{
	double			pen_opacity;
	double			pen_light;
	int				pen_size;
	int				pen_texture;
	int				pen_group;
	int				pen_area;
}					t_pen_list;

typedef struct		s_list_2
{
	double			vx;
	double			vy;
	double			vz;
	double			v1x;
	double			v2x;
	double			v1y;
	double			v2y;
	double			v1z;
	double			v2z;
	double			nx;
	double			ny;
	double			nz;
	double			p1x;
	double			p2x;
	double			p3x;
	double			p1y;
	double			p2y;
	double			p3y;
	double			p1z;
	double			p2z;
	double			p3z;
	double			t;
	double			u;
	double			v;
}					t_npc_list;

typedef struct		s_list_1
{
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Surface		*window_surface;
	Uint32			*pixels;
	t_triangle_list	t;
	t_group_list	g;
	t_engine_list	e;
	t_editor_list	me;
	t_utility_list	u;
	t_input_list	i;
	t_player_list	p;
	t_npc_list		n;
	t_grenade_list	gr;
	t_pen_list		pe;
	double			gravity;
	double			pixels_distance[WDW][WDH];
	double			coef_gravity;
	char			*file;
	int				npc_base_life;
	int				npc_base_damage;
	int				view_only;
	int				pixels_triangle[WDW][WDH];
	int				pixels_color[WDW][WDH];
	int				action_v1[MAX_GROUPS];
	int				action_select[50][200];
	int				link1[MAX_AREAS];
	int				link2[MAX_AREAS];
	int				link3[MAX_AREAS];
	int				link4[MAX_AREAS];
	int				link5[MAX_AREAS];
	int				link6[MAX_AREAS];
	int				window_w;
	int				window_h;
	int				triangle_select;
	int				area_select;
	int				group_select;
	int				light_select;
	int				menu_select;
	int				action;
	int				paint_texture_select;
	int				paint_opacity_select;
	int				paint_group_select;
	int				paint_area_select;
	int				triangle_number;
	int				light_number;
	int				texture_number;
	int				group_number;
	int				area_number;
	int				writing_mode;
	int				cooldown;
	int				player_area;
	int				menu_mode;
	unsigned char	texture_colors[49][1024 * 1024 * 4];
}					t_variable_list;

void				ft_action_x(
t_variable_list *l, int group, int c, char *str);
void				ft_action_y(
t_variable_list *l, int group, int c, char *str);
void				ft_action_z(
t_variable_list *l, int group, int c, char *str);
void				ft_action_calculate_center(
t_variable_list *l, int group);
void				ft_action_h_rotate(
t_variable_list *l, int group);
void				ft_action_h(
t_variable_list *l, int group, int c, char *str);
void				ft_action_v_rotate(
t_variable_list *l, int group);
void				ft_action_v(
t_variable_list *l, int group, int c, char *str);
void				ft_action_l_rotate(
t_variable_list *l, int group);
void				ft_action_l(
t_variable_list *l, int group, int c, char *str);
void				ft_action_s_up(
t_variable_list *l, int group, double value);
void				ft_action_s_do(
t_variable_list *l, int group, double value);
void				ft_action_s_replace(
t_variable_list *l, int group);
void				ft_action_size(
t_variable_list *l, int group, int c, char *str);
void				ft_action_texture(
t_variable_list *l, int group, int c, char *str);
void				ft_action_on(
t_variable_list *l, int group, int c, char *str);
void				ft_action_off(
t_variable_list *l, int group, int c, char *str);
void				ft_action_area_end(
t_variable_list *l);
void				ft_action_area_loot(
t_variable_list *l, int group, int c, char *str);
void				ft_action_area_heal(
t_variable_list *l, int group, int c, char *str);
void				ft_action_area(
t_variable_list *l, int group, int c, char *str);
void				ft_action_exist(
t_variable_list *l, int group, int c, char *str);
void				ft_action_xyzhvls(
t_variable_list *l, int group, int c, char *str);
void				ft_action_start_action_timer_positive(
t_variable_list *l, int group, int c, char *str);
void				ft_action_start_action_timer_negative_key(
t_variable_list *l, int group, int *c, char *str);
void				ft_action_start_action_timer_negative_time(
t_variable_list *l, int group, int c, char *str);
void				ft_action_start(
t_variable_list *l, int group, int c, char *str);
void				ft_action_enable(
t_variable_list *l, int group);
void				ft_action_disable(
t_variable_list *l, int group);
void				ft_action(
t_variable_list *l);
void				ft_map_editor_tool_set_mult(
t_variable_list *l);
void				ft_map_editor_menu_background(
t_variable_list *l);
void				ft_map_editor_submenu_background(
t_variable_list *l);
void				ft_map_editor_menu(
t_variable_list *l);
void				ft_map_editor(
t_variable_list *l);
void				ft_map_editor_area_action_select_area(
t_variable_list *l);
void				ft_map_editor_area_action_switch_area(
t_variable_list *l);
void				ft_map_editor_area_action_position_x_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_x_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_x(
t_variable_list *l);
void				ft_map_editor_area_action_position_y_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_y_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_y(
t_variable_list *l);
void				ft_map_editor_area_action_position_z_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_z_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_z(
t_variable_list *l);
void				ft_map_editor_area_action_position_calculate_center(
t_variable_list *l);
void				ft_map_editor_area_action_position_h_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_h_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_h(
t_variable_list *l);
void				ft_map_editor_area_action_position_v_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_vdown(
t_variable_list *l);
void				ft_map_editor_area_action_position_v(
t_variable_list *l);
void				ft_map_editor_area_action_position_l_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_l_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_l(
t_variable_list *l);
void				ft_map_editor_area_action_position_size_recall(
t_variable_list *l);
void				ft_map_editor_area_action_position_size_up(
t_variable_list *l);
void				ft_map_editor_area_action_position_size_down(
t_variable_list *l);
void				ft_map_editor_area_action_position_size(
t_variable_list *l);
void				ft_map_editor_area_action_link1(
t_variable_list *l);
void				ft_map_editor_area_action_link2(
t_variable_list *l);
void				ft_map_editor_area_action_link3(
t_variable_list *l);
void				ft_map_editor_area_action_link4(
t_variable_list *l);
void				ft_map_editor_area_action_link5(
t_variable_list *l);
void				ft_map_editor_area_action_link6(
t_variable_list *l);
void				ft_map_editor_area_action_delete_set_values(
t_variable_list *l, int ts);
void				ft_map_editor_area_action_delete(
t_variable_list *l);
void				ft_map_editor_game_action_npc_health(
t_variable_list *l);
void				ft_map_editor_game_action_npc_damage(
t_variable_list *l);
void				ft_map_editor_game_action_world_gravity(
t_variable_list *l);
void				ft_map_editor_group_action_select_group(
t_variable_list *l);
void				ft_map_editor_group_action_switch_group(
t_variable_list *l);
void				ft_map_editor_group_action_position_x_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_x_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_x(
t_variable_list *l);
void				ft_map_editor_group_action_position_y_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_y_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_y(
t_variable_list *l);
void				ft_map_editor_group_action_position_z_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_z_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_z(
t_variable_list *l);
void				ft_map_editor_group_action_position_calculate_center(
t_variable_list *l);
void				ft_map_editor_group_action_position_h_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_h_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_h(
t_variable_list *l);
void				ft_map_editor_group_action_position_v_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_vdown(
t_variable_list *l);
void				ft_map_editor_group_action_position_v(
t_variable_list *l);
void				ft_map_editor_group_action_position_l_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_l_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_l(
t_variable_list *l);
void				ft_map_editor_group_action_position_size_recall(
t_variable_list *l);
void				ft_map_editor_group_action_position_size_up(
t_variable_list *l);
void				ft_map_editor_group_action_position_size_down(
t_variable_list *l);
void				ft_map_editor_group_action_position_size(
t_variable_list *l);
void				ft_map_editor_group_action_enable(
t_variable_list *l);
void				ft_map_editor_group_action_disable(
t_variable_list *l);
void				ft_map_editor_group_action_sprite(
t_variable_list *l);
void				ft_map_editor_group_action_npc(
t_variable_list *l);
void				ft_map_editor_group_action_no_block(
t_variable_list *l);
void				ft_map_editor_group_action_interact(
t_variable_list *l);
void				ft_map_editor_group_action_check_free_group(
t_variable_list *l);
void				ft_map_editor_group_action_create_npc_triangle_1(
t_variable_list *l, int ts);
void				ft_map_editor_group_action_create_npc_triangle_2(
t_variable_list *l, int ts);
void				ft_map_editor_group_action_create_npc(
t_variable_list *l);
void				ft_map_editor_group_action_duplicate_set_values(
t_variable_list *l, int ts);
void				ft_map_editor_group_action_duplicate(
t_variable_list *l);
void				ft_map_editor_group_action_delete_set_values(
t_variable_list *l, int ts);
void				ft_map_editor_group_action_delete(
t_variable_list *l);
void				ft_map_editor_paint_action_delete_set_values(
t_variable_list *l);
void				ft_map_editor_paint_action_delete(
t_variable_list *l);
void				ft_map_editor_paint_action_texture(
t_variable_list *l);
void				ft_map_editor_paint_action_group(
t_variable_list *l);
void				ft_map_editor_paint_action_area(
t_variable_list *l);
void				ft_map_editor_paint_action_opacity(
t_variable_list *l);
void				ft_map_editor_paint_action_light(
t_variable_list *l);
void				ft_map_editor_player_action_x(
t_variable_list *l);
void				ft_map_editor_player_action_y(
t_variable_list *l);
void				ft_map_editor_player_action_z(
t_variable_list *l);
void				ft_map_editor_player_action_hp(
t_variable_list *l);
void				ft_map_editor_player_action_item_bare_hands(
t_variable_list *l);
void				ft_map_editor_player_action_item_pistol(
t_variable_list *l);
void				ft_map_editor_player_action_item_grenade(
t_variable_list *l);
void				ft_map_editor_player_action_item_telecommand(
t_variable_list *l);
void				ft_map_editor_player_action_item_access_card(
t_variable_list *l);
void				ft_map_editor_player_action_item_top_secret_box(
t_variable_list *l);
void				ft_map_editor_triangle_action_create_square(
t_variable_list *l);
void				ft_map_editor_triangle_action_duplicate_set_values(
t_variable_list *l);
void				ft_map_editor_triangle_action_duplicate(
t_variable_list *l);
void				ft_map_editor_triangle_action_delete_set_values(
t_variable_list *l);
void				ft_map_editor_triangle_action_delete(
t_variable_list *l);
void				ft_map_editor_triangle_action_triangle(
t_variable_list *l);
void				ft_map_editor_triangle_action_area(
t_variable_list *l);
void				ft_map_editor_triangle_action_group(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_x_all(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_y_all(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_z_all(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_calculate_center(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_size_recall(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_size_up(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_size_down(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_size(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_h_up(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_h_down(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_h(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_v_up(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_vdown(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_v(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_l_up(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_l_down(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_l(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_x_1(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_y_1(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_z_1(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_x_2(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_y_2(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_z_2(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_x_3(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_y_3(
t_variable_list *l);
void				ft_map_editor_triangle_action_position_z_3(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_light(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_opacity(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_x(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_y(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_stretch(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_repeat(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_adapt_y(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_size_adapt_x(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_sides(
t_variable_list *l);
void				ft_map_editor_triangle_action_create_new_set_values(
t_variable_list *l);
void				ft_map_editor_triangle_action_create_new(
t_variable_list *l);
void				ft_map_editor_triangle_action_create_square_set_values(
t_variable_list *l, int tn);
void				ft_map_editor_area_parameter_area(
t_variable_list *l);
void				ft_map_editor_area_parameter_area_id(
t_variable_list *l);
void				ft_map_editor_area_parameter_switch(
t_variable_list *l);
void				ft_map_editor_area_parameter_position(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_x(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_y(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_z(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_h(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_v(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_l(
t_variable_list *l);
void				ft_map_editor_area_parameter_position_size(
t_variable_list *l);
void				ft_map_editor_area_parameter_link(
t_variable_list *l);
void				ft_map_editor_area_parameter_link1(
t_variable_list *l);
void				ft_map_editor_area_parameter_link2(
t_variable_list *l);
void				ft_map_editor_area_parameter_link3(
t_variable_list *l);
void				ft_map_editor_area_parameter_link4(
t_variable_list *l);
void				ft_map_editor_area_parameter_link5(
t_variable_list *l);
void				ft_map_editor_area_parameter_link6(
t_variable_list *l);
void				ft_map_editor_area_parameter_options(
t_variable_list *l);
void				ft_map_editor_area_parameter_delete(
t_variable_list *l);
void				ft_map_editor_game_parameter_npc(
t_variable_list *l);
void				ft_map_editor_game_parameter_npc_health(
t_variable_list *l);
void				ft_map_editor_game_parameter_npc_damage(
t_variable_list *l);
void				ft_map_editor_game_parameter_world(
t_variable_list *l);
void				ft_map_editor_game_parameter_world_gravity(
t_variable_list *l);
void				ft_map_editor_group_parameter_group(
t_variable_list *l);
void				ft_map_editor_group_parameter_group_id(
t_variable_list *l);
void				ft_map_editor_group_parameter_switch(
t_variable_list *l);
void				ft_map_editor_group_parameter_position(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_x(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_y(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_z(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_h(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_v(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_l(
t_variable_list *l);
void				ft_map_editor_group_parameter_position_size(
t_variable_list *l);
void				ft_map_editor_group_parameter_action(
t_variable_list *l);
void				ft_map_editor_group_parameter_enable(
t_variable_list *l);
void				ft_map_editor_group_parameter_disable(
t_variable_list *l);
void				ft_map_editor_group_parameter_flag(
t_variable_list *l);
void				ft_map_editor_group_parameter_sprite(
t_variable_list *l);
void				ft_map_editor_group_parameter_npc(
t_variable_list *l);
void				ft_map_editor_group_parameter_no_block(
t_variable_list *l);
void				ft_map_editor_group_parameter_interact(
t_variable_list *l);
void				ft_map_editor_group_parameter_options(
t_variable_list *l);
void				ft_map_editor_group_parameter_create_npc(
t_variable_list *l);
void				ft_map_editor_group_parameter_duplicate(
t_variable_list *l);
void				ft_map_editor_group_parameter_delete(
t_variable_list *l);
void				ft_map_editor_menu_parameter_triangle(
t_variable_list *l);
void				ft_map_editor_menu_parameter_area(
t_variable_list *l);
void				ft_map_editor_menu_parameter_group(
t_variable_list *l);
void				ft_map_editor_menu_parameter_light(
t_variable_list *l);
void				ft_map_editor_menu_parameter_player(
t_variable_list *l);
void				ft_map_editor_menu_parameter_game(
t_variable_list *l);
void				ft_map_editor_menu_parameter_paint(
t_variable_list *l);
void				ft_map_editor_menu_parameter_view_only(
t_variable_list *l);
void				ft_map_editor_paint_parameter_mode(
t_variable_list *l);
void				ft_map_editor_paint_parameter_delete(
t_variable_list *l);
void				ft_map_editor_paint_parameter_texture(
t_variable_list *l);
void				ft_map_editor_paint_parameter_group(
t_variable_list *l);
void				ft_map_editor_paint_parameter_area(
t_variable_list *l);
void				ft_map_editor_paint_parameter_opacity(
t_variable_list *l);
void				ft_map_editor_paint_parameter_light(
t_variable_list *l);
void				ft_map_editor_player_parameter_start(
t_variable_list *l);
void				ft_map_editor_player_parameter_x(
t_variable_list *l);
void				ft_map_editor_player_parameter_y(
t_variable_list *l);
void				ft_map_editor_player_parameter_z(
t_variable_list *l);
void				ft_map_editor_player_parameter_hp(
t_variable_list *l);
void				ft_map_editor_player_parameter_item(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_bare_hands(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_pistol(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_grenade(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_telecommand(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_access_card(
t_variable_list *l);
void				ft_map_editor_player_parameter_item_top_secret_box(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_triangle(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_triangle_id(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_area(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_group(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_x_all(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_y_all(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_z_all(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_size(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_rotation(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_h(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_v(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_l(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_x_1(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_y_1(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_z_1(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_x_2(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_y_2(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_z_2(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_x_3(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_y_3(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_position_z_3(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_id(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_light(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_opacity(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_x(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_y(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_shift(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_shift_x(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_shift_y(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_shift_x(
t_variable_list *l);
void				ft_map_editor_triangle_action_texture_shift_y(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_adapt(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_stretch(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_repeat(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_adapt_x(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_size_adapt_y(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_sides(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_options(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_create_new(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_create_square(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_duplicate(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_delete(
t_variable_list *l);
void				ft_map_editor_triangle_parameter_texture_view(
t_variable_list *l);
void				ft_map_editor_area_parameters(
t_variable_list *l);
void				ft_map_editor_area_actions(
t_variable_list *l);
void				ft_map_editor_area(
t_variable_list *l);
void				ft_map_editor_game_parameters(
t_variable_list *l);
void				ft_map_editor_game_actions(
t_variable_list *l);
void				ft_map_editor_game(
t_variable_list *l);
void				ft_map_editor_group_parameters(
t_variable_list *l);
void				ft_map_editor_group_actions(
t_variable_list *l);
void				ft_map_editor_group(
t_variable_list *l);
void				ft_map_editor_paint_parameters(
t_variable_list *l);
void				ft_map_editor_paint_actions(
t_variable_list *l);
void				ft_map_editor_paint(
t_variable_list *l);
void				ft_map_editor_player_parameters(
t_variable_list *l);
void				ft_map_editor_player_actions(
t_variable_list *l);
void				ft_map_editor_player(
t_variable_list *l);
void				ft_map_editor_triangle_parameters_1(
t_variable_list *l);
void				ft_map_editor_triangle_parameters_2(
t_variable_list *l);
void				ft_map_editor_triangle_actions_1(
t_variable_list *l);
void				ft_map_editor_triangle_actions_2(
t_variable_list *l);
void				ft_map_editor_triangle(
t_variable_list *l);
void				ft_engine_calculate_triangles_distance(
t_variable_list *l);
void				ft_engine_set_x_y_z(
t_variable_list *l, double *x, double *y, double *z);
void				ft_engine_set_angles_value(
t_variable_list *l);
void				ft_engine_set_triangles_points_sprite(
t_variable_list *l, int ts);
void				ft_engine_set_triangles_points_no_sprite(
t_variable_list *l, int ts);
int					ft_engine_play_calculate_skip_triangles_behind_player(
t_variable_list *l);
void				ft_engine_play_calculate_initialize_points_vectors_normals(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_ref_1(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_ref_2(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_ref_3(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_1(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_2(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_3(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_4(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_5(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref_6(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front_no_ref(
t_variable_list *l);
void				ft_engine_play_calculate_points_to_front(
t_variable_list *l);
void				ft_engine_play_calculate_pixel_points(
t_variable_list *l);
void				ft_engine_play_calculate_pixel_points_p4(
t_variable_list *l);
void				ft_engine_play_calculate_triangle_line_1_2(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_line_1_3(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_line_2_3(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_line_1_4(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_line_2_4(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_line_3_4(
t_variable_list *l, int i, double *first_y, double *last_y);
void				ft_engine_play_calculate_triangle_limits_no_ref(
t_variable_list *l);
void				ft_engine_play_calculate_triangle_limits_ref_1(
t_variable_list *l);
void				ft_engine_play_calculate_triangle_limits_ref_2(
t_variable_list *l);
void				ft_engine_play_calculate_if_appear(
t_variable_list *l);
void				ft_engine_play_calculate_me_opacity(
t_variable_list *l, int i, int j);
void				ft_engine_play_calculate_me(
t_variable_list *l);
void				ft_engine_play_calculate_p_opacity(
t_variable_list *l, int i, int j);
void				ft_engine_play_calculate_p(
t_variable_list *l, int i, int j);
void				ft_engine_play_calculate_pixels_initialize_part_1(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *tmp);
void				ft_engine_play_calculate_pixels_initialize_part_2(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *tmp);
void				ft_engine_play_calculate_pixels_initialize_part_3(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *tmp);
void				ft_engine_play_calculate_pixels_while_y(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *s);
void				ft_engine_play_calculate_pixels(
t_variable_list *l);
void				ft_engine_play_calculate_pixels_while_y_opacity_color(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *s);
void				ft_engine_play_calculate_pixels_while_y_opacity(
t_variable_list *l, t_engine_play_calculate_pixels_tmp *s);
void				ft_engine_play_calculate_pixels_opacity(
t_variable_list *l);
void				ft_engine_play_p(
t_variable_list *l);
void				ft_engine_play_me(
t_variable_list *l);
void				ft_engine_set_triangles_points(
t_variable_list *l);
void				ft_hud_play_set_item_select(
t_variable_list *l, int item);
void				ft_hud_play_set_item_select_scroll_up(
t_variable_list *l);
void				ft_hud_play_set_item_select_scroll_down(
t_variable_list *l);
void				ft_hud_play_set_item_select_scroll(
t_variable_list *l);
void				ft_hud_play_item_0_animation_1(
t_variable_list *l);
void				ft_hud_play_item_0_animation_2(
t_variable_list *l);
void				ft_hud_play_item_0_animation_3(
t_variable_list *l);
void				ft_hud_play_item_0_animation_4(
t_variable_list *l);
void				ft_hud_play_item_0_animation_5(
t_variable_list *l);
void				ft_hud_play_item_0(
t_variable_list *l);
void				ft_hud_play_item_1_animation_1(
t_variable_list *l);
void				ft_hud_play_item_1_animation_2(
t_variable_list *l);
void				ft_hud_play_item_1_animation_3(
t_variable_list *l);
void				ft_hud_play_item_1_animation_4(
t_variable_list *l);
void				ft_hud_play_item_1_animation_5(
t_variable_list *l);
void				ft_hud_play_item_1(
t_variable_list *l);
void				ft_hud_play_item_2_animation_1(
t_variable_list *l);
void				ft_hud_play_item_2_animation_2(
t_variable_list *l);
void				ft_hud_play_item_2_animation_3_check_error(
t_variable_list *l);
void				ft_hud_play_item_2_animation_3_create_grenade(
t_variable_list *l);
void				ft_hud_play_item_2_animation_3(
t_variable_list *l);
void				ft_hud_play_item_2_animation_4(
t_variable_list *l);
void				ft_hud_play_item_2_animation_5(
t_variable_list *l);
void				ft_hud_play_item_2(
t_variable_list *l);
void				ft_hud_play_item_3(
t_variable_list *l);
void				ft_hud_play_item_4(
t_variable_list *l);
void				ft_hud_play_item_5(
t_variable_list *l);
void				ft_hud_play_animation_timer_zero(
t_variable_list *l);
void				ft_hud_play_item_select(
t_variable_list *l);
void				ft_hud_play_grenade_distance_positive(
t_variable_list *l);
void				ft_hud_play_grenade_distance_negative_delete(
t_variable_list *l);
void				ft_hud_play_grenade_distance_negative_explosion(
t_variable_list *l);
void				ft_hud_play_grenade_distance_negative_move(
t_variable_list *l);
void				ft_hud_play_grenade_distance_negative(
t_variable_list *l);
void				ft_hud_play_grenade(
t_variable_list *l);
void				ft_hud_play_items_1(
t_variable_list *l);
void				ft_hud_play_items_2(
t_variable_list *l);
void				ft_hud_play(
t_variable_list *l);
void				ft_hud_main_menu_display(
t_variable_list *l);
void				ft_hud_main_menu_play(
t_variable_list *l);
void				ft_hud_main_menu_editor(
t_variable_list *l);
void				ft_hud_main_menu(
t_variable_list *l);
void				ft_hud_play_item_2_animation_6(
t_variable_list *l);
void				ft_initialize_variables_triangles(
t_variable_list *l);
void				ft_initialize_variables_groups(
t_variable_list *l);
void				ft_initialize_variables_areas(
t_variable_list *l);
void				ft_initialize_variables_1(
t_variable_list *l);
void				ft_initialize_variables_2(
t_variable_list *l);
void				ft_initialize_variables_3(
t_variable_list *l);
void				ft_initialize_variables_4(
t_variable_list *l);
void				ft_initialize_skybox_1(
t_variable_list *l);
void				ft_initialize_skybox_2(
t_variable_list *l);
void				ft_initialize_skybox_3(
t_variable_list *l);
void				ft_initialize_skybox_4(
t_variable_list *l);
void				ft_initialize_skybox_5(
t_variable_list *l);
void				ft_initialize_skybox_6(
t_variable_list *l);
void				ft_initialize_skybox_7(
t_variable_list *l);
void				ft_initialize_skybox_8(
t_variable_list *l);
void				ft_initialize_skybox_9(
t_variable_list *l);
void				ft_initialize_skybox_10(
t_variable_list *l);
void				ft_initialize_skybox_11(
t_variable_list *l);
void				ft_initialize_skybox_12(
t_variable_list *l);
void				ft_initialize_variables(
t_variable_list *l);
void				ft_initialize_sdl(
t_variable_list *l);
void				ft_reset_arrays(
t_variable_list *l);
void				ft_map_reader_error(
t_variable_list *l, double value, double min, double max);
void				ft_reader_textures(
t_variable_list *l, int *i, int size);
void				ft_reader_triangles_error(
t_variable_list *l, int *i, int size);
void				ft_reader_triangles_w1(
t_variable_list *l, int *i);
void				ft_reader_triangles_w2(
t_variable_list *l, int *i);
void				ft_reader_triangles(
t_variable_list *l, int *i, int size);
void				ft_reader_groups_error(
t_variable_list *l, int *i, int size);
void				ft_reader_groups_strings(
t_variable_list *l, int *i, int size);
void				ft_reader_groups(
t_variable_list *l, int *i, int size);
void				ft_reader_areas_error(
t_variable_list *l, int *i, int size);
void				ft_reader_areas(
t_variable_list *l, int *i, int size);
void				ft_reader(
t_variable_list *l, char **argv);
void				ft_engine_set_window_blue_border_triangle1(
t_variable_list *l);
void				ft_engine_set_window_blue_border_triangle2(
t_variable_list *l);
void				ft_engine_set_window_red_border_area1(
t_variable_list *l);
void				ft_engine_set_window_red_border_area2(
t_variable_list *l);
void				ft_engine_set_window_green_border_group1(
t_variable_list *l);
void				ft_engine_set_window_green_border_group2(
t_variable_list *l);
void				ft_size_to_window(
t_variable_list *l);
void				ft_loop_menu_1(
t_variable_list *l);
void				ft_loop_menu_2(
t_variable_list *l);
void				ft_loop_menu_3(
t_variable_list *l);
void				ft_loop_menu_4(
t_variable_list *l);
void				ft_loop(
t_variable_list *l);
void				ft_event_playing_mode_motion(
t_variable_list *l);
void				ft_event_playing_mode_player_line_plan_t(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_line_plan_u(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_line_plan_v(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_vector_intersection(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_triangle_init(
t_variable_list *l, t_player_move_list *tmp, int ts);
void				ft_event_playing_mode_player_wallblock_init(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_gravity(
t_variable_list *l);
void				ft_event_playing_mode_player_first_area_list_calculate(
t_variable_list *l, t_player_move_list *tmp, int ts);
void				ft_event_playing_mode_set_player_area_while(
t_variable_list *l, t_player_move_list *tmp, int ts);
void				ft_event_playing_mode_set_player_area(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_jump(
t_variable_list *l);
void				ft_event_playing_mode_player_wallblock_size(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_check_y(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_move_while_1(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_move_while_2(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_move_while_3(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock_move(
t_variable_list *l, t_player_move_list *tmp);
void				ft_event_playing_mode_player_wallblock(
t_variable_list *l);
void				ft_event_playing_mode_player(
t_variable_list *l);
void				ft_event_playing_mode(
t_variable_list *l);
void				ft_event_map_editor_mode_motion_right_click_on(
t_variable_list *l);
void				ft_event_map_editor_mode_motion_right_click_off(
t_variable_list *l);
void				ft_event_map_editor_mode_motion(
t_variable_list *l);
void				ft_event_map_editor_mode_moving(
t_variable_list *l);
void				ft_event_map_editor_mode_mouse_time_pressing_counter(
t_variable_list *l);
void				ft_event_map_editor_mode_select_triangle(
t_variable_list *l);
void				ft_event_map_editor_mode_select_area(
t_variable_list *l);
void				ft_event_map_editor_mode_select_group(
t_variable_list *l);
void				ft_event_map_editor_mode_select_on_click(
t_variable_list *l);
void				ft_event_map_editor_mode_moving_y(
t_variable_list *l);
void				ft_event_map_editor_mode(
t_variable_list *l);
void				ft_events_init(
t_variable_list *l);
void				ft_events(
t_variable_list *l);
void				ft_npc_line_triangle_t(
t_variable_list *l, t_npc_list *tmp);
void				ft_npc_line_triangle_u(
t_variable_list *l, t_npc_list *tmp);
void				ft_npc_line_triangle_v(
t_variable_list *l, t_npc_list *tmp);
void				ft_npc_line_triangle_initialize(
t_variable_list *l, t_npc_list *tmp, int ts);
void				ft_npc_hp_positive_init(
t_variable_list *l, t_npc_list *tmp, int group);
int					ft_npc_hp_positive_while(
t_variable_list *l, t_npc_list *tmp, int group);
void				ft_npc_hp_positive(
t_variable_list *l, t_npc_list *tmp, int group);
void				ft_npc_hp_negative(
t_variable_list *l, int group);
void				ft_npc(
t_variable_list *l);
void				ft_value_editing_double_wheel_up(
t_variable_list *l, double *value, int max);
void				ft_value_editing_double_wheel_down(
t_variable_list *l, double *value, int min);
void				ft_value_editing_double_set_number(
t_variable_list *l, double *value, int *limits, int i);
void				ft_value_editing_double_remove_number(
t_variable_list *l, double *value, int *limits, int i);
void				ft_value_editing_double_set_negativ(
double *value, int *limits);
void				ft_value_editing_double(
t_variable_list *l, double *value, int min, int max);
void				ft_value_editing_int_wheel_up(
t_variable_list *l, int *value, int max);
void				ft_value_editing_int_wheel_down(
t_variable_list *l, int *value, int min);
void				ft_value_editing_int_set_number(
t_variable_list *l, int *value, int *limits, int i);
void				ft_value_editing_int_remove_number(
t_variable_list *l, int *value, int *limits);
void				ft_value_editing_int_set_negativ(
int *value, int *limits);
void				ft_value_editing_int(
t_variable_list *l, int *value, int min, int max);
void				ft_text_editing(
t_variable_list *l, char *str, int max);
void				ft_put_text_texture_initialize(
t_variable_list *l, t_utility_list *tmp);
void				ft_put_text_texture_while(
t_variable_list *l, t_utility_list *tmp, int x, int y);
void				ft_put_text_texture_action(
t_variable_list *l, t_utility_list *tmp);
void				ft_put_text_texture(
t_variable_list *l, t_utility_list *tmp);
void				ft_put_text(
t_variable_list *l);
void				ft_put_texture_initialize(
t_variable_list *l, t_utility_list *tmp);
void				ft_put_texture_while(
t_variable_list *l, t_utility_list *tmp, int x, int y);
void				ft_put_texture_action(
t_variable_list *l, t_utility_list *tmp);
void				ft_put_texture(
t_variable_list *l);
void				ft_free_and_exit(
t_variable_list *l, const char *str);
void				ft_get_time_editor(
t_variable_list *l);
void				ft_get_time(
t_variable_list *l);
double				ft_atoi_while_init(
char *str, int *i, double *n);
void				ft_atoi_while_p1(
char *str, int *i, double *result, double *result_decimal);
void				ft_atoi_while_p2(
char *str, int *i, double *result_decimal);
double				ft_atoi_while(
char *str, int *i);
double				ft_atoi(
char *str, int *i);
void				ft_itoa_naturals(
double number, char *str, int *i);
void				ft_itoa_decimals(
double number, char *str, int *i);
int					ft_itoa(
double number, char *str);
int					ft_strings_compare(
char *line, char *word, int c);
void				ft_swap_nbr(
int *k, double *t, int i, int j);
void				ft_quick_sort(
int *k, double *t, int size);

#endif
