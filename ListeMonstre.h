#ifndef _LISTEMONSTRE_H
#define _LISTEMONSTRE_H

#include "Monstre.h"

typedef struct
{
      Monstre * monstre;
      int nbMonstre;
} ListeMonstre;

void AjouterMonstre(Monstre * monstre, ListeMonstre *listeMonstre);

void SupprimerMonstre(Monstre * monstre, ListeMonstre *listeMonstre);

#endif
