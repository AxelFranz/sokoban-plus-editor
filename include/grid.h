/**
 * @file grid.h
 * Header contentant les prototypes de fonction du projet
 * @author Axel FRANZ
 */

#ifndef GRID_HEADER
#define GRID_HEADER
enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
    int goal_number; ///< Nombre d'endrokts où mettre les caisses
}Grid;


/** 
 * @brief Initialisation de la grille de niveau
 * @param file_path Chemin d'accès du niveau à charger
 * @return Une copie de la structure de la grille
 */
Grid init_level(const char* file_path);

/** 
 * @brief Affichage d'une grille dans la sortie standard 
 * @param g Pointeur vers la structure à afficher
 */
void display(Grid* g);

#endif
