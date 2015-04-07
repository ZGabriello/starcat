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

void ReduireViePersonnage (Personnage * personnage);

void AugmenterVie (Personnage * personnage);

void InitialiserPersonnage (Personnage * personnage);

void DeplacerGauchePersonnage (Personnage * personnage, const Terrain * terrain);

void DeplacerDroitePersonnage (Personnage * personnage, const Terrain * terrain);

void Sauter (Personnage * personnage, Terrain * terrain);

void TirerPersonnage (Personnage * personnage, Terrain * terrain);

void DetruirePersonnage (Personnage * personnage, Terrain * terrain);

int PersonnageGetX (const Personnage * personnage);

int PersonnageGetY (const Personnage * personnage);

int PersonnageGetVie ( const Personnage * personnage);

#endif // PERSONNAGE_H_INCLUDED
