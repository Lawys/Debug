#include "header.h"


/*
** output of the HUD
** ATTENTION ORDRE D AFFICHAGE DES IMAGES, SUPPERPOSITIONS
*/

void	ft_event_playing_hud(variable_list* l)
{
    //test
    ft_tester_hud(l);

    //  ft_nbr_no_block_recuperation(l);
      //------------------------

    if (l->hl.live_bar <= 0)
        ft_game_over(l);
    else
    {
        ft_inventory_gestion(l);
        ft_punch(l);
        ft_shoot(l);
        ft_throw(l);
        ft_output_hud(l);
        ft_put_icone(l);//en test
        if (l->hl.item_select == 1)
            ft_put_ammo_bar(l);
    }
}

/*
**
*/

coord_img ft_pick_icone(variable_list* l, int index, int in_hud)
{
    if (index == 0 && in_hud == 1)// 0 = fist
    {
        return((coord_img) { 28, 92, 587, 651, 59.9, 90.5, 1 });//fist box
    }
    if (index == 1 && in_hud == 1)// 1 = gun
    {
        return((coord_img) { 27, 91, 426, 490, 59.9, 90.5, 1 });//first box
    }
    if (index == 2 && in_hud == 1) // 2 = grenade
    {
        return((coord_img) { 28, 92, 778, 842, 59.9, 90.5, 1 });//first box
    }
    if (index == 3 && in_hud == 2)// 3 = cut arm
    {
        return((coord_img) { 110, 174, 426, 490, 67.6, 90.5, 1 });//second box
    }
    if (index == 4 && in_hud == 2)// 4 = remote
    {
        return((coord_img) { 107, 171, 587, 651, 67.6, 90.5, 1 });//second box
    }
    if (index == 5 && in_hud == 3)// 5 = box
    {
        return((coord_img) { 182, 246, 426, 490, 74.8, 90.5, 1 });//third box
    }
    // etc.
    return((coord_img) { 0, 0, 0, 0, 0, 0, 1 });
}

/*
** affiche les mini icones des objet recuperer
** si weapon recup, valeur init a 1, sinon 0
** pour equiper un objet, verifier d abord qu il est recuperer.
*
* uniquement pour case 1 ?
*/

void ft_put_icone(variable_list* l)
{
    int i;
    coord_img coord1;
    coord_img coord2;
    coord_img coord3;

    i = 0;

    while (i < 6)//valeur de nombre obj
    {

        if (i == l->hl.item_select && l->hl.obj[i][2] == 1)
        {
            if (l->hl.obj[i][0] == 1)
                l->hl.inv1 = l->hl.item_select;
            else if (l->hl.obj[i][0] == 2)
                l->hl.inv2 = l->hl.item_select;
            else if (l->hl.obj[i][0] == 3)
                l->hl.inv3 = l->hl.item_select;
            printf("item = %d | obj[%d][2] = %d | inv1 %d| inv2 %d | inv3 %d\n", l->hl.item_select, i, l->hl.obj[i][2], l->hl.inv1, l->hl.inv2, l->hl.inv3);
        }
        i++;
    }
    coord1 = ft_pick_icone(l, l->hl.inv1, 1);
    coord2 = ft_pick_icone(l, l->hl.inv2, 2);
    coord3 = ft_pick_icone(l, l->hl.inv3, 3);

    ft_img_to_window(l, 34, coord1);
    ft_img_to_window(l, 34, coord2);
    ft_img_to_window(l, 34, coord3);

}


/*
** verifie si gun ou grenade recup
* first box of hud
*/
void ft_weapons_select(variable_list* l)
{
    if (l->hl.obj[0][2] == 1 && l->hl.item_select == 0)
    {
        if (l->hl.obj[1][2] == 1)
            l->hl.item_select = 1;
        else if (l->hl.obj[2][2] == 1)
            l->hl.item_select = 2;
    }
    else if (l->hl.obj[1][2] == 1 && l->hl.item_select == 1)
    {
        if (l->hl.obj[2][2] == 1)
            l->hl.item_select = 2;
        else
            l->hl.item_select = 0;
    }
    else if (l->hl.obj[2][2] == 1)
        l->hl.item_select = 0;
}

/*
* for obj in second box hud
*/

void ft_select_obj(variable_list* l)
{
    if (l->hl.obj[3][2] == 1)
    {
        l->hl.item_select = 3;
        if (l->hl.inv2 == 3)
            l->hl.item_select = 4;
    }
    else if (l->hl.obj[4][2] == 1)
    {
        if (l->hl.obj[3][2] == 1 && l->hl.inv2 == 4)
            l->hl.item_select = 3;
        else
            l->hl.item_select = 4;
    }
}

