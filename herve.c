#include "header.h"

/*
** output of the HUD
** ATTENTION ORDRE D AFFICHAGE DES IMAGES, SUPPERPOSITIONS
*/

void	ft_event_playing_hud(variable_list* l)
{
    int x[2];
    int y[2];
    double percent[2];

    ft_tester_hud(l);

    if (l->hl.live_bar <= 0)
        ft_game_over(l);
    else
    {
        ft_inventory_gestion(l);
        ft_punch(l);
        ft_shoot(l);
        x[0] = 20;
        x[1] = 342;
        y[0] = 913;
        y[1] = 1009;
        percent[0] = 20. * 100. / 1024.;
        percent[1] = 913. * 100. / 1024.;
        ft_img_to_window(l, 34, x, y, percent);

        x[0] = 603;
        x[1] = 1002;
        y[0] = 913;
        y[1] = 1009;
        percent[0] = 603. * 100. / 1024.;
        percent[1] = 913. * 100. / 1024.;
        ft_img_to_window(l, 34, x, y, percent);

        x[0] = 30;
        x[1] = 30 + ((double)(332 - 30) / 100) * l->hl.live_bar;
        y[0] = 955;
        y[1] = 996;
        percent[0] = 30. * 100. / 1024.;
        percent[1] = 955. * 100. / 1024.;
        ft_img_to_window(l, 35, x, y, percent);
        ft_put_ammo_bar(l);
    }
}

/*
return the correct index for the image to put in inventory
*/

int ft_choose_img_inventory(int index)
{
    int img_number = 0;

    if (index == 0)
        img_number = 50;//fist
    else if (index == 1)
        img_number = 50;//gun ammo
    else if (index == 2)
        img_number = 50;//box
    else if (index == 3)
        img_number = 50;//arm

    return(img_number);
}


void ft_put_ammo_bar(variable_list* l)
{
    int x[2] = { 614, 679 };
    int y[2] = { 992, 996 };
    double percent[2] = { (614. * 100. / 1024.), (992. * 100. / 1024.) };

    x[1] = 614 + ((double)(679 - 614) / 24) * l->hl.ammo;
    ft_img_to_window(l, 41, x, y, percent);
}

/*
** inventory checker
*/

void ft_inventory_gestion(variable_list* l)
{
    if (l->i.state[SDL_SCANCODE_1])//press 1
    {
        l->i.state[SDL_SCANCODE_1] = 0;
        l->hl.item_select = 0;
    }
    else if (l->i.state[SDL_SCANCODE_2])//press 2
    {
        l->i.state[SDL_SCANCODE_2] = 0;
        l->hl.item_select = 1;
    }
    else if (l->i.state[SDL_SCANCODE_3])//press 3
    {
        l->i.state[SDL_SCANCODE_3] = 0;
        l->hl.item_select = 2;
    }
}

/*
** for punch, default weapon, fix frame
*/

void ft_punch(variable_list* l)
{
    static int frame = 0;
    int x[2] = { 0, 1024 };
    int y[2] = { 700, 1024 };
    double percent[2] = { 0.0, 69 };

    if (l->hl.item_select == 0)
    {
        if (l->i.mouse == 1 && frame < l->cooldown)
            frame = l->cooldown + 40;
        if (l->cooldown < frame - 30)
            ft_img_to_window(l, 37, x, y, percent);
        else if (l->cooldown < frame - 20)
            ft_img_to_window(l, 38, x, y, percent);
        else if (l->cooldown < frame - 10)
            ft_img_to_window(l, 37, x, y, percent);
        else
            ft_img_to_window(l, 36, x, y, percent);
    }
}

void ft_shoot(variable_list* l)
{
    static int frame = 0;
    int x[2] = { 0, 1024 };
    int y[2] = { 700, 1024 };
    double percent[2] = { 0.0, 69 };

    if (l->hl.item_select == 1)
    {
        if (l->i.mouse == 1 && frame < l->cooldown)
        {
            l->hl.ammo--;
            frame = l->cooldown + 20;
        }
        if (l->cooldown < frame - 10 && l->hl.ammo > 0)
            ft_img_to_window(l, 40, x, y, percent);
        else
            ft_img_to_window(l, 39, x, y, percent);
    }
}

/*
** check is a value is between two  other values.
*/

int ft_nbrisinside(int a, int min, int max)
{
    if (a >= min && a <= max)
        return(1);
    return(0);
}

/*
** ft that mod coord in a img to find the corresponding one in the window
*/

double ft_coord_button_menu(variable_list* l, double coord, int window)
{
    double num;

    num = ((double)coord / (double)1024) * window;
    return(num);
}

/*
** recuperation of clics on main menu
** check if size table ok ..
*/

