/**
 * @file player.c
 * Fichier contenant les différentes fonctions définies dans player.h
 * @author Axel FRANZ
 */

#include "player.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
void getPlayerPos(Grid a,int* tab){
    tab[0]=a.player.x;
    tab[1]=a.player.y;
}

void move_player(Grid* a, enum Direction d){
	int playerCoord[2];
	getPlayerPos(*a,playerCoord);
	if(d == Right){
		if(a->game_grid[playerCoord[1]][playerCoord[0]+1] == ' '){
			setCell(a,playerCoord[1],playerCoord[0]+1, '@');
			setCell(a,playerCoord[1],playerCoord[0], ' ');
			a->player.x=playerCoord[0]+1;
		}
	}
	if(d == Left){
		if(a->game_grid[playerCoord[1]][playerCoord[0]-1] == ' '){
			setCell(a,playerCoord[1],playerCoord[0]-1, '@');
			setCell(a,playerCoord[1],playerCoord[0], ' ');
			a->player.x=playerCoord[0]-1;
		}
	}
	if(d == Bottom){
		if(a->game_grid[playerCoord[1]+1][playerCoord[0]] == ' '){
			setCell(a,playerCoord[1]+1,playerCoord[0], '@');
			setCell(a,playerCoord[1],playerCoord[0], ' ');
			a->player.y=playerCoord[1]+1;
		}
	}
	if(d == Top){
		if(a->game_grid[playerCoord[1]-1][playerCoord[0]] == ' '){
			setCell(a,playerCoord[1]-1,playerCoord[0], '@');
			setCell(a,playerCoord[1],playerCoord[0], ' ');
			a->player.y=playerCoord[1]-1;
		}
	}

	display(a);
}