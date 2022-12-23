/**
 * @file grid.h
 * Header contentant les prototypes de fonction en lien avec la grille de jeu
 * @author Axel FRANZ
 */

#ifndef GRID_HEADER
#define GRID_HEADER

/// Enumération des types de cases possibles
enum CaseType{ 
	WALL = '#', ///< Mur
	BOX = '$', ///< Boîte
	PLAYER = '@', ///< Joueur
	GOAL = '.', ///< But
	NONE = ' ' ///< Vide
};

struct Player;

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
    int goal_number; ///< Nombre d'endroits où mettre les caisses
    Position* goals; ///< Tableau avec les positions des goals
    struct Player player; ///< Représentant le joueur sur la grille
}Grid;




/** 
 * @brief Initialisation de la grille de niveau
 * @param file_path Chemin d'accès du niveau à charger
 * @return Une copie de la structure de la grille
 */
Grid init_level(const char* file_path);

/** 
 * @brief Affichage d'une grille dans la sortie standard 
 * @param g Pointeur vers la grille à afficher
 */
void display(Grid* g);

char checkCase(Grid g, Position pos);

int isNoWall(Grid* g, Position pos);

void switchCase(Grid* g, Position pos1, Position pos2);

void freeGrid(Grid* g);

int checkFinish(Grid* g);

/**
 * @brief Modification d'une case de la grille
 * @param a Pointeur vers la grille
 * @param i Ligne
 * @param j Colonne
 * @param val Valeur à mettre
 */
void setCell(Grid* a,int i ,int j, char val);

#endif
