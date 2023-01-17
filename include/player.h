/**
 * @file player.h
 * Header contentant les prototypes de fonction du joueur
 * @author Axel FRANZ
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

/** Position player.h
 * @brief Une position composée d'un x et d'un y
 */
typedef struct Position{
    int x; ///< La position x
    int y; ///< La position y
}Position;

/**
 * @struct Player player.h
 * @brief Cette structure contient les informations 
 * concernant la position du joueur
 */
typedef struct Player{
    struct Position pos; ///< Position du joueur
}Player;

// Pour les dépendances
struct Grid;

/// Enumération des évènements possibles
enum Event{
    Quit, ///< Quitter le jeu
    Left, ///< Aller à gauche
    Right, ///< Aller à droite
    Top, ///< Aller en haut
    Bottom, ///< Aller en base
    None, ///< Ne rien faire
    Click, //< Clic souris
    Save, //< sauvegarde de la grille
    Retry, ///< Retry du niveau
};


/**
 * @brief Fonction permettant de déplacer le joueur
 * @param g Pointeur vers la grille de jeu
 * @param d Direction du mouvement
 */
void move_player(struct Grid* g, enum Event d);

/**
 * @brief Fonction permettant de récuperer la position du joueur
 * @param a Structure de la grille de jeu
 * @return La position du joueur
 */
Position getPlayerPos(struct Player a);

/**
 * @brief Renvoie la position potentielle après déplacement
 * @param pos La position de base
 * @param d La direction
 * @return La position après déplacement
 */
Position posDir(Position pos, enum Event d);

/**
 * @brief Renvoie l'évènement reçu pendant l'execution du programme
 * @return L'évènement reçu
 */
enum Event event();

#endif

