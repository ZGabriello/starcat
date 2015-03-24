#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


typedef struct
{
    Terrain terrain;
    ListePersonnage listePersonnage;
    ListeMonstre listeMonstre;
    Bonus bonus;
} Jeu;

void InitialiserJeu (Jeu * pJeu);

void LibererJeu (Jeu * pJeu);


#endif // JEU_H_INCLUDED
