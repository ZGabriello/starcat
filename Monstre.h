#ifndef _MONSTRE_H
#define _MONSTRE_H

typedef struct
{
        char nom[20];
        int vie;
	int x;
	int y;
} Monstre;

void InitialiserMonstre(monstre *);

void DeplacerGaucheMonstre(monstre *, const terrain *);

void DeplacerDroiteMonstre(monstre *, const terrain *);

void Tirer(monstre *, const terrain *);

void ReduireVie(monstre *);

#endif
