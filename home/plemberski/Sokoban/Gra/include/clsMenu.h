#ifndef CLSMENU_H
#define CLSMENU_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include<clsPlansza.h>
using namespace std;
#include <string>

class clsMenu
{
    static const string plik_z_menu[1];
    ALLEGRO_BITMAP* wskMenu[1];

public:

    void WyswietlMenu();

};

#endif // CLSMENU_H