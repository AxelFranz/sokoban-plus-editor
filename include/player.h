/**
 * @file player.h
 * Header contentant les prototypes de fonction du joueur
 * @author Axel FRANZ
 */

#include "grid.h"

#ifndef PLAYER_HEADER
#define PLAYER_HEADER


/// Enumération des directions
enum Direction{
    Top, ///< Haut
    Left, ///< Gauche
    Right, ///< Droite
    Bottom ///< Bas
};


/**
 * @brief Fonction permettant de déplacer le joueur
 * @param a Pointeur vers la grille de jeu
 * @param d Direction du mouvement
 */
void move_player(Grid* a, enum Direction d);

/**
 * @brief Fonction permettant de récuperer la position du joueur
 * @param a Structure de la grille de jeu
 * @param tab Pointeur vers tableau à 2 éléments vide qui comprendra les coordonnées
 */
void getPlayerPos(Grid a, int* tab);

#endif

