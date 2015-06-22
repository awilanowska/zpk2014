#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
using namespace std;

#include<clsMenu.h>
#include<clsPlansza.h>
#include<clsLudzik.h>
#include<clsSkrzynka.h>

const int screen_w = 800;
const int screen_h = 600;
const float FPS = 60.0;

int PozycjaLudzikaWiersz(clsPlansza);
int PozycjaLudzikaKolumna(clsPlansza);

int main(){

/* ******************************************************************************************************************* */
/*Inicjalizacja allegro                                                                                                */
/* ******************************************************************************************************************* */

//inicjalizacja czcionek
    al_init_font_addon();

//inicjalizacja allegro + klawiatury + obrazow + czcionek ttf
    if (!al_init() || !al_install_keyboard()  || !al_init_image_addon() || !al_init_ttf_addon())
    {
        cout << "Blad inicjalizacji 1." << endl;
        return 1;
    }

// wskazniki na ekran, czas, kolejke zdarzen, czcionke
    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 12, 0 );

//sprawdzenie poprawnosci wskaznikow
    if (display == NULL || timer == NULL || event_queue == NULL || font == NULL)
    {
        cout << "Blad inicjalizacji 2." << endl;
        return 2;
    }
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

 /*   al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

*/    al_clear_to_color(al_map_rgb(0,0,0));
/*    al_flip_display();

*/

/* ******************************************************************************************************************* */
/*Wyswietlenie MENU wraz z komunikatem powitalnym. Mozliwosc wybrania odpowiedniej planszy oraz wyjscia z programu.    */
/* ******************************************************************************************************************* */

    clsMenu objMenu;
    objMenu.WyswietlKomunikat(font);

    int a;
    cin >> a;


//<> wybiera odpowiedni� plansz� (decyduje u�ytkownik)
//<> wy��cza program (decyduje u�ytkownik)



/* ******************************************************************************************************************* */
/*  Wyswietlenie Planszy, wczytanie danych, rysowanie Planszy wraz z mozliwoscia wyswietlenie MENU.                    */
/* ******************************************************************************************************************* */

    clsPlansza objPlansza;
    objPlansza.WczytajDane();
    objPlansza.WypiszDane();
    objPlansza.KonwertujDane();
    objPlansza.przygotuj_bitmapy();
    objPlansza.rysuj_statyczne();
    objPlansza.rysuj_ruchome(0);

    //objPlansza.WyswietlMenu();
// Rysuje si� na okr�g�o.

/* ******************************************************************************************************************* */
/*  Poruszanie ludzikiem, sprawdzenie czy ma energie, czy ruch mozliwy, czy stoi obok skrzynki -> ruch Skrzynka        */
/* ******************************************************************************************************************* */
        int x = objPlansza.PozycjaLudzikaWiersz();
        int y = objPlansza.PozycjaLudzikaKolumna();
        clsLudzik objLudzik(x, y);
        cout << endl << endl << "Ludzik - wiersz: " << x + 1 << endl << "Ludzik - kolumna: " << y + 1;
         cin >> a;
//        cout << endl << "czy mozna ruszyc sie w D: " << objLudzik.MozliwyRuch(objPlansza, 'D') << " G: " << objLudzik.MozliwyRuch(objPlansza, 'G');
 //       cout    << " L: " << objLudzik.MozliwyRuch(objPlansza, 'L') << " P: " << objLudzik.MozliwyRuch(objPlansza, 'P');

/*
while(true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

int x = 0;
if (static_cast<long int>(time(NULL))%4 == 0)
{  x = 1;  }

cout << x << " " << timer << " " ;
objPlansza.rysuj_ruchome(x);


        if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                break;
            }
        }
    }*/

//<> je�li U�ytkownik wykona� ruch Ludzikiem:
    //objLudzik.SprawdzEnergie();
    //objLudzik.MozliwyRuch();
    //objLudzik.ObokSkrzynka();
    //objLudzik.Ruch();

/* ******************************************************************************************************************* */
/*  Poruszanie Skrzynka, sprawdzenie czy ruch mozliwy, czy ukonczono Plansze ->                                        */
/*  -> zapisanie ze ukonczono plansze, sprawdzenie czy sa jakies nieukonczone plansze -> narysowanie / koniec gry      */
/* ******************************************************************************************************************* */

    //clsSkrzynka objSkrzynka;
    //objSkrzynka.MozliwyRuch();
    //objSkrzynka.Ruch();

/*    if (objSkrzynka.CzyUkonczono()) // sprawdza czy ukonczono plansze
    {
       objPlansza.Ukonczono();    // zapisanie ze plansze ukonczono

        if (objPlansza.CzySaNieukonczone()) // sprawdcza czy sa jescze jakies nieukonczone plansze
        {
            // Rysuje nasteppna plansz�
        }
        else
            // Ko�czy program (je�li to ostatnia uko�czona plansza).
    }
*/
    return 0;
}
