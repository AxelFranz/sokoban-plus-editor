#include "player.h"
#include "grid.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
void fprintString(const char* file_name, const char* printed){
    FILE* fp = fopen(file_name,"w");
    if(fp == NULL){
        fprintf(stderr,"Cannot open file %s\n",file_name);
        exit(1);
    }
    fprintf(fp,printed);
    fclose(fp);
}

void fappendString(const char* file_name, const char* printed){
    FILE* fp = fopen(file_name,"a");
    if(fp == NULL){
        fprintf(stderr,"Cannot open file %s\n",file_name);
        exit(1);
    }
    fprintf(fp,printed);
    fclose(fp);
}

void fputChar(const char* file_name, const char c){
    FILE* fp = fopen(file_name,"w");
    if(fp == NULL){
        fprintf(stderr,"Cannot open file %s\n",file_name);
        exit(1);
    }
    fputc(c,fp);
    fclose(fp);
}

void fappendChar(const char* file_name, const char c){
    FILE* fp = fopen(file_name,"a");
    if(fp == NULL){
        fprintf(stderr,"Cannot open file %s\n",file_name);
        exit(1);
    }
    fputc(c,fp);
    fclose(fp);

}

void createGridFile(const char* file_name, Grid g){
    char new_path[256];
    snprintf(new_path,256,"levels/%s",file_name);
    char info[256];
    snprintf(info,sizeof(info),"%d %d %d\n",g.column_number,g.row_number,getGoalNumber(g)); 
    fprintString(new_path,info);
    Position pos;
    for(pos.y = 0; pos.y < g.row_number; pos.y++){
        for(pos.x =  0; pos.x < g.column_number; pos.x++){
            fappendChar(new_path,checkCase(g,pos));
        }
        fappendChar(new_path,'\n');
    }
}
