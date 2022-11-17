/**
 * @file grid.c
 * Fichier contenant les différentes fonctions définies dans grid.h
 * @author Axel FRANZ
 */

#include "player.h"
#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void setCell(Grid* a,int i ,int j, char val){
    a->game_grid[i][j]=val;
}

Grid init_level(const char* file_path){
    // ouverture du fichier en mode lecture
    struct Grid a_r;
    FILE* file = fopen(file_path, "r");
    if(!file){
        fprintf(stderr, "Error %s not found", file_path);
        exit(-1);
    }
    char line[100] = {0};
    int number_column = 0; // nombre de colonne
    int number_row = 0; // nombre de ligne
    int number_goals = 0;
    //on lit la première ligne du fichier
    fgets(line, 100, file);
    sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
    int current_row = 0;
    a_r.row_number = number_row;
	a_r.column_number = number_column;
	a_r.goal_number = number_goals;
	a_r.game_grid =malloc((number_row)*sizeof(enum CaseType*));  
	if (a_r.game_grid == NULL) exit(1);
	
    for (int i = 0; i < number_row; i++){
        a_r.game_grid[i] =malloc((number_column)*sizeof(enum CaseType));
    	if (a_r.game_grid[i] == NULL) exit(1);
	}
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			setCell(&a_r,current_row,current_column,*buffer);
			if((*buffer)=='@'){
				a_r.player.x = current_column;
				a_r.player.y = current_row;
            }
            current_column += 1;			
			buffer += 1;			
		}	
		current_row += 1;
	}

	// fermeture du fichier
	fclose(file);
	return a_r;
}

void display(Grid* g){
	#ifdef _WIN32
		char clear[]="cls";
	#else
		char clear[]="clear";
	#endif
	system(clear);
	for(int i =0;i < g->row_number;i++){
		for(int j = 0; j < g->column_number;j++){
			fprintf(stdout,"%c",g->game_grid[i][j]);
		}
		fprintf(stdout,"\n");
	}
}
