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

// Pour les dépendances
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

/**
 * @brief Renvoie le caractère présent sur une case
 * @param g Une copie de la grille de jeu
 * @param pos La position à tester
 * @return Le caractère présent à la position
 */
char checkCase(Grid g, Position pos);

/**
 * @brief Teste si une position est un mur ou non
 * @param g Un pointeur vers la grille (car dans son contexte d'utilisation, les pointeurs ne surchargent pas la fonction)
 * @param pos La position à tester
 * @return 1 si ce n'est pas un mur et 0 sinon
 */
int isNoWall(Grid* g, Position pos);

/**
 * @brief Permet d'inverser 2 cases
 * @param g Un pointeur vers la grille
 * @param pos1 La première position à inverser
 * @param pos2 La deuxième position
 */
void switchCase(Grid* g, Position pos1, Position pos2);

/**
 * @brief Désalloue les différents structures allouées dynamiquement
 * @param g Un pointeur vers la grille à désallouer 
 */
void freeGrid(Grid* g);

/**
 * @brief Vérifie si la grille est considérée comme terminée ou non
 * @param g Un pointeur vers la grille
 * @return 1 si la grille est finie, 0 sinon
 */
int checkFinish(Grid* g);


/**
 * @brief Modification d'une case de la grille
 * @param a Pointeur vers la grille
 * @param i Ligne
 * @param j Colonne
 * @param val Valeur à mettre
 */
void setCell(Grid* a,int i ,int j, char val);

/**
 * @brief Modifie une case en fonction de sa position et sa valeur
 * @param g Un pointeur vers la grille
 * @param val La valeur à mettre à la place
 * @param pos La position où mettre la valeur
 */
void setPosCell(Grid* g, Position pos, char val);

int getGoalNumber(Grid g);

#endif
