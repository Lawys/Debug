#ifndef DOOM__
#define DOOM__

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <io.h>
#include <malloc.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define WDWF 1024
#define WDHF 768
#define WDW (WDWF / 2)
#define WDH (WDHF / 2)
#define WDW2 (WDW / 2)
#define WDH2 (WDH / 2)

#define MAX_TRIANGLES 1500
#define MAX_GROUPS 1000
#define MAX_LIGHTS 200
#define MAX_AREAS 100
#define MAX_GENERIC 9999

typedef struct s_list_15
{
    double nx, ny, nz;
    double angle;
    double p01x, p02x, p01y, p02y, p01z, p02z;
    double p1x, p2x, p3x, p1y, p2y, p3y, p1z, p2z, p3z;
    double t, u, v, save, h;
    double vx, vy, vz;
    double move_x, move_y, move_z;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    double save_px, save_py, save_pz;
    double save_nx, save_ny, save_nz;
    double p[3];
    int i;
}				player_move_list;

typedef struct s_list_14
{
    double nzvd;
    double t_n;
    double d01;
    double d04;
    double c_x;
    double c_y;
    double c_z;
    double vd;
    double t_d;
    double t_z1;
    double t_x1;
    double t_y1;
    double v1x;
    double v4x;
    double v1y;
    double v4y;
    double v1z;
    double v4z;
    double nx;
    double ny;
    double nz;
    double ttsix;
    double ttshx;
    double ttsiy;
    double ttshy;
    double l;
    double o;
    Uint32 *p;
    int *t_id;
    unsigned char *c;
    double *fy;
    double *ly;
    double s;
    int ss;
    int x;
    int y;
    int mx;
    int my;
    int v;
    int t_s;
}               s_engine_play_calculate_pixels_tmp;

typedef struct s_list_13
{
    double d01;
    double d02;
    double d04;
    double t_cos;
    double t_sin;
    double t_x;
    double t_y;
    double t;
    double nzvd;
    double c_x;
    double c_y;
    double c_z;
    double min_x;
    double max_x;
    double min_y;
    double max_y;
    double first_y[WDW];
    double last_y[WDW];
    double p_x1;
    double p_x2;
    double p_x3;
    double p_x4;
    double p_y1;
    double p_y2;
    double p_y3;
    double p_y4;
    double t_normal;
    double view_distance;
    double t_d[MAX_TRIANGLES];
    double t_z1[MAX_TRIANGLES];
    double t_z2[MAX_TRIANGLES];
    double t_z3[MAX_TRIANGLES];
    double t_x1[MAX_TRIANGLES];
    double t_x2[MAX_TRIANGLES];
    double t_x3[MAX_TRIANGLES];
    double t_y1[MAX_TRIANGLES];
    double t_y2[MAX_TRIANGLES];
    double t_y3[MAX_TRIANGLES];
    double tmp_z1;
    double tmp_z2;
    double tmp_z3;
    double tmp_z4;
    double tmp_x1;
    double tmp_x2;
    double tmp_x3;
    double tmp_x4;
    double tmp_y1;
    double tmp_y2;
    double tmp_y3;
    double tmp_y4;
    double v1x;
    double v2x;
    double v4x;
    double v1y;
    double v2y;
    double v4y;
    double v1z;
    double v2z;
    double v4z;
    double nx;
    double ny;
    double nz;
    double xp;
    double yp;
    double zp;
    double c_h;
    double s_h;
    double c_v;
    double s_v;
    double c_l;
    double s_l;
    int t_id[MAX_TRIANGLES];
    int i;
    int j;
    int inc;
    int v;
    int t_s;
    int ref;
    int x;
    int y;
}               engine_list;

typedef struct s_list_12
{
    double sizex;
    double sizey;
    double size;
    char *colors;
    double tsx;
    double tsy;
    double wsx;
    double wsy;
    int action;
}               ft_map_editor_put_text_pixel_list;

