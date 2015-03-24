#ifndef LISTEPERSONNAGE_H_INCLUDED
#define LISTEPERSONNAGE_H_INCLUDED


typedef struct
{
    Personnage * listePersonnage;
    int nbPersonnage;
} ListePersonnage;

void ajouterPersonnage (Personnage personnage, ListePersonnage * listePersonnage );

void SupprimerPersonnage (Personnage personnage, ListePersonnage * listePersonnage);


#endif // LISTEPERSONNAGE_H_INCLUDED
