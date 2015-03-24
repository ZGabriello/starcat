#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

typedef struct
{
    char nom[20];
    int x;
    int y;
} Bonus;

void Vie (Personnage * personnage);

void VieMax (Personnage * personnage);

#endif // BONUS_H_INCLUDED