/*
** inventory checker
** utilisation voulue :
*
*
* press 1 = fist, gun, grenade On rotation if recover
* press 2 = arm, remote
* press 3 = box
*
*/

void ft_inventory_gestion(variable_list* l)
{
    if (l->i.state[SDL_SCANCODE_1])//press 1
    {
        l->i.state[SDL_SCANCODE_1] = 0;
        ft_weapons_select(l);
    }
    else if (l->i.state[SDL_SCANCODE_2])//press 2
    {
        l->i.state[SDL_SCANCODE_2] = 0;
        ft_select_obj(l);
    }
    else if (l->i.state[SDL_SCANCODE_3])//press 3
    {
        l->i.state[SDL_SCANCODE_3] = 0;
        if (l->hl.obj[5][2] == 1)//box
            l->hl.item_select = 5;
    }
}

/*
** for punch, default weapon
*/

void ft_punch(variable_list* l)
{
    static int frame = 0;

    if (l->hl.item_select == 0)
    {
        if (l->i.mouse == 1 && frame < l->cooldown)
            frame = l->cooldown + 40;
        if (l->cooldown < frame - 30)
            ft_img_to_window(l, 35, (coord_img) { 11, 368, 491, 666, 9.8, 82.6, 1 });
        else if (l->cooldown < frame - 20)
            ft_img_to_window(l, 35, (coord_img) { 9, 500, 678, 930, 9.8, 75.2, 1 });
        else if (l->cooldown < frame - 10)
            ft_img_to_window(l, 35, (coord_img) { 11, 368, 491, 666, 9.8, 82.6, 1 });
        else
            ft_img_to_window(l, 35, (coord_img) { 10, 277, 346, 484, 9.8, 86.5, 1 });
    }
}

/*
** Shoot
*/

void ft_shoot(variable_list* l)
{
    static int frame = 0;

    if (l->hl.item_select == 1)
    {
        if (l->i.mouse == 1 && frame < l->cooldown)
        {
            l->hl.ammo--;
            frame = l->cooldown + 20;
        }
        if (l->cooldown < frame - 10 && l->hl.ammo > 0)
            ft_img_to_window(l, 35, (coord_img) { 384, 593, 67, 337, 35.6, 73.6, 1 });
        else
            ft_img_to_window(l, 35, (coord_img) { 17, 167, 171, 337, 40.1, 83.6, 1 });
    }
}

/*
** ft throw grenade
*/

