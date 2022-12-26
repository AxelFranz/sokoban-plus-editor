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
    enum Event (*handle_event)() = event;
    /* sdl_init(); */

    while(run){
        display(&a);
        enum Event entry = (*handle_event)();
        switch(entry){ 
			case Quit:{
				run = false;
                break;
			}
			case None:{
				break;
			}
            default:
                move_player(&a,entry);
                break;
        }
	    if(checkFinish(&a)){
            display(&a);
	        fprintf(stdout,"Bravo vous avez gagné !\n");
	        run=false;
	    }
    }

    /* sdl_quit(); */
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

