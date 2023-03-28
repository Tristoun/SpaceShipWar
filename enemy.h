//
// Created by trist on 15/03/2023.
//

#ifndef SPATIAL_ENEMY_H
#define SPATIAL_ENEMY_H

#define RYMAX 20
#define RXMAX 30
#define BEASTMAX 15

typedef struct {
    int x,y;
    int rax, ray;
    int state; //Etat pour le clignotant
}Beast;

void setstate(Beast beastlist[BEASTMAX]);
void gestioneenemy(Beast beastlist[BEASTMAX], int* indice);

#endif //SPATIAL_ENEMY_H