void ft_throw(variable_list* l)
{
    static int frame = 0;

    if (l->hl.item_select == 2)
    {
        if (l->i.mouse == 1 && frame < l->cooldown)
            frame = l->cooldown + 40;
        if (l->cooldown < frame - 30)
            ft_img_to_window(l, 35, (coord_img) { 551, 988, 351, 661, 48.2, 70.0, 1 });
        else if (l->cooldown < frame - 20)
            ft_img_to_window(l, 35, (coord_img) { 538, 1008, 666, 950, 42.5, 72.6, 1 });
        else if (l->cooldown < frame - 10)
            ft_img_to_window(l, 35, (coord_img) { 551, 988, 351, 661, 48.2, 70.0, 1 });
        else
            ft_img_to_window(l, 35, (coord_img) { 612, 989, 32, 341, 53.3, 70.0, 1 });
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
** ft provisoire en attendant implementation de recuperation d objet
*/

void ft_fill_inventory(variable_list* l, int index, int in_hud, int type, int status, int img, int if_hud)
{
    l->hl.obj[index][0] = in_hud; //type emplacement 1 2 ou 3 ds l inventaire du hud
    l->hl.obj[index][1] = type; //type d objet : remote, box, arm, gun, etc
    l->hl.obj[index][2] = status;// 0 ou 1 pour recuperer
    l->hl.obj[index][3] = img;// numero de la texture ou se trouve l image ?
    l->hl.obj[index][4] = 0;//coord ds map x ?
    l->hl.obj[index][5] = 0;// coord ds map y ?
    l->hl.obj[index][6] = 0;//si il est afficher ds inventaire 0 ou 1 ?
    l->hl.obj[index][7] = 0;
    l->hl.obj[index][8] = 0;
    l->hl.obj[index][9] = 0;
}

/*
** recuperation of clics on main menu
** check if size table ok ..
*/

void ft_main_menu_clic(variable_list* l)
{
    double x[2];
    double y[6];


    //test fill inventaire ici
    ft_fill_inventory(l, 0, 1, 0, 1, 42, 1);//fist
    ft_fill_inventory(l, 1, 1, 1, 0, 42, 0);//gun
    ft_fill_inventory(l, 2, 1, 2, 0, 42, 0);//grenade
    ft_fill_inventory(l, 3, 2, 3, 0, 42, 0);//arm
    ft_fill_inventory(l, 4, 2, 4, 0, 42, 0);//remote
    ft_fill_inventory(l, 5, 3, 5, 0, 42, 0);//box
    //



    ft_img_to_window(l, 32, (coord_img) { 0, 1024, 0, 1024, 0, 0, 1 });
    if (l->i.mouse == 1)
    {
        x[0] = ft_coord_button_menu(l, (double)310, WDWF);
        x[1] = ft_coord_button_menu(l, (double)747, WDWF);
        y[0] = ft_coord_button_menu(l, (double)360, WDHF);//game
        y[1] = ft_coord_button_menu(l, (double)503, WDHF);
        y[2] = ft_coord_button_menu(l, (double)527, WDHF);//edit
        y[3] = ft_coord_button_menu(l, (double)671, WDHF);
        y[4] = ft_coord_button_menu(l, (double)697, WDHF);//exit
        y[5] = ft_coord_button_menu(l, (double)841, WDHF);

        if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[0], y[1]) == 1)//play
        {
            printf("GAME\n");
            l->p.x = l->p.start_x;
            l->p.y = l->p.start_y;
            l->p.z = l->p.start_z;
            l->hl.live_bar = l->p.start_hp;
            l->hl.ammo = l->p.start_ammo;
            l->hl.obj[0][2] = l->p.start_item[0];
            l->hl.obj[1][2] = l->p.start_item[1];
            l->hl.obj[2][2] = l->p.start_item[2];
            l->hl.obj[3][2] = l->p.start_item[3];
            l->hl.obj[4][2] = l->p.start_item[4];
            l->hl.obj[5][2] = l->p.start_item[5];
            l->hl.obj[6][2] = l->p.start_item[6];
            l->hl.obj[7][2] = l->p.start_item[7];
            l->hl.obj[8][2] = l->p.start_item[8];
            l->triangle_select = -1;
            l->area_select = -1;
            l->group_select = -1;
            SDL_ShowCursor(0);
            l->menu_mode = 1;
        }
        else if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[2], y[3]) == 1)//edit
        {
            printf("EDIT\n");
            int i;
            i = -1;
            while (++i < MAX_GROUPS)
                l->g.exist[i] = 1;
            SDL_ShowCursor(1);
            l->menu_mode = 2;
        }
        else if (ft_nbrisinside(l->i.mouse_x, x[0], x[1]) && ft_nbrisinside(l->i.mouse_y, y[4], y[5]) == 1)//exit
        {
            printf("EXIT\n");
            ft_free_and_exit(l);
        }
    }
}

/*
** put texture on the full window
*/

void ft_img_to_window(variable_list* l, int img_index, coord_img ci)
{
    l->u.action = -1;
    l->u.colors = l->texture_colors[img_index];
    l->u.tsx = ci.x1;
    l->u.tex = ci.x2;
    l->u.tsy = ci.y1;
    l->u.tey = ci.y2;
    l->u.sizex = (double)WDWF / 1024;
    l->u.sizey = (double)WDHF / 1024;
    l->u.size = ci.size;
    l->u.wsx = ci.percx;
    l->u.wsy = ci.percy;
    ft_put_texture(l);
}

/*
    GAME OVER
    bizarrement ne renvoie pas a loop comme il faut, CLAVIER AZERTY
*/

void ft_game_over(variable_list* l)
{

    ft_img_to_window(l, 33, (coord_img) { 0, 1024, 0, 1024, 0, 0, 1 });

    if (l->i.state[SDL_SCANCODE_RETURN])
    {
        l->menu_mode = 0;
        l->hl.live_bar = 100;
        SDL_ShowCursor(1);
    }
}

/*
reparer affichage bar de vie
*/
void ft_output_hud(variable_list* l)
{
    l->hl.ci.x1 = 18;
    l->hl.ci.y1 = 46;
    l->hl.ci.x2 = 341;
    l->hl.ci.y2 = 143;
    l->hl.ci.percx = 2;
    l->hl.ci.percy = 89;
    l->hl.ci.size = 1;
    ft_img_to_window(l, 34, l->hl.ci);//barre de vie

    l->hl.ci.x1 = 18;
    l->hl.ci.y1 = 154;
    l->hl.ci.x2 = 418;
    l->hl.ci.y2 = 251;
    l->hl.ci.percx = 58.8;
    l->hl.ci.percy = 89;
    l->hl.ci.size = 1;
    ft_img_to_window(l, 34, l->hl.ci);//inventaire

    l->hl.ci.x1 = 27;
    l->hl.ci.y1 = 271;
    l->hl.ci.x2 = 27 + ((double)(332 - 27) / 100) * l->hl.live_bar;//330
    l->hl.ci.y2 = 313;
    l->hl.ci.percx = 3;
    l->hl.ci.percy = 93.4;
    l->hl.ci.size = 1;
    ft_img_to_window(l, 34, l->hl.ci);//live bar
}

