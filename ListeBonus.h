#ifndef LISTEBONUS_H_INCLUDED
#define LISTEBONUS_H_INCLUDED

#include "Bonus.h"

typedef struct
{
    Bonus * listeBonus;
    int nbBonus;
} ListeBonus;

void SupprimerBonus (Bonus bonus, ListeBonus * listeBonus);

#endif // LISTEBONUS_H_INCLUDED
