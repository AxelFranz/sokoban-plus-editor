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

void display_sdl2(Grid* g){
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
                default:
                    fillPos(caseWidth,caseHeight,check,S_GREY);
                    break;
            } 
        }
    }
}
