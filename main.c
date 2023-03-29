#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "vaisseau.h"
#include "color.h"
#include "star.h"
#include "enemy.h"
#include "text.h"
#include "shot.h"

#define LARGEUR 800
#define LONGUEUR 500
#define FPS 60.0



ALLEGRO_DISPLAY* setting() {
    srand(time(NULL));
    assert(al_init());
    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(LARGEUR, LONGUEUR);
    assert(display != NULL);
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_image_addon());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    al_init_ttf_addon();
    al_set_window_title(display, "Title");
    al_set_window_position(display, 500, 100);
    al_flip_display();
    return display;
}

void game(){
    enum KEYS {UP, DOWN, LEFT, RIGHT, KEYS_MAX}; //KEYS_MAX = 2 sert donc à exprimer le nb de touches possibles pour le tableau
    int keys[KEYS_MAX] = {0};

    ALLEGRO_DISPLAY* display=setting();
    Ship joueur;
    star starlist[NBSTAR];
    Beast beastlist[BEASTMAX];
    ALLEGRO_FONT* texte = setuptext();
    Missile m;
    setstate(beastlist);
    int isEnd=0, moveaccess = 0, sens = 0;
    int indiceBeast = 0;

    ALLEGRO_EVENT_QUEUE*queue;
    ALLEGRO_TIMER* timer = al_create_timer(1/FPS);
    queue=al_create_event_queue();
    assert(queue);

    al_register_event_source(queue,al_get_display_event_source(display));
    al_register_event_source(queue,al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    xstar(starlist,LONGUEUR, LARGEUR, STARSIZE);
    startship(&joueur);
    setupshoot(&m, joueur);
    al_flip_display();

    while(!isEnd){
        ALLEGRO_EVENT event={0};
        al_wait_for_event(queue,&event);
        switch(event.type){
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                isEnd=1;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_ESCAPE:
                        isEnd=1;
                        break;
                    case ALLEGRO_KEY_DOWN :
                        sens = 2;
                        moveaccess = moveupdown(&joueur);
                        if (moveaccess !=0) {
                            keys[DOWN] = 1;
                        }
                        break;
                    case ALLEGRO_KEY_UP :
                        sens = 1;
                        moveaccess = moveupdown(&joueur);
                        if (moveaccess !=0) {
                            keys[UP] = 1;
                        }
                        break;
                    case ALLEGRO_KEY_LEFT :
                        sens = 4;
                        moveaccess = moveupdown(&joueur);
                        if (moveaccess !=0) {
                            keys[LEFT] = 1;
                        }
                        break;
                    case ALLEGRO_KEY_RIGHT :
                        sens = 3;
                        moveaccess = moveupdown(&joueur);
                        if(moveaccess != 0) {
                            keys[RIGHT] = 1;
                        }
                        break;
                    case ALLEGRO_KEY_P :
                        joueur.life = 0;
                        break;
                    case ALLEGRO_KEY_D :
                        joueur.life += 1;
                        break;
                    case ALLEGRO_KEY_SPACE :
                        m.state = 1;
                        break;
                }
                break;

            case ALLEGRO_EVENT_KEY_UP :
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_DOWN :
                        keys[DOWN] = 0;
                        break;
                    case ALLEGRO_KEY_UP :
                        keys[UP] = 0;
                        break;
                    case ALLEGRO_KEY_LEFT :
                        keys[LEFT] = 0;
                        break;
                    case ALLEGRO_KEY_RIGHT :
                        keys[RIGHT] = 0;
                        break;
                }
                break;

            case ALLEGRO_EVENT_TIMER:
                if (moveupdown(&joueur) != 0){
                    joueur.y += keys[DOWN] * joueur.speed;
                    joueur.y -= keys[UP] * joueur.speed;
                    joueur.x -= keys[LEFT] * joueur.speed;
                    joueur.x += keys[RIGHT] * joueur.speed;
                    if (m.state == 0) {
                        m.y = joueur.y+ joueur.size/4;
                        m.x = joueur.x+ joueur.size/4;
                    }
                }
                if (checkEnd(joueur, texte) !=1) {
                    al_clear_to_color(choose_color('n'));
                    moveallstars(starlist);
                    drawallstars(starlist);
                    shooting(&m, joueur);
                    print(joueur);

                    /*if (collision(joueur, beastlist) == 0) {
                        print(joueur);
                    }*/
                    printtexte(joueur, texte);
                    gestioneenemy(beastlist, &indiceBeast);
                    al_flip_display();
                }
                else {
                    End(joueur);
                    al_flip_display();
                }
                break;

        }

    }
    al_destroy_event_queue(queue);
}

int main() {
    game();
    return 0;
}
