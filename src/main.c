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
#include "fileIO.h"
#include "editmode.h"

SDLContext context;

/**
 * @brief Fonction main qui lance le jeu
 */
int main(int argc, char** argv){
    bool isSDL = argc == 1 ||(argc == 2 && strcmp(argv[1],"--sdl2") == 0);
    bool isEditor = argc == 2 && strcmp(argv[1],"--editor") == 0;
    bool isConsole = argc == 2 && strcmp(argv[1],"--console") == 0;

    enum Event(*handle_event)();
    void (*handle_display)(Grid*);

    // On check les arguments
    if(isSDL){
        sdl_init();
        handle_event = event_sdl2;
        handle_display = display_sdl2;
    } else if(isConsole){
        handle_event = event;
        handle_display = display;
    } else if(isEditor){
        sdl_init();
        handle_event = event_editor;
        handle_display = display_editor;
    } else {
        fprintf(stderr,"Usage : ./main [--console] OR [--sdl2] OR [--editor]\n"
                "Sans argument : Lance en mode SDL2\n");
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
            case Click:{
                changeCase(&a);
                handle_display(&a);
                break;
            }
            case Save:{
                fprintf(stdout,"File name: ");
                char file_name[256];
                fgets(file_name,256,stdin);
                file_name[strcspn(file_name, "\n")] = 0;
                createGridFile(file_name,a);
                run=false;
                break;
            }
            default:
                move_player(&a,entry);
                break;
        }
	    if(checkFinish(&a)){
            handle_display(&a);
	        fprintf(stdout,"Bravo vous avez gagné !\n");
	        run=false;
	    }
    }
    if(isSDL) sdl_quit();
	freeGrid(&a);
    return 0;
}

