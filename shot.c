//
// Created by trist on 16/03/2023.
//
#include "shot.h"
#include "vaisseau.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>

#define START 0
#define SPEED 15
#define SIZE 25
#define LARGEUR 800

void setupshoot (Missile* m,Ship joueur ) {
    m->img = al_load_bitmap("/Users/trist/OneDrive/Documents/Cours ECE/CLionProjects/spatial/shot.png");
    assert (m->img != NULL);
    m->x = joueur.x+joueur.size/2;
    m->y = joueur.y + joueur.size/4;
    m->speed = SPEED;
    m->size = SIZE;
    m->state = 0;
}

void shooting(Missile* m, Ship joueur) {
    if (m->state == 1) {
        m->x += m->speed;
        if (m->x > LARGEUR) {
            m->x = joueur.x+joueur.size/2;
            m->y = joueur.y + joueur.size/4;
            m->state = 0;
        }
        else {
            al_draw_scaled_bitmap(m->img,
                                  0, 0,                                // source origin
                                  al_get_bitmap_width(m->img),     // source width
                                  al_get_bitmap_height(m->img),    // source height
                                  m->x, m->y,                                // target origin
                                  m->size, m->size,                                // target dimensions
                                  0                                    // flags
            );
        }

    }
}