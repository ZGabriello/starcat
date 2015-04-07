#include "Jeu.h"
#include "Personnage.h"
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

void jeuInit(Jeu *pJeu)
{
    int x, y, i_monstre;

    InitialiserPersonnage(&(pJeu->personnage));
	InitialiserTerrain(&(pJeu->terrain));

	pJeu->listeMonstre.nbMonstre = 5;
	pJeu->tabMonstre = malloc(pJeu->listeMonstre.nbMonstre*sizeof(Monstre));

	for (i_monstre=0; i_monstre<pJeu->listeMonstre.nbMonstre; i_monstre++)
    {
        do {
            x=0;
            {   x = rand()%pJeu->terrain.dimx;
                y = rand()%pJeu->terrain.dimy;
            }
        } while (!TestPositionValide(&(pJeu->terrain), x, y) && (x<4));

        pJeu->tabMonstre[i_monstre].x = x;
        pJeu->tabMonstre[i_monstre].y = y;

        pJeu->tabMonstre[i_monstre].direction = rand()%4;
    }
}

void jeuLibere(Jeu *pJeu)
{
	LibererTerrain(&(pJeu->terrain));
	free(pJeu->tabMonstre);
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->terrain);
}

Personnage *jeuGetPersonnagePtr(Jeu *pJeu)
{
	return &(pJeu->personnage);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->terrain);
}

const Personnage *jeuGetConstPersonnagePtr(const Jeu *pJeu)
{
	return &(pJeu->personnage);
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' :
				DeplacerGauchePersonnage(&(pJeu->personnage), &(pJeu->terrain));
				break;
		case 'd' :
				DeplacerDroitePersonnage(&(pJeu->personnage), &(pJeu->terrain));
				break;
	}
}

void jeuEvolue(Jeu *pJeu)
{
    int i_monstre, testx, testy;
    Monstre *p_monstre;
    int depx[] = {-1, 1, 0, 0};
    int depy[] = {0, 0, -1, 1};

    for (i_monstre=0; i_monstre<pJeu->listeMonstre.nbMonstre; i_monstre++)
    {
        p_monstre = &(pJeu->tabMonstre[i_monstre]);

        testx = p_monstre->x + depx[p_monstre->direction];
        testy = p_monstre->y + depy[p_monstre->direction];

        if (TestPositionValide(&(pJeu->terrain), testx, testy))
        {
            p_monstre->x = testx;
            p_monstre->y = testy;
        }
        else {
            /* Changement de direction */
            p_monstre->direction = rand()%4;
        }
    }
}
