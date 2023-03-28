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

int moveupdown(Ship joueur, int longueur, int sens) {
    //Debug touche en diagonale
    if (sens == 1 && joueur.y-SPEED<0) {
        return 0;
    }
    if (sens == 2 && joueur.y+joueur.size+joueur.speed>longueur) {
        return 0;
    }
    if (sens == 3 && joueur.x+joueur.size+joueur.speed>800) {
        return 0;
    }
    if (sens == 4 && joueur.x-joueur.speed<0) {
        return 0;
    }
    return joueur.speed;
}

int collision(Ship joueur, Beast beastlist[BEASTMAX]) {
    for (int i = 0; i < BEASTMAX; i++) {
        if (beastlist[i].state != -1) {
            if(beastlist[i].x-beastlist->rax <= joueur.x+joueur.size && beastlist[i].y <= joueur.y+joueur.size && beastlist[i].y >= joueur.y-joueur.size) {
                printf("BOOM\n");
                return 1;
            }
        }
        return 0;
    }
}
