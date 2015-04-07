#include "Personnage.h"
#include "Terrain.h"

void InitialiserPersonnage(Personnage *personnage)
{
    personnage->vie=3;
    personnage->x=1;
    personnage->y=7;
}

void ReduireViePersonnage (Personnage * personnage)
{
    personnage->vie--;
}

void AugmenterVie (Personnage * personnage)
{
    personnage->vie++;
}

void DeplacerGauchePersonnage (Personnage * personnage, const Terrain * terrain)
{
    if(TestPositionValide(terrain, personnage->x-1, personnage->y))//on teste si on n'est pas à la limite du terrain
        personnage->x--;
}

void DeplacerDroitePersonnage (Personnage * personnage, const Terrain * terrain)
{
     if(TestPositionValide(terrain, personnage->x+1, personnage->y))//on teste si on n'est pas à la limite du terrain
        personnage->x++;
}

int PersonnageGetX (const Personnage * personnage)
{
    return personnage->x;
}

int PersonnageGetY (const Personnage * personnage)
{
    return personnage->y;
}

int PersonnageGetVie ( const Personnage * personnage)
{
    return personnage->vie;
}

void TirerPersonnage(Personnage * personnage,Terrain * terrain)
{

}
