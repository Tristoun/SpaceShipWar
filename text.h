//
// Created by trist on 15/03/2023.
//
#include "vaisseau.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#ifndef SPATIAL_TEXT_H
#define SPATIAL_TEXT_H

void printtexte(Ship joueur,ALLEGRO_FONT* texte);
ALLEGRO_FONT* setuptext();
int checkEnd (Ship joueur, ALLEGRO_FONT* texte);
void End(Ship joueur);


#endif //SPATIAL_TEXT_H
