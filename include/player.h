/**
 * @file player.h
 * Header contentant les prototypes de fonction du joueur
 * @author Axel FRANZ
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

typedef struct Position{
    int x;
    int y;
}Position;

/**
 * @struct Player player.h
 * @brief Cette structure contient les informations 
 * concernant la position du joueur
 */
typedef struct Player{
    struct Position pos; ///< Position du joueur
}Player;

struct Grid;


enum Event{
    Quit,
    Left,
    Right,
    Top,
    Bottom,
    None
};


/**
 * @brief Fonction permettant de déplacer le joueur
 * @param a Pointeur vers la grille de jeu
 * @param d Direction du mouvement
 */
void move_player(struct Grid* g, enum Event d);

/**
 * @brief Fonction permettant de récuperer la position du joueur
 * @param a Structure de la grille de jeu
 * @param tab Pointeur vers tableau à 2 éléments vide qui comprendra les coordonnées
 */
Position getPlayerPos(struct Player a);

enum Event event();

#endif

