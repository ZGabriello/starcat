#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "Terrain.h"
#include "Personnage.h"
#include "Monstre.h"
#include "Bonus.h"
#include "ListePersonnage.h"
#include "ListeMonstre.h"
typedef struct
{
    Terrain terrain;
    Personnage personnage;
    ListeMonstre listeMonstre;
    Monstre *tabMonstre;
    Bonus bonus;
} Jeu;

void InitialiserJeu (Jeu * pJeu);

void LibererJeu (Jeu * pJeu);

Terrain *jeuGetTerrainPtr(Jeu *);

Personnage *jeuGetPersonnagePtr(Jeu *);

const Terrain *jeuGetConstTerrainPtr(const Jeu *);

const Personnage *jeuGetConstPersonnagePtr(const Jeu *);


void jeuActionClavier(Jeu *j, const char);

void jeuEvolue(Jeu *pJeu);

#endif // JEU_H_INCLUDED