typedef struct s_list_11
{
    double mult;
    double endx;
    double endy;
    double x;
    double y;
    double z;
    double angle;
    char *color_white;
    char *color_blue;
    char *color_red;
    char *color_green;
    int xf;
    int yf;
    int area_switch_value;
    int group_switch_value;
    int action;
    int menu;
    int new_area;
    int new_group;
    unsigned char str[15];
}               map_editor_list;

typedef struct s_list_10
{
    double sizex;
    double sizey;
    double size;
    double wsx;
    double wsy;
    double wex;
    double wey;
    double time;
    double frametime;
    double old_time;
    unsigned char str[15];
    unsigned char *str_address;
    unsigned char *colors;
    unsigned char *colors_on;
    int action;
    int tsx;
    int tex;
    int tsy;
    int tey;
}               utility_list;

typedef struct s_list_9
{
    Uint8 *state;
    int save_mouse_x;
    int save_mouse_y;
    int mouse;
    int mouse_y;
    int mouse_x;
    int	mouse_time_pressing;
    int scroll_up;
    int scroll_down;
    int key_input;
}       input_list;

typedef struct s_list_8
{
    double  x;
    double  y;
    double  z;
    double  h;
    double  v;
    double  r;
    double  speed;
    double  player_size;
    double     jump_timer;
    int     start_x;
    int     start_y;
    int     start_z;
    int     start_hp;
    int     start_ammo;
    int     start_item[6];
    int     interact;
    int     hp;
    int     item[6];
    int     animation_timer;
}       player_list;
typedef struct s_list_7
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
    int			texture_id[MAX_TRIANGLES];
    int			texture_sides[MAX_TRIANGLES];
    int			area[MAX_TRIANGLES];
    int			group[MAX_TRIANGLES];

}       triangle_list;

typedef struct s_list_6
{
    int		    sprite[MAX_GROUPS];
    int		    npc_o[MAX_GROUPS];
    int		    npc[MAX_GROUPS];
    int		    npc_timer[MAX_GROUPS];
    int		    npc_hp[MAX_GROUPS];
    int		    npc_statement[MAX_GROUPS];
    int		    no_block[MAX_GROUPS];
    int		    interact[MAX_GROUPS];
    int		    exist[MAX_GROUPS];
    int		    action_timer[MAX_GROUPS];
    int		    action_statement[MAX_GROUPS];
    char		action_enable[MAX_GROUPS][67];
    char		action_disable[MAX_GROUPS][67];
}       group_list;

typedef struct s_list_5
{
    double      gx;
    double      gy;
    double      gz;
    double      sx;
    double      sy;
    double      sz;
    double      gd;
    int         ts;
}       grenade_list;

typedef struct s_list_4
{
    double pen_opacity;
    double pen_light;
    int pen_size;
    int pen_texture;
    int pen_group;
    int pen_area;
}       pen_list;
typedef struct s_list_2
{
    double vx;
    double vy;
    double vz;
    double v1x;
    double v2x;
    double v1y;
    double v2y;
    double v1z;
    double v2z;
    double nx;
    double ny;
    double nz;
    double p1x;
    double p2x;
    double p3x;
    double p1y;
    double p2y;
    double p3y;
    double p1z;
    double p2z;
    double p3z;
    double t;
    double u;
    double v;

}               npc_list;

typedef struct s_list_1
{
    SDL_Event event;
    SDL_Window *window;
    SDL_Surface *window_surface;
    Uint32 *pixels;
    triangle_list t;
    group_list g;
    engine_list e;
    map_editor_list me;
    utility_list u;
    input_list i;
    player_list p;
    npc_list n;
    grenade_list gr;
    pen_list pe;

    double gravity;
    double		pixels_distance[WDW][WDH];
    double     coef_gravity;

    int    npc_base_life;
    int    npc_base_damage;

    int view_only;
    int			pixels_triangle[WDW][WDH];
    int			pixels_color[WDW][WDH];
    int		    action_v1[MAX_GROUPS];
    int				action_select[50][200];
    int         link1[MAX_AREAS];
    int         link2[MAX_AREAS];
    int         link3[MAX_AREAS];
    int         link4[MAX_AREAS];
    int         link5[MAX_AREAS];
    int         link6[MAX_AREAS];
    int             window_w;
    int             window_h;
    int				triangle_select;
    int				area_select;
    int				group_select;
    int				light_select;
    int             menu_select;
    int             action;
    int             paint_texture_select;
    int             paint_opacity_select;
    int             paint_group_select;
    int             paint_area_select;
    int				triangle_number;
    int				light_number;
    int             texture_number;
    int             group_number;
    int             area_number;
    int writing_mode;
    int	cooldown;
    int player_area;
    int menu_mode;
    unsigned char		texture_colors[49][1024 * 1024 * 4];
}   variable_list;

