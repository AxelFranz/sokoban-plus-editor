/**
 * @file main.c
 * Fichier permettant de tester et exécuter les fonctions
 * @author Axel FRANZ
 */
#include <stdio.h>
#include "player.h"
#include <stdbool.h>
#include "grid.h"
#include <stdlib.h>
#include "sdl2.h"

SDLContext context;

/**
 * @brief Fonction main qui lance le jeu
 */
int main(void){
	bool run = true;
	Grid a = init_level("level1.txt");
    sdl_init();

    while(run){
        display_sdl2(&a);
        SDL_RenderPresent(context.renderer); // On affiche tout
        SDL_Event ev;
        SDL_WaitEvent(&ev);
        switch (ev.type){
        case SDL_QUIT:
            sdl_quit();
            run=false;
          // on a appuyé sur le bouton "quitter" de la fenêtre
          break;
        case SDL_KEYUP:
          run=false;
          sdl_quit();
          // on a relaché une touche du clavier.
          break;
        }
    }

    sdl_quit();
	/* display(&a); */
	/*    while(run){ */
	/* 	char entry = fgetc(stdin); */
	/* 	switch(entry){ */
	/* 		case 'h':{ */
	/* 			move_player(&a,Left); */
	/* 			break; */
	/* 		} */
	/* 		case 'j':{ */
	/* 			move_player(&a,Bottom); */
	/* 			break; */
	/* 		} */
	/* 		case 'k':{ */
	/* 			move_player(&a,Top); */
	/* 			break; */
	/* 		} */
	/* 		case 'l':{ */
	/* 			move_player(&a,Right); */
	/* 			break; */
	/* 		} */
	/* 		case 'q' :{ */
	/* 			run = false; */
	/* 			break; */
	/* 		} */
	/*     } */
	/*        if(checkFinish(&a)){ */
	/*            fprintf(stdout,"\nBravo vous avez gagné !\n"); */
	/*            run=false; */
	/*        }  */
	/*    } */
	   freeGrid(&a);
    return 0;
}

