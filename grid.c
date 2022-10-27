#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

struct Grid init_level(const char* file_path){
	// ouverture du fichier en mode lecture
	struct Grid a_r;
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	int current_row = 0;
	int current_goal = 0;
	a_r.row_number = number_row;
	a_r.column_number = number_column;
	a_r.game_grid =malloc((number_row)*sizeof(char*));  
	for (int i = 0; i < number_row; i++)
        a_r.game_grid[i] =malloc((number_column)* sizeof(char));
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			a_r.game_grid[current_row][current_column]=line[current_column];
			current_column += 1;			
			buffer += 1;			
		}	
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
	return a_r;
}
 

