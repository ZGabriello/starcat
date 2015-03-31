#include "Monstre.h"
#include "Terrain.h"

void InitialiserMonstre(Monstre * monstre)
{
    monstre->vie=3;//les monstres ont trois vies, il faudra savoir où placer les monstres dans le jeu pour pouvoir initialiser sa position
}


void ReduireVieMonstre (Monstre * monstre)
{
  monstre->vie--;
}
void DeplacerGaucheMonstre(Monstre *monstre, const Terrain *pTer)
{
	if (TestPositionValide( pTer, monstre->x-1, monstre->y)) //on teste si on n'est pas à la limite du terrain
		monstre->x--;
}

void DeplacerDroiteMonstre(Monstre *monstre, const Terrain *pTer)
{
	if (TestPositionValide( pTer, monstre->x+1, monstre->y))//on teste si on n'est pas à la limite du terrain
		monstre->x++;
}
