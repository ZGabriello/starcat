#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Terrain.h"
#include "ListePersonnage.h"
#include "ListeMonstre.h"
#include "ListeBonus.h"

typedef struct
{
    Terrain terrain;
    ListePersonnage listePersonnage;
    ListeMonstre listeMonstre;
    ListeBonus bonus;
} Jeu;

void InitialiserJeu (Jeu * pJeu);

void LibererJeu (Jeu * pJeu);


#endif // JEU_H_INCLUDED
