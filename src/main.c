/**
 * @file main.c
 * Fichier permettant de tester et exécuter les fonctions
 * @author Axel FRANZ
 */
#include <stdio.h>
#include "grid.h"
#include <stdbool.h>

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
			case 'q' :{
				run = false;
				break;
			}
		}
	}
	return 0;
}