void ft_main_menu_clic(variable_list* l)
{
    double x[2];
    double y[6];
    int xf[2];
    int yf[2];
    double percent[2];

    xf[0] = 0;
    xf[1] = 1024;
    yf[0] = 0;
    yf[1] = 1024;
    percent[0] = 0;
    percent[1] = 0;
    ft_img_to_window(l, 32, xf, yf, percent);
    if (l->i.mouse == 1)
    {
        x[0] = ft_coord_button_menu(l, (double)310, WDWF);
        x[1] = ft_coord_button_menu(l, (double)747, WDWF);
        y[0] = ft_coord_button_menu(l, (double)360, WDHF);//game
        y[1] = ft_coord_button_menu(l, (double)503, WDHF);
        y[2] = ft_coord_button_menu(l, (double)527, WDHF);//edit
        y[3] = ft_coord_button_menu(l, (double)671, WDHF);
        y[4] = ft_coord_button_menu(l, (double)697, WDHF);//edit
        y[5] = ft_coord_button_menu(l, (double)841, WDHF);

        if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[0], y[1]) == 1)//play
        {
            printf("GAME\n");
            SDL_ShowCursor(0);
            l->menu_mode = 1;
        }
        else if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[2], y[3]) == 1)//edit
        {
            printf("EDIT\n");
            SDL_ShowCursor(1);
            l->menu_mode = 2;
        }
        else if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[4], y[5]) == 1)//exit
        {
            printf("EXIT\n");
            ft_free_and_exit(l);
        }
       // printf("CLICK mouse x %d | mouse y = %d | time press = %d | mouse = %d \n", l->i.mouse_x, l->i.mouse_y, l->i.mouse_time_pressing, l->i.mouse);
    }
}

/*
** put texture on the full window
** bug occasionel ds put texture while
*/

void ft_img_to_window(variable_list* l, int img_index, int* x, int* y, double* percent)
{
    l->u.action = -1;
    l->u.colors = l->texture_colors[img_index];
    l->u.tsx = x[0];
    l->u.tex = x[1];
    l->u.tsy = y[0];
    l->u.tey = y[1];
    l->u.sizex = (double)WDWF / 1024;
    l->u.sizey = (double)WDHF / 1024;
    l->u.size = 1;
    l->u.wsx = percent[0];
    l->u.wsy = percent[1];
    ft_put_texture(l);
}

/*
    GAME OVER
    bizarrement ne renvoie pas a loop comme il faut, CLAVIER AZERTY
*/

void ft_game_over(variable_list* l)
{
    int x[2];
    int y[2];
    double percent[2];

    x[0] = 0;
    x[1] = 1024;
    y[0] = 0;
    y[1] = 1024;
    percent[0] = 0;
    percent[1] = 0;
    ft_img_to_window(l, 33, x, y, percent);

    if (l->i.state[SDL_SCANCODE_RETURN])
    {
        l->menu_mode = 0;
        l->hl.live_bar = 100;
        SDL_ShowCursor(1);
    }
}

void ft_tester_hud(variable_list* l)
{
    if (l->i.state[SDL_SCANCODE_M])//key M
    {
        l->hl.live_bar -= 1;
        printf("valeur barre = %d", l->hl.live_bar);
    }
}

/*
   if (l->i.key_input)
   {
       if (l->i.key_input == l->hl.obj_key[0])// key 1
       {
           if (l->hl.obj[0] == 0)
           {
               l->hl.obj[0]++;
               ft_punch(l);
           }
           else if (l->hl.obj[1] == 0)
           {
               l->hl.obj[1]++;
               l->hl.obj[0]--;
               ft_shoot(l);
           }
       }

       if (l->i.key_input == l->hl.obj_key[1])// key 2
       {
           if (l->hl.obj[2] == 0)
           {
               l->hl.obj[2]++;
               printf("use of obj index 2\n");
           }
       }

       if (l->i.key_input == l->hl.obj_key[2])// key 3
       {
           if (l->hl.obj[3] == 0)
           {
               l->hl.obj[3]++;
               printf("use of obj index 3\n");
           }
        }
   }*/





   /*

   static unsigned int		ft_dest_size(int n)
   {
       unsigned int		i;

       i = 0;
       if (n < 0)
       {
           i++;
           n = n * -1;
       }
       while (n != 0)
       {
           i++;
           n = n / 10;
       }
       return (i);
   }

   static char* ft_fill_dest(unsigned int i, int nb, char* dest)
   {
       if (nb < 0)
       {
           dest[0] = '-';
           nb = -nb;
       }
       while (nb != 0)
       {
           dest[i] = ((nb % 10) + 48);
           nb = nb / 10;
           i--;
       }
       return (dest);
   }

   char* my_itoa(int n)
   {
       char* dest;
       unsigned int		i;
       int					nb;

       nb = n;
       i = 0;
       if (n == 0)
       {
           return (ft_strdup("0"));
       }
       if (n == INT_MIN)//valeur neg int max -2147483648
       {
           return (ft_strdup("-2147483648"));
       }
       i = ft_dest_size(n);
       if (!(dest = ft_strnew(i)))
           return (NULL);
       i = i - 1;
       dest = ft_fill_dest(i, nb, dest);
       return (dest);
   }

   char* ft_strdup(const char* s)
   {
       char* dup = NULL;
       size_t	len;
       int		i;

       i = 0;
       len = ft_strlen(s);
       if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
           return (NULL);
       while (s[i] != '\0')
       {
           dup[i] = s[i];
           i++;
       }
       dup[i] = '\0';
       return (dup);
   }

   size_t	ft_strlen(const char* s)
   {
       size_t i;

       i = 0;
       while (s[i] != '\0')
       {
           i++;
       }
       return (i);
   }
   */




