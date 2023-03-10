/** 
 * @file sdl2.c
 * Fichier contenant toutes les fonctions définies dans sdl2.h
 * @author Axel FRANZ
 */

#include "sdl2.h"
#include "player.h"
#include "grid.h"

const Color S_BLACK = {0,0,0};
const Color S_RED = {255,0,0};
const Color S_GREY = {126,126,126};
const Color S_GREEN = {0,255,0};
const Color S_ORANGE = {255,128,0};


void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
  if(!renderer){
      return;
  }
}

void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

void setBackgroundColor(Color c){
    SDL_SetRenderDrawColor(context.renderer,c.r,c.g,c.b,255);
    SDL_RenderClear(context.renderer);
}

void draw_rect(int x, int y, int dx, int dy, Color c){
    SDL_Rect rect = {
        .x = x,
        .y = y,
        .w = dx,
        .h = dy
    };
    SDL_SetRenderDrawColor(context.renderer,c.r,c.g,c.b,255);
    SDL_RenderFillRect(context.renderer, &rect);
}

void fillPos(int caseWidth, int caseHeight, Position p, Color c){
    int basex = p.x * caseWidth;
    int basey = p.y * caseHeight;
    draw_rect(basex,basey,caseWidth,caseHeight,c);
}

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

static int caseWidth;
static int caseHeight;

void display_sdl2(Grid* g){
    caseWidth = context.width/g->column_number;
    caseHeight = context.height/g->row_number;
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

void display_editor(Grid* g){
    caseWidth = context.width/g->column_number;
    caseHeight = context.height/g->row_number;
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
    SDL_RenderPresent(context.renderer);
}


enum Event event_sdl2(){
    SDL_Event ev;
    SDL_WaitEvent(&ev);
    switch(ev.type){
        case SDL_KEYDOWN:
            switch(ev.key.keysym.sym){
            case SDLK_h:
                return Left;
            case SDLK_j:
                return Bottom;
            case SDLK_k:
                return Top;
            case SDLK_l:
                return Right;
            case SDLK_q:
                return Quit;
            case SDLK_r:
                return Retry;
            default:
                return None;
            
            }
        case SDL_QUIT:
            return Quit;
        default:
            return None;
    }
}

/// Liste contenant tous les types présents dans une grille
char items[] = {NONE,WALL,BOX,PLAYER,GOAL};

void changeCase(Grid* a){
    int x,y;
    SDL_GetMouseState(&x,&y);
    Position clic = {x/caseWidth,y/caseHeight};
    int listIndex;
    for(int i = 0; i < 5; i++) if(items[i] == checkCase(*a,clic)) listIndex=(i+1)%5;
    setPosCell(a,clic,items[listIndex]);
}
