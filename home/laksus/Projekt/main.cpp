#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#include "bird.h"
#include "board.h"
#include "obs.h"
#include "menu.h"

int obsCount=1, pom, ObstacleCompleted;
bool done, decision_made;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *displ;
queue<Pipe>OBS;
Menu *act_menu;
double angle;

int main(){
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    displ = al_create_display(800, 600);
    al_set_window_title(displ,"Flappy Bird v. 1.0beta");

    Board plansza;
    Bird flap;
    Pipe pip;
    OBS.push(pip);
    MainMenu men;
    SettingsMenu set_menu;
    act_menu = &men;
    act_menu->create();

    event_queue = al_create_event_queue();
    timer = al_create_timer(5.0/60);
    al_start_timer(timer);
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    while(!decision_made){
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_UP || ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                act_menu->select_menu_item(1);
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN || ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                act_menu->select_menu_item(-1);
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                done = true; break;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
                if(act_menu->actual_selection() == 0)
                    decision_made = true;
                else if(act_menu->actual_selection() == 2){
                    act_menu = &set_menu;
                    act_menu->create();
                }
            }
        }
        al_wait_for_event(event_queue, &ev);
    }
    decision_made = false;

    plansza.init(flap.type);
    while(!flap.collision_ground() && !done){
        al_wait_for_event(event_queue, &ev);
        plansza.refresh_background();
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                flap.move(-1,15);
                angle =0;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER){
            flap.move(1,5);
            angle += 0.05;
            angle = min(angle,90.0);
        }
        pom = obsCount;
            while(pom--){
                if(OBS.front().getX()==400){
                        Pipe p;
                        OBS.push(p);
                        obsCount++;
                }
                OBS.front().move(5);
                if(flap.collision_obstacle(OBS.front().getX(),OBS.front().getY()))
                    done = true;
                plansza.refresh_pipe(OBS.front().getX(),OBS.front().getY());
                if(OBS.front().getX()<0){
                    obsCount--;
                    ObstacleCompleted++;
                }
                if(OBS.front().getX()>=0)
                    OBS.push(OBS.front());
                    OBS.pop();
            }

        plansza.refresh_hero(flap.getX(), flap.getY(), angle);
        plansza.refresh_counter(ObstacleCompleted,2);
        plansza.show();
        if(ObstacleCompleted==2){
            plansza.win_lvl();
            done = true;
        }
    }
    if(ObstacleCompleted <2){
        plansza.end_game();
        while(ev.type != ALLEGRO_EVENT_KEY_DOWN)
            al_wait_for_event(event_queue, &ev);
    }
    Sleep(1000);
    al_destroy_display(displ);
    return 0;
}
