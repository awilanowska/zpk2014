#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include<iostream>
#include "menu.h"

using namespace std;

MainMenu::MainMenu(){}

MainMenu::~MainMenu(){}

void MainMenu::display(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    al_draw_scaled_bitmap(title,0,0,1500,1000,175,100,700,600,0);

    for(int i = 0; i < ButtonCount; i++)
        show_button(buttons[i],130+200*i,400);

    al_flip_display();
}

void MainMenu::create(){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "images");

    al_set_path_filename(path, "title_screen.png");
    title = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background1.jpg");
    background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt1.png");
    buttons[0] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt2.png");
    buttons[1] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt3.png");
    buttons[2] = al_load_bitmap(al_path_cstr(path, '/'));

    actButton = 0;
    display();
    select_menu_item(0);
    al_destroy_path(path);
}

void MainMenu::show_button(ALLEGRO_BITMAP* but, int pos_x, int pos_y){
    al_draw_scaled_bitmap(but,0,0,325,185,pos_x,pos_y,140,70,0);
}

void MainMenu::select_menu_item(int direction){
    display();
    actButton += direction;
    if(actButton > (ButtonCount-1))
        actButton = 0;
    else if(actButton < 0)
        actButton = ButtonCount - 1;
    al_draw_rounded_rectangle(130+200*actButton,400,130+200*actButton+140,470,25,25,al_map_rgb(0,0,0),5);
    al_flip_display();
}


int MainMenu::actual_selection(){
    return actButton;
}


SettingsMenu::SettingsMenu(){}

SettingsMenu::~SettingsMenu(){}

void SettingsMenu::display(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    al_draw_scaled_bitmap(title,0,0,1500,1000,175,100,700,600,0);

    for(int i = 0; i < ButtonCount; i++)
        show_button(buttons[i],130+200*i,400);

    al_flip_display();
}

void SettingsMenu::create(){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "images");

    al_set_path_filename(path, "title_screen.png");
    title = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background1.jpg");
    background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt1.png");
    buttons[0] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt2.png");
    buttons[1] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt3.png");
    buttons[2] = al_load_bitmap(al_path_cstr(path, '/'));

    actButton = 0;
    display();
    select_menu_item(0);
    al_destroy_path(path);
}

void SettingsMenu::show_button(ALLEGRO_BITMAP* but, int pos_x, int pos_y){
    al_draw_scaled_bitmap(but,0,0,325,185,pos_x,pos_y,140,70,0);
}

void SettingsMenu::select_menu_item(int direction){
    display();
    actButton += direction;
    if(actButton > (ButtonCount-1))
        actButton = 0;
    else if(actButton < 0)
        actButton = ButtonCount - 1;
    al_draw_rounded_rectangle(130+200*actButton,400,130+200*actButton+140,470,25,25,al_map_rgb(0,0,0),5);
    al_flip_display();
}


int SettingsMenu::actual_selection(){
    return actButton;
}
