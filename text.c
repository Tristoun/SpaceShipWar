//
// Created by trist on 15/03/2023.
//
#include "text.h"
#include "vaisseau.h"
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SIZEFONT 20
#define FONTEND SIZEFONT*4
#define LARGEUR 800
#define LONGUEUR 500

ALLEGRO_FONT* setuptext() {
    ALLEGRO_FONT* texte = al_load_font("/Users/trist/OneDrive/Documents/Cours ECE/CLionProjects/spatial/Bangers/Bangers-Regular.ttf", SIZEFONT, 0);
    if (texte == NULL) {
        printf("text doesn't load");
    }
    return texte;
}

void printtexte (Ship joueur, ALLEGRO_FONT* texte) {
    char* contenu = "LIVES : ";
    char* contenu2 = "SCORE : ";
    char vie[2];
    char score[10];
    sprintf(vie, "%d", joueur.life);
    sprintf(score, "%d", joueur.score);
    al_draw_text(texte, al_map_rgb(255,255,0), LARGEUR/2,15,0, contenu);
    al_draw_text(texte, al_map_rgb(255,255,0), LARGEUR/2 + 50,15,0, vie);

    al_draw_text(texte, al_map_rgb(255,255,0), LARGEUR-5*SIZEFONT,15,0, contenu2);
    al_draw_text(texte, al_map_rgb(255,255,0), LARGEUR-4*SIZEFONT + 50,15,0, score);
}

int checkEnd (Ship joueur, ALLEGRO_FONT* texte) {
    if (joueur.life == 0) {
        return 1;
    }
    return 0;
}

void End(Ship joueur) {
    ALLEGRO_FONT* text = al_load_font("/Users/trist/OneDrive/Documents/Cours ECE/CLionProjects/spatial/Bangers/Bangers-Regular.ttf", FONTEND, 0);
    al_draw_text(text, al_map_rgb(255,255,0), LARGEUR/3,LONGUEUR/3,0, "GAME OVER");

}

