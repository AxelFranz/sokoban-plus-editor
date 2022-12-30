/**
 * @file main.c
 * Fichier permettant de tester et exécuter les fonctions
 * @author Axel FRANZ
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "player.h"
#include "grid.h"
#include "sdl2.h"

SDLContext context;

/**
 * @brief Fonction main qui lance le jeu
 */
int main(int argc, char** argv){
    bool isSDL = argc == 2 && strcmp(argv[1],"--sdl2") == 0;

    enum Event(*handle_event)();
    void (*handle_display)(Grid*);

    // On check les arguments
    if(isSDL){
        sdl_init();
        handle_event = event_sdl2;
        handle_display = display_sdl2;
    } else if(argc == 1 || (argc == 2 && strcmp(argv[1],"--console") == 0)){
        handle_event = event;
        handle_display = display;
    } else {
        fprintf(stderr,"Usage : ./main [--console] OR [--sdl2]\n"
                "Sans argument : Lance en mode console\n");
        return -1;
    }
    bool run = true;
	Grid a = init_level("level1.txt");

    while(run){
        handle_display(&a);
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
            handle_display(&a);
            if(isSDL) sdl_quit();
	        fprintf(stdout,"Bravo vous avez gagné !\n");
	        run=false;
	    }
    }
	freeGrid(&a);
    return 0;
}

