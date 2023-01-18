/**
 * @file sdl2.h
 * Fichier contenant les prototypes de fonction en rapport avec sdl
 * @author Axel FRANZ
 */

#pragma once
#include <SDL2/SDL.h>

/**
 * @struct SDLContext sdl2.h
 * @brief Contient toutes les informations nécessaires pour SDL2
 */
typedef struct SDLContext {
  SDL_Window *window; ///< La fenêtre SDL2
  SDL_Renderer *renderer; ///< Moteur de rendu de la fenêtre
  int width; ///< La longueur de la fenêtre
  int height; ///< La largeur/hauteur de la fenêtre
} SDLContext;

/**
 * @struct Color sdl2.h
 * @brief Contient les informations d'une couleur sous forme RGB
 */
typedef struct Color{
    int r; ///< Taux de rouge entre 0 et 255
    int g; ///< Taux de vert entre 0 et 255
    int b; ///< Taux de bleu entre 0 et 255
} Color;


// Défintion de quelques couleurs
extern const Color S_BLACK; ///< Constante noir
extern const Color S_RED; ///< Constante rouge
extern const Color S_GREY; ///< Constante gris
extern const Color S_GREEN; ///< Constante verte
extern const Color S_ORANGE; ///< Constante orange

// Pour les dépendances
struct Position;
struct Grid;
extern SDLContext context; ///< Le contexte utilisé dans tout le programme
enum Event;

/**
 * @brief Initialise une variable global `context` de type SDLContext
 */
void sdl_init();

/**
 * @brief nettoie la variable global context 
 */
void sdl_quit();

/**
 * @brief Dessine un rectangle de couleur c
 * @param x La position x du début du rectangle
 * @param y La position y du début du rectangle
 * @param dx La longueur du rectangle
 * @param dy La largeur du rectangle
 * @param c La couleur du rectangle
 */
void draw_rect(int x,int y,int dx, int dy, Color c);

/**
 * @brief Mets le fond de la couleur c (fonction utilisée pour d'anciens tests)
 * @param c La couleur du fond
 */
 void setBackgroundColor(Color c);

/**
 * @brief En donnant la largeur et longueur d'une case, remplis la position p de la couleur c
 * @param caseWidth La longueur d'une case
 * @param caseHeight La hauteur d'une case
 * @param p La position à remplir
 * @param c La couleur à appliquer
 */
void fillPos(int caseWidth, int caseHeight, struct Position p, Color c);

/**
 * @brief Permet d'afficher la grille g
 * @param g Un pointeur vers la grille
 */
void display_sdl2(struct Grid* g);

/**
 * @brief Permet de renvoyer l'évènement reçu lors de l'execution
 * @return L'évènement reçu
 */
enum Event event_sdl2();

/**
 * @brief Permet de changer la case cliquée (en mode éditeur)
 * @param a Pointeur vers la grille à modifier
 */
void changeCase(struct Grid* a);

/**
 * @brief Handler d'évènements en mode editeur (sauvegarder/changer la case)
 * @return L'event en input
 */
enum Event event_editor();

/**
 * @brief Permet d'afficher la grille en mode editeur (changement mineur par rapport au SDL2 normal)
 * @param g Pointeur vers la grille à afficher
 */
void display_editor(struct Grid* g);
