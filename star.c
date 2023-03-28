//
// Created by trist on 15/03/2023.
//

#include "star.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>

#define LARGEUR 800

void drawstars(int cx, int cy, int r) {
    al_draw_filled_circle(cx, cy, r, al_map_rgb(255,255,255));
    al_draw_filled_circle(cx-r ,cy-r, r, al_map_rgb(0,0,0));
    al_draw_filled_circle(cx+r ,cy-r, r, al_map_rgb(0,0,0));
    al_draw_filled_circle(cx-r ,cy+r, r, al_map_rgb(0,0,0));
    al_draw_filled_circle(cx+r ,cy+r, r,al_map_rgb(0,0,0));
}

void create_star(star starlist[NBSTAR],int longueur, int largeur, int r, int i) {
    int cx, cy;
    cx = rand()%largeur;
    cy = rand()%longueur;
    drawstars(cx, cy, r);
    starlist[i].x = cx;
    starlist[i].y = cy;
}

void xstar(star starlist[NBSTAR], int longueur, int largeur, int r) {
    for (int i =0; i<NBSTAR; i++) {
        create_star(starlist, longueur, largeur, r, i);
    }
}

void drawallstars(star starlist[NBSTAR]) {
    for (int i =0; i<NBSTAR; i++) {
        drawstars(starlist[i].x, starlist[i].y, STARSIZE);
    }
}

void moveallstars(star starlist[NBSTAR]) {
    for(int i=0; i<NBSTAR; i++) {
        starlist[i].x -= STARSPEED;
        if (starlist[i].x < 0) {
            starlist[i].x = LARGEUR;
        }
    }
}