//
// Created by trist on 15/03/2023.
//

#ifndef SPATIAL_STAR_H
#define SPATIAL_STAR_H

#define STARSIZE 2
#define NBSTAR 150
#define STARSPEED 3

typedef struct {
    int x,y;
}star;

void create_star(star starlist[NBSTAR], int longueur, int largeur, int r, int i);
void xstar(star starlist[NBSTAR], int longueur, int largeur, int r);
void drawallstars(star starlist[NBSTAR]);
void moveallstars(star starlist[NBSTAR]);


#endif //SPATIAL_STAR_H
