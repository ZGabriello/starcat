#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Terrain.h"

typedef struct
{
    char nom[20];
    int vie;
    int x;
    int y;
} Personnage;

void ReduireVie (Personnage * personnage);

void AugmenterVie (Personnage * personnage);

void initialiserTerrain (Personnage * personnage);

void DeplacerGauche (Personnage * personnage, Terrain * terrain);

void DeplacerDroite (Personnage * personnage, Terrain * terrain);

void Sauter (Personnage * personnage, Terrain * terrain);

void Tirer (Personnage * personnage, Terrain * terrain);

void DetruirePersonnage (Personnage * personnage, Terrain * terrain);

#endif // PERSONNAGE_H_INCLUDED
