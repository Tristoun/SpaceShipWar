//
// Created by trist on 15/03/2023.
//
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "vaisseau.h"
#include <stdio.h>


#define STARTY 0
#define SCORE 0
#define STARTX 10
#define LIFE 3
#define SIZE 50
#define SPEED 5
#define LARGEUR 800
#define LONGUEUR 500


void setup(Ship* joueur) {
    joueur->x = STARTX, joueur->y = STARTY;
    joueur->life = LIFE;
    joueur->score = SCORE;
    joueur->size = SIZE;
    joueur->speed = SPEED;
    ALLEGRO_BITMAP* img = al_load_bitmap("/Users/trist/OneDrive/Documents/Cours ECE/CLionProjects/spatial/v1.png");
    if (img == NULL) {
        printf("Image doesn't load\n");
    }
    joueur->img = img;
}

void print(Ship joueur) {
    al_draw_scaled_bitmap(joueur.img,
                          STARTX, STARTY,                               // source origin
                          al_get_bitmap_width(joueur.img),     // source width
                          al_get_bitmap_height(joueur.img),    // source height
                          joueur.x, joueur.y,                                // target origin
                          SIZE, SIZE,                                // target dimensions
                          0                                    // flags
    );

}

void startship(Ship* joueur) {
    setup(joueur);
    print(*joueur);
}

int moveupdown(Ship* joueur) {
    //Debug touche en diagonale
    if(joueur->x < STARTX) {
        joueur->x = STARTX;
        return 0;
    }
    if (joueur->x+SIZE > LARGEUR) {
        joueur->x = LARGEUR-SIZE;
        return 0;
    }
    if (joueur->y < STARTY) {
        joueur->y = STARTY;
        return 0;
    }
    if (joueur->y+SIZE > LONGUEUR) {
        joueur->y = LONGUEUR-SIZE;
        return 0;
    }
    return joueur->speed;
}

int collision(Ship joueur, Beast beastlist[BEASTMAX]) {
    int x1,x2,y1,y2;
    for (int i = 0; i < BEASTMAX; i++) {
        if (beastlist[i].state != -1) {

                printf("BOOM\n");
                return 1;
        }
    }
        return 0;
}

