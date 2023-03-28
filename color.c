//
// Created by trist on 07/02/2023.
//

#include <allegro5/allegro.h>
#include "color.h"

ALLEGRO_COLOR choose_color(char color) {
    switch (color) {
        case 'b' :
            return al_map_rgb(0,0,250);
        case 'g' :
            return al_map_rgb(128,128,128);
        case 'r' :
            return al_map_rgb(250, 0, 0);
        case 'w' :
            return al_map_rgb(255,255,255);
        case 'n' :
            return al_map_rgb(0,0,0);
    }
}