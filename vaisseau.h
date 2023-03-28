//
// Created by trist on 15/03/2023.
//
#include <allegro5/allegro.h>
#include "enemy.h"

#ifndef SPATIAL_VAISSEAU_H
#define SPATIAL_VAISSEAU_H

typedef struct {
    int x,y;
    int size;
    int speed, life, score;
    ALLEGRO_BITMAP* img;
}Ship;

void startship(Ship* joueur);
void print(Ship joueur);
int moveupdown(Ship joueur, int longueur, int sens);
int collision(Ship joueur, Beast beastlist[BEASTMAX]);

#endif //SPATIAL_VAISSEAU_H
