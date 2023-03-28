//
// Created by trist on 15/03/2023.
//

#include "enemy.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>

#define PROBA 1000
#define YESCREATE 15
#define LARGEUR 800
#define LONGUEUR 500
#define SPEEDBEAST 5

void setstate(Beast beastlist[BEASTMAX]) {
    for(int i=0; i<BEASTMAX; i++) {
        beastlist[i].state = -1;
    }
}

void createennemy (Beast beastlist[BEASTMAX], int* indice) {
    if (*indice == BEASTMAX-1 && beastlist[0].state == -1) {
        *indice = 0;
    }
    int nb;
    nb = rand()%PROBA;
    if (nb<=YESCREATE) {
        beastlist[*indice].x = LARGEUR;
        beastlist[*indice].y = rand()%LONGUEUR;
        beastlist[*indice].rax = rand()%RXMAX;
        beastlist[*indice].ray = rand()%RYMAX;
        beastlist[*indice].state = 1;
        *indice +=1;

    }
}

void moveennemy(Beast beastlist[BEASTMAX]) {

    for(int i=0; i<BEASTMAX; i++) {
        if(beastlist[i].state!=-1) {
            beastlist[i].x -= SPEEDBEAST;
        }
        if (beastlist[i].x <=0) {
            beastlist[i].state = -1;
        }
    }
}

void drawennemy (Beast ennemy) {
    int r1, r2, r3;
    r1 = rand()%255;
    r2 = rand()%255;
    r3 = rand()%255;
    al_draw_filled_ellipse(ennemy.x, ennemy.y, ennemy.rax, ennemy.ray, al_map_rgb(r1,r2, r3));
}

void drawallennemy (Beast beastlist[BEASTMAX]) {
    for(int i=0; i<BEASTMAX; i++) {
        if (beastlist[i].state != -1) {
            drawennemy(beastlist[i]);
        }
    }
}

void gestioneenemy(Beast beastlist[BEASTMAX], int* indice) {
    createennemy(beastlist, indice);
    moveennemy(beastlist);
    drawallennemy(beastlist);

}