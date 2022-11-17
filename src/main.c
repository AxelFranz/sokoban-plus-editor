/**
 * @file main.c
 * Fichier permettant de tester et exécuter les fonctions
 * @author Axel FRANZ
 */
#include <stdio.h>
#include "player.h"
#include "grid.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Fonction main qui lance le jeu
 */
int main(void){
	bool run = true;
	Grid a = init_level("level1.txt");
	display(&a);
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'h':{
				move_player(&a,Left);
				break;
			}
			case 'j':{
				move_player(&a,Bottom);
				break;
			}
			case 'k':{
				move_player(&a,Top);
				break;
			}
			case 'l':{
				move_player(&a,Right);
				break;
			}
			case 'q' :{
				run = false;
				break;
			}
		}
	}

    for(int i = 0; i < a.row_number;i++){
        free(a.game_grid[i]);
    }
    free(a.game_grid);
	return 0;
}

