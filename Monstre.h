#ifndef _MONSTRE_H
#define _MONSTRE_H

#include "Terrain.h"

typedef struct
{
    char nom[20];
    int vie;
	int x;
	int y;
	enum {Droite,Gauche} direction;
} Monstre;

void InitialiserMonstre(Monstre *monstre);

void DeplacerGaucheMonstre(Monstre *monstre, const Terrain *terrain);

void DeplacerDroiteMonstre(Monstre *monstre, const Terrain *terrain);

void TirerMonstre(Monstre *monstre, const Terrain *terrain);

void ReduireVieMosntre(Monstre *monstre);

#endif
