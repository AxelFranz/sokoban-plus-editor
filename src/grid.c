/**
 * @file grid.c
 * Fichier contenant les différentes fonctions définies dans grid.h
 * @author Axel FRANZ
 */

#include "player.h"
#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void setCell(Grid* g,int i ,int j, char val){
    g->game_grid[i][j]=val;
}

void setPosCell(Grid* g, Position pos, char val){
    setCell(g,pos.y,pos.x,val);
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
    int current_goal=0;
    a_r.row_number = number_row;
	a_r.column_number = number_column;
	a_r.goal_number = number_goals;

    a_r.goals=malloc(number_goals*sizeof(Position));
    if (a_r.goals==NULL) exit(1);

	a_r.game_grid =malloc((number_row)*sizeof(enum CaseType*));
	if (a_r.game_grid == NULL) exit(1);
	
    for (int i = 0; i < number_row; i++){
        a_r.game_grid[i] = malloc((number_column)*sizeof(enum CaseType));
    	if (a_r.game_grid[i] == NULL) exit(1);
	}
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			setCell(&a_r,current_row,current_column,*buffer);
			if((*buffer)==PLAYER){
                a_r.player.pos.x = current_column;
				a_r.player.pos.y = current_row;
            } else if ((*buffer)==GOAL){
                a_r.goals[current_goal].x = current_column;
                a_r.goals[current_goal].y = current_row;
                current_goal=1;
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

char checkCase(Grid g, Position pos){
    return g.game_grid[pos.y][pos.x];
}

int isNoWall(Grid* g, Position pos){
    return !(checkCase(*g,pos) == WALL || checkCase(*g,pos)== BOX);
} 

void switchCase(Grid* g, Position pos1, Position pos2){
    setPosCell(g,pos2,checkCase(*g,pos1));
    setPosCell(g,pos1,' ');
}

int checkFinish(Grid* g){
    int count = 0;
    for(int i = 0; i < g->goal_number; i++){
        if(checkCase(*g,g->goals[i])==BOX) count++;
    }
    return (count==g->goal_number);
}

void freeGrid(Grid* g){
   free(g->goals); 
   for(int i = 0; i < g->row_number;i++){
	       free(g->game_grid[i]);
   }
   free(g->game_grid);
}

void display(Grid* g){
	#ifdef _WIN32
		char clear[]="cls";
	#else
		char clear[]="clear";
	#endif
	system(clear);
    for(int i = 0; i < g->goal_number;i++){
        if(checkCase(*g,g->goals[i])==NONE){
            setPosCell(g,g->goals[i],GOAL);
        }
    }
    
	for(int i =0;i < g->row_number;i++){
		for(int j = 0; j < g->column_number;j++){
			fprintf(stdout,"%c",g->game_grid[i][j]);
		}
		fprintf(stdout,"\n");
	}
}

int getGoalNumber(Grid g){
    int count = 0;
    Position check;
    for(check.y = 0; check.y < g.row_number; check.y++){
        for(check.x = 0; check.x < g.column_number; check.x++){
            if(checkCase(g,check) == GOAL) count++;
        }
    }
    return count;
}

Grid initNewGrid(){
    Grid a_r;
    int number_row;
    int number_column;
    fprintf(stdout,"Nombre de lignes : ");
    scanf("%d",&number_row);
    fprintf(stdout,"Nombre de colonnes : ");
    scanf("%d",&number_column);

    if((0 >= number_row) || (0 >= number_column) ){
        fprintf(stderr,"Il faut que le nombre de lignes et de colonnes soit strictement positif\n");
        exit(1);
    }
    a_r.row_number = number_row;
	a_r.column_number = number_column;
	a_r.goal_number = 0;
    a_r.goals = NULL;
	a_r.game_grid = malloc((number_row)*sizeof(enum CaseType*));
	if (a_r.game_grid == NULL) exit(1);
	
    for (int i = 0; i < number_row; i++){
        a_r.game_grid[i] = malloc((number_column)*sizeof(enum CaseType));
    	if (a_r.game_grid[i] == NULL) exit(1);
        if(i == 0 || i == number_row-1){
            for(int j = 0; j < number_column; j++){
                Position p = {.x  = j, .y = i};
                setPosCell(&a_r,p,WALL);
            }
        } else {
            for(int j = 0; j < number_column;j++){
                Position p = {.x = j, .y = i};
                if(j == 0 || j == number_column-1){
                    setPosCell(&a_r,p,WALL);
                } else {
                    setPosCell(&a_r,p,NONE);
                }
            }
	    }
    }
    return a_r;
}
