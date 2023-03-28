//
// Created by trist on 16/03/2023.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "vaisseau.h"

#ifndef SPATIAL_SHOT_H
#define SPATIAL_SHOT_H

typedef struct {
    int x, y;
    int speed;
    ALLEGRO_BITMAP* img;
    int size, state;
}Missile;

void setupshoot (Missile* m, Ship joueur);
void shooting(Missile* m, Ship joueur);



#endif //SPATIAL_SHOT_H