/*
** output of the ammo bar in the hud
*/
void ft_put_ammo_bar(variable_list* l)
{

    l->hl.ci.x1 = 27;
    l->hl.ci.x2 = 93;
    l->hl.ci.y1 = 338;
    l->hl.ci.y2 = 342;
    l->hl.ci.percx = 59.9;
    l->hl.ci.percy = 96.4;
    l->hl.ci.size = 1;
    ft_img_to_window(l, 34, l->hl.ci);
}



void ft_tester_hud(variable_list* l)
{

    if (l->i.state[SDL_SCANCODE_M])//key M
    {
        l->hl.live_bar -= 1;
        printf("valeur barre = %d", l->hl.live_bar);
    }
    if (l->i.state[SDL_SCANCODE_G])//recup gun
    {
        l->hl.obj[1][2] = 1;
        printf("G pressed\n");
    }
    if (l->i.state[SDL_SCANCODE_F])//recup fist
    {
        l->hl.obj[0][2] = 1;
        printf("F pressed\n");
    }
    if (l->i.state[SDL_SCANCODE_H])//recup grenade
    {
        l->hl.obj[2][2] = 1;
        printf("H pressed\n");
    }
    if (l->i.state[SDL_SCANCODE_C])//recup arm
    {
        l->hl.obj[3][2] = 1;
        printf("C pressed\n");
    }
    if (l->i.state[SDL_SCANCODE_V])//recup remote
    {
        l->hl.obj[4][2] = 1;
        printf("V pressed\n");
    }
    if (l->i.state[SDL_SCANCODE_B])//recup box
    {
        l->hl.obj[5][2] = 1;
        printf("B pressed\n");
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
   ** compte le nombre d objet ds le jeux
   */

void ft_nbr_no_block_recuperation(variable_list* l)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (i <= MAX_GROUPS)
    {
        if (l->g.no_block[i])
            count++;
        i++;
    }
    printf("COUNT %d\n", count);
    //  i = 0;
    while (i < count)
    {
        //    printf("objet[%d] =  %d\n", i, l->g.no_block[i]);
        i++;
    }

}
//----------------------------------------------------------------//


/*
* IMG 60
health
x1 = 18
y1 = 46
x2 = 341
y2 = 143

inventory
x1 = 18
y1 = 154
x2 = 418
y2 = 251

health bar
x1 = 27
y1 = 271
x2 = 330
y2 = 313

ammo bar
x1 = 27
y1 = 338
x2 = 93
y2 = 343

gun1
x1 = 27
y1 = 365
x2 = 95
y2 = 398


gun2
x1 = 27
y1 = 426
x2 = 91
y2 = 490

fist1
x1 = 27
y1 = 503
x2 = 93
y2 = 564

fist2
x1 = 28
y1 = 587
x2 = 92
y2 = 651

grenade1
x1 = 32
y1 = 677
x2 = 87
y2 = 741

grenade2
x1 = 28
y1 = 778
x2 = 92
y2 = 842

arm1
x1 = 110
y1 = 355
x2 = 158
y2 = 413

arm2
x1 = 110
y1 = 426
x2 = 174
y2 = 490

controler1
x1 = 110
y1 = 507
x2 = 167
y2 = 564

controler2
x1 = 107
y1 = 587
x2 = 171
y2 = 651

box1
x1 = 187
y1 = 357
x2 = 239
y2 = 409

box2
x1 = 182
y1 = 426
x2 = 246
y2 = 490


IMG 61
gun frame 1
x1 = 17
y1 = 171
x2 = 167
y2 = 337

gun frame 2
x1 = 175
y1 = 124
x2 = 382
y2 = 336

gun frame 3
x1 = 384
y1 = 67
x2 = 593
y2 = 337


punch frame 1
x1 = 10
y1 = 346
x2 = 277
y2 = 484

punch frame 2
x1 = 11
y1 = 491
x2 = 368
y2 = 666

prunch frame 3
x1 = 9
y1 = 678
x2 = 500
y2 = 930


throw frame 1
x1 = 612
y1 = 32
x2 = 989
y2 = 341

throw frame 2
x1 = 551
y1 = 351
x2 = 988
y2 = 661

throw frame 3
x1 = 538
y1 = 666
x2 = 1008
y2 = 950


*/