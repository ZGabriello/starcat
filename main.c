#include <stdio.h>
#include <stdlib.h>

#include "Jeu.h"
#include "Affichage"


int main ()
{
    printf("coucou");
    Jeu jeu;
    initialiserJeu(&jeu);
/*boucle du affichage */
    LibererJeu(&jeu);
    return 0;
}

