#include "player.h"
#include "grid.h"
#include "stdlib.h"
#include "sdl2.h"
#include "stdio.h"
#include "editmode.h"


enum Event event_editor(){
    SDL_Event ev;
    SDL_WaitEvent(&ev);
    switch(ev.type){
        case SDL_MOUSEBUTTONDOWN:
            return Click;
        case SDL_KEYDOWN:
            switch(ev.key.keysym.sym){
            case SDLK_w:
                return Save;
            case SDLK_q:
                return Quit;
            default:
                return None;
            }
        case SDL_QUIT:
            return Quit;
        default:
            return None;
    }
}

void display_editor(Grid* g){
    int caseWidth = context.width/g->column_number;
    int caseHeight = context.height/g->row_number;
    for(int i = 0; i < g->row_number; i++){
        for(int j = 0; j < g->column_number; j++){
            Position check = {.x = j, .y = i };
            switch(checkCase(*g,check)){
                case '#':
                    fillPos(caseWidth,caseHeight,check,S_BLACK);
                    break;
                case '$':
                    fillPos(caseWidth,caseHeight,check,S_ORANGE);
                    break;
                case '.':
                    fillPos(caseWidth,caseHeight,check,S_GREEN);
                    break;
                case '@':
                    fillPos(caseWidth,caseHeight,check,S_RED);
                    break;
                case ' ':
                    fillPos(caseWidth,caseHeight,check,S_GREY);
                    break;
            } 
        }
    }
    for(int i = 0; i < g->goal_number;i++){
        if(checkCase(*g,g->goals[i])==' '){
            fillPos(caseWidth,caseHeight,g->goals[i],S_GREEN);
        }
    }
    
    SDL_RenderPresent(context.renderer);
}
