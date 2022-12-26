#pragma once
#include <SDL2/SDL.h>
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

typedef struct color{
    int r;
    int g;
    int b;
} Color;


// Défintion de quelques couleurs
extern const Color S_BLACK;
extern const Color S_RED;
extern const Color S_GREY;
extern const Color S_GREEN; 
extern const Color S_ORANGE;

struct Position;
struct Grid;
extern SDLContext context;
enum Event;

/* @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
void sdl_init();
/**
 * nettoie la variable global context 
 */
void sdl_quit();


void draw_rect(int x,int y,int dx, int dy, Color c);

void setBackgroundColor(Color c);

void fillPos(int caseHeight, int caseWidth, struct Position p, Color c);

void display_sdl2(struct Grid* g);

enum Event event_sdl2();


