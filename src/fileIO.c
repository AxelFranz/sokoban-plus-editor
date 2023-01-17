#include "player.h"
#include "grid.h"
#include "fileIO.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
void fprintString(const char* file_name, const char* printed){
    FILE* fp = fopen(file_name,"w");
    if(fp == NULL){
        fprintf(stderr,"fprintString : Cannot open file %s\n",file_name);
        exit(1);
    }
    fprintf(fp,printed);
    fclose(fp);
}


void fappendString(const char* file_name, const char* printed){
    FILE* fp = fopen(file_name,"a");
    if(fp == NULL){
        fprintf(stderr,"fappendString : Cannot open file %s\n",file_name);
        exit(1);
    }
    fprintf(fp,printed);
    fclose(fp);
}

void fputChar(const char* file_name, const char c){
    FILE* fp = fopen(file_name,"w");
    if(fp == NULL){
        fprintf(stderr,"fputChar : Cannot open file %s\n",file_name);
        exit(1);
    }
    fputc(c,fp);
    fclose(fp);
}

void fappendChar(const char* file_name, const char c){
    FILE* fp = fopen(file_name,"a");
    if(fp == NULL){
        fprintf(stderr,"fappendChar : Cannot open file %s\n",file_name);
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

void listFolder(const char* dirname,char** names, int* size_names){
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);
    if(!d){
        fprintf(stderr,"listFolder : Cannot open folder %s",dirname);
        exit(1);
    }
    dir=readdir(d); *(size_names) = 0;
    while (dir != NULL){
        if(strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name,"..") == 0){
        } else {
            strcpy(names[*(size_names)],dir->d_name);
            (*size_names)++;
        }
        dir=readdir(d);
    }
    closedir(d);
}

void printFolder(const char* dirname){
    char** names = malloc(256*sizeof(char*));
    if(!names){
        fprintf(stderr,"Malloc error : PrintFolder\n");
        exit(1);
    }
    for(int i = 0; i < 256; i++){
        names[i] = malloc(256*sizeof(char));
        if(!names[i]){
            fprintf(stderr,"Malloc error : PrintFolder\n");
            exit(1);
        }
    }
    int size_names;
    listFolder(dirname,names,&size_names);
    for(int i = 0; i < size_names;i++){
        fprintf(stdout,"%d : %s\n",i,names[i]);
    }
    for(int i = 0; i < size_names; i++){
        free(names[i]);
    }
    free(names);
}
