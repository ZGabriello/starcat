#include <stdio.h>
#include <stdlib.h>
#include "Bonus.h"
#include "Personnage.h"

void Vie (Personnage * personnage)
{
    personnage->vie++;
}

void VieMax (Personnage * personnage)
{
    while (personnage->vie < 3)
    {
        personnage->vie++;
    }
}
