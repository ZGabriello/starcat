#include <stdio.h>

 #define JEU_NCURSES
/* #define JEU_SDL */

#ifdef JEU_NCURSES
#include "Affichage.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#endif


int main ( int argc, char** argv )
{

#ifdef JEU_NCURSES
	Jeu jeu;
	jeuInit(&jeu);
	ncursBoucle(&jeu);
	jeuLibere(&jeu);
#endif


#ifdef JEU_SDL
	sdlJeu sj;
	sdljeuInit( &sj );
	sdljeuBoucle( &sj );
	sdljeuLibere( &sj );
#endif

	printf("Fin\n");
	return 0;
}
