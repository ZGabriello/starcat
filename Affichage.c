#include <stdio.h>
#include "Affichage.h"


#ifdef WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include <assert.h>
#include <time.h>
#include "Jeu.h"

void ncursAff( WINDOW* win, const Jeu *pJeu)
{
	int x,y;
//Pour monstre
//	int i_fant;

	const Terrain *pTer = jeuGetConstTerrainPtr(pJeu);
	const Personnage *personnage = jeuGetConstPersonnagePtr(pJeu);

	wclear(win);

	for(x=0;x<GetDimX(pTer);++x)
		for(y=0;y<GetDimY(pTer);++y)
			mvwprintw( win, y, x, "%c", GetTerrainXY(pTer,x,y) );
// Pour l'affichage des monstre
 /*   for (i_fant=0; i_fant<pJeu->nb_fantomes; i_fant++)
        mvwprintw( win, pJeu->tab_fantomes[i_fant].y, pJeu->tab_fantomes[i_fant].x, "F");
*/
	mvwprintw( win, PersonnageGetY(personnage), PersonnageGetX(personnage), "*");

	wmove( win, PersonnageGetY(personnage), PersonnageGetX(personnage));
}


void ncursBoucle(Jeu *pJeu)
{
	WINDOW *win;
	int c;
	int continue_boucle;

	 /* Horloges (en secondes) */
    float horloge_courante, horloge_precedente;

    /* Intervalle de temps (en secondes) entre deux évolutions du jeu */
    /* Changer la valeur pour ralentir ou accélérer le déplacement des fantomes */
    float intervalle_horloge = 0.1f;

	initscr();		/* passe l'écran texte en mode NCurses */
	clear();		/* efface l'écran */
	noecho();  	/* Lorsqu'une touche est préssée au clavier, elle n'apparait pasa à l'écran */
	cbreak();		/* un caractère est directement affiché, il ne passe pas dans un buffer */

	/* Creation d'une nouvelle fenetre en mode texte */
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY) */
	win = newwin( GetDimY(jeuGetConstTerrainPtr(pJeu)), GetDimX(jeuGetConstTerrainPtr(pJeu)), 10, 5 );
	keypad(win, TRUE);		/* pour que les flèches soient traitées (il faut le faire après création de la fenêtre) */

	/* notimeout(win,true); */
	/* wtimeout( win, 500 ); */
	nodelay(win,true); /* Pour que l'appel à wgetch soit non-bloquant */

	continue_boucle = 1;

	/* Récupère l'horloge actuelle et la convertit en secondes */
    /* clock() retourne le nombre de tops horloge depuis le lancement du programme */
    horloge_precedente = (float)clock()/(float)CLOCKS_PER_SEC;

    ncursAff( win, pJeu);

	do
	{
        /* Récupère l'horloge actuelle et la convertit en secondes */
        /* clock() retourne le nombre de tops horloge depuis le lancement du programme */
        horloge_courante = (float)clock()/(float)CLOCKS_PER_SEC;

        if (horloge_courante-horloge_precedente>=intervalle_horloge)
        {
                jeuEvolue(pJeu);
                ncursAff( win, pJeu);
                horloge_precedente = horloge_courante;
        }

		c = wgetch(win);

		switch(c)
		{
			case KEY_LEFT:
				jeuActionClavier( pJeu, 'g');
				ncursAff( win, pJeu);
				break;
			case KEY_RIGHT:
				jeuActionClavier( pJeu, 'd');
				ncursAff( win, pJeu);
				break;
			case KEY_UP:
				jeuActionClavier( pJeu, 'h');
				ncursAff( win, pJeu);
				break;
			case KEY_DOWN:
				jeuActionClavier( pJeu, 'b');
				ncursAff( win, pJeu);
				break;
			case 27: /* ECHAP */
				continue_boucle = 0;
				break;
		}
	} while (continue_boucle==1);

    assert(delwin(win)!=ERR);

	endwin();
}