void		ft_engine_play_calculate_pixels_opacity(variable_list *l);
void		ft_engine_calculate_triangles_distance(variable_list *l);

void		ft_engine_set_x_y_z(variable_list *l, double *x, double *y, double *z);

void		ft_engine_set_angles_value(variable_list *l);

void		ft_engine_set_triangles_points(variable_list *l);

int ft_engine_play_calculate_skip_triangles_behind_player(variable_list *l);

void		ft_engine_play_calculate_initialize_points_vectors_normals(variable_list *l);

void		ft_engine_play_calculate_points_to_front_ref_1(variable_list *l);

void		ft_engine_play_calculate_points_to_front_ref_2(variable_list *l);

void		ft_engine_play_calculate_points_to_front_ref_3(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_1(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_2(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_3(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_4(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_5(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref_6(variable_list *l);

void		ft_engine_play_calculate_points_to_front_no_ref(variable_list *l);

void		ft_engine_play_calculate_points_to_front(variable_list *l);

void		ft_engine_play_calculate_pixel_points(variable_list *l);

void		ft_engine_play_calculate_pixel_points_p4(variable_list *l);

void		ft_engine_play_calculate_pixels_switch(variable_list *l);

void		ft_engine_play_calculate_pixels_switch_p4(variable_list *l);

void		ft_engine_play_calculate_min_max_x_limits(variable_list *l);

void		ft_engine_play_calculate_min_max_x_p4(variable_list *l);

void		ft_engine_play_calculate_min_max_x(variable_list *l);

void		ft_engine_play_calculate_triangle_line_1_2(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_line_1_3(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_line_2_3(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_line_1_4(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_line_2_4(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_line_3_4(variable_list *l, int i, double *first_y, double *last_y);

void		ft_engine_play_calculate_triangle_limits_no_ref(variable_list *l);

void		ft_engine_play_calculate_triangle_limits_ref_1(variable_list *l);

void		ft_engine_play_calculate_triangle_limits_ref_2(variable_list *l);

void		ft_engine_play_calculate_pixels_initialize_part_1(variable_list *l, s_engine_play_calculate_pixels_tmp *tmp);

void		ft_engine_play_calculate_pixels_initialize_part_2(variable_list *l, s_engine_play_calculate_pixels_tmp *tmp);

void		ft_engine_play_calculate_pixels_y_initialize(variable_list *l, s_engine_play_calculate_pixels_tmp *tmp);

void		ft_engine_play_calculate_pixels_distance(variable_list *l, s_engine_play_calculate_pixels_tmp *tmp);

void		ft_engine_play_calculate_pixels_color(s_engine_play_calculate_pixels_tmp *tmp);

void		ft_engine_play_calculate_pixels(variable_list *l);

void		ft_engine_play_calculate_if_appear(variable_list *l);

void		ft_engine_play_calculate(variable_list *l);

void		ft_engine_play(variable_list *l);
void		ft_map_editor_tool_set_mult(variable_list *l);

void		ft_map_editor_menu_background(variable_list *l);

void		ft_map_editor_submenu_background(variable_list *l);

void		ft_map_editor_menu_parameters(variable_list *l);

void		ft_map_editor_menu(variable_list *l);

void		ft_map_editor(variable_list *l);

void TMP_map_editor_save_map(variable_list *l);

void TMP_map_editor_clean_errors(variable_list *l);

void		ft_initialize_variables(variable_list *l);

void		ft_initialize_SDL(variable_list *l);

void		ft_read_all(variable_list *l);

void		ft_reset_arrays(variable_list *l);

void		ft_map_reader(variable_list *l);

void		ft_engine_set_window_blue_border_triangle(variable_list *l);

void		ft_engine_set_window_red_border_area(variable_list *l);

void		ft_engine_set_window_green_border_group(variable_list *l);

void		ft_loop(variable_list *l);

void		ft_event_playing_mode_motion(variable_list *l);

void		ft_event_playing_mode_player_line_plan_t(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_line_plan_u(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_line_plan_v(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_vector_intersection(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_triangle_init(variable_list *l, player_move_list *tmp, int ts);

void		ft_event_playing_mode_triangle_line_plan_t(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_triangle_line_plan_u(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_triangle_line_plan_v(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_triangle_vector_intersection(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_wallblock_triangle_init(player_move_list *tmp);

void		ft_event_playing_mode_player_wallblock_init(variable_list *l, player_move_list *tmp);

void		ft_event_playing_mode_player_wallblock_gravity(variable_list *l);

void		ft_event_playing_mode_player_wallblock(variable_list *l);

void		ft_event_playing_mode_player_crawl_or_squat(variable_list *l);

void		ft_event_playing_mode_player(variable_list *l);

void		ft_event_playing_mode(variable_list *l);

void		ft_event_map_editor_mode_motion_right_click_on(variable_list *l);

void		ft_event_map_editor_mode_motion_right_click_off(variable_list *l);

void		ft_event_map_editor_mode_motion(variable_list *l);

void		ft_event_map_editor_mode_moving(variable_list *l);

void		ft_event_map_editor_mode_mouse_time_pressing_counter(variable_list *l);

void		ft_event_map_editor_mode_select_triangle(variable_list *l);

void		ft_event_map_editor_mode_select_area(variable_list *l);

void		ft_event_map_editor_mode_select_group(variable_list *l);

void		ft_event_map_editor_mode_select_on_click(variable_list *l);

void		ft_event_map_editor_mode_moving_y(variable_list *l);

void		ft_event_map_editor_mode(variable_list *l);

void		ft_events(variable_list *l);
void		ft_free_and_exit(variable_list *l, const char *str);

void		ft_get_time(variable_list *l);

void		ft_img_reader(variable_list *l);

double ft_atoi_while(variable_list *l, char *str, int *i);

double ft_atoi(variable_list *l, char *str, int *i);

int ft_itoa(variable_list *l, double number, char *str);

void		ft_swap_nbr(int *k, double *t, int i, int j);

void		ft_quick_sort(int *k, double *t, int size);
void		ft_map_editor_menu_parameter_triangle(variable_list *l);

void		ft_map_editor_menu_parameter_area(variable_list *l);

void		ft_map_editor_menu_parameter_group(variable_list *l);

void		ft_map_editor_menu_parameter_light(variable_list *l);

void		ft_map_editor_menu_parameter_npc(variable_list *l);

void		ft_map_editor_menu_parameter_no_block(variable_list *l);

void		ft_map_editor_menu_parameter_player(variable_list *l);

void		ft_map_editor_menu_parameter_game(variable_list *l);

void		ft_map_editor_menu_parameter_paint(variable_list *l);

void TMP_map_editor_menu_parameter_save_map(variable_list *l);

void TMP_map_editor_menu_parameter_clean_errors(variable_list *l);

void		ft_put_texture_initialize(variable_list *l, utility_list *tmp);

void		ft_put_texture_while(variable_list *l, utility_list *tmp, int x, int y);

void		ft_put_texture_action(variable_list *l, utility_list *tmp);

void		ft_put_texture(variable_list *l);

void		ft_put_text_texture_initialize(variable_list *l, utility_list *tmp);

void		ft_put_text_texture_while(variable_list *l, utility_list *tmp, int x, int y);

void		ft_put_text_texture_action(variable_list *l, utility_list *tmp);

void		ft_put_text_texture(variable_list *l, utility_list *tmp);

void		ft_put_text(variable_list *l);
void		ft_map_editor_triangle_parameters(variable_list *l);

void		ft_map_editor_triangle_actions(variable_list *l);

void		ft_map_editor_triangle(variable_list *l);

void		ft_map_editor_triangle_parameter_triangle(variable_list *l);

void		ft_map_editor_triangle_parameter_triangle_id(variable_list *l);

void		ft_map_editor_triangle_parameter_area(variable_list *l);

void		ft_map_editor_triangle_parameter_group(variable_list *l);

void		ft_map_editor_triangle_parameter_position(variable_list *l);

void		ft_map_editor_triangle_parameter_position_x_all(variable_list *l);

void		ft_map_editor_triangle_parameter_position_y_all(variable_list *l);

void		ft_map_editor_triangle_parameter_position_z_all(variable_list *l);

void		ft_map_editor_triangle_parameter_position_size(variable_list *l);

void		ft_map_editor_triangle_parameter_rotation(variable_list *l);

void		ft_map_editor_triangle_parameter_position_h(variable_list *l);

void		ft_map_editor_triangle_parameter_position_v(variable_list *l);

void		ft_map_editor_triangle_parameter_position_l(variable_list *l);

void		ft_map_editor_triangle_parameter_position_x_1(variable_list *l);

void		ft_map_editor_triangle_parameter_position_y_1(variable_list *l);

void		ft_map_editor_triangle_parameter_position_z_1(variable_list *l);

void		ft_map_editor_triangle_parameter_position_x_2(variable_list *l);

void		ft_map_editor_triangle_parameter_position_y_2(variable_list *l);

void		ft_map_editor_triangle_parameter_position_z_2(variable_list *l);

void		ft_map_editor_triangle_parameter_position_x_3(variable_list *l);

void		ft_map_editor_triangle_parameter_position_y_3(variable_list *l);

void		ft_map_editor_triangle_parameter_position_z_3(variable_list *l);

void		ft_map_editor_triangle_parameter_texture(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_id(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_light(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_opacity(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_x(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_y(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_shift(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_shift_x(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_shift_y(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_adapt(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_stretch(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_repeat(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_adapt_x(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_size_adapt_y(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_sides(variable_list *l);

void		ft_map_editor_triangle_parameter_options(variable_list *l);

void		ft_map_editor_triangle_parameter_create_new(variable_list *l);

void		ft_map_editor_triangle_parameter_create_square(variable_list *l);

void		ft_map_editor_triangle_parameter_duplicate(variable_list *l);

void		ft_map_editor_triangle_parameter_delete(variable_list *l);

void		ft_map_editor_triangle_parameter_texture_view(variable_list *l);

int ft_strings_compare(char *line, char *word, int c);

void		ft_action_x(variable_list *l, int group, int c, char *str);

void		ft_action_y(variable_list *l, int group, int c, char *str);

void		ft_action_z(variable_list *l, int group, int c, char *str);

void		ft_action_calculate_center(variable_list *l, int group);

void		ft_action_h_rotate(variable_list *l, int group);

void		ft_action_h(variable_list *l, int group, int c, char *str);

void		ft_action_v_rotate(variable_list *l, int group);

void		ft_action_v(variable_list *l, int group, int c, char *str);

void		ft_action_l_rotate(variable_list *l, int group);

void		ft_action_l(variable_list *l, int group, int c, char *str);

void		ft_action_s_up(variable_list *l, int group, double value);

void		ft_action_s_do(variable_list *l, int group, double value);

void		ft_action_s_replace(variable_list *l, int group);

void		ft_action_size(variable_list *l, int group, int c, char *str);

void		ft_action_xyzhvls(variable_list *l, int group, int c, char *str);

void		ft_action_start(variable_list *l, int group, int c, char *str);

void		ft_action(variable_list *l);
#endif

