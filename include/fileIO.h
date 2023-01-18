/**
 * @file fileIO.h
 * Fichier contenant les définitions des fonctions de fileIO.c
 * @author Axel FRANZ
 */
#ifndef FILE_m_h
#define FILE_m_h

// Pour les dépendances
struct Grid;

/**
 * @brief Permet de mettre un caractère dans un fichier (fonction non utilisée). Si le fichier existe, il est écrasé.
 * @param file_name Le chemin vers le fichier
 * @param c Le caractère à ajouter
 */
void fputChar(const char* file_name, const char c);

/**
 * @brief Permet d'ajouter un caractère à un fichier. Si le fichier existe, il est ajouté. 
 * @param file_name Le chemin vers le fhicer
 * @param c Le caractère à ajouter
 */
void fappendChar(const char* file_name, const char c);

/**
 * @brief Print une chaine de caractères dans un fichier. S'il existe, le fichier est écrasé.
 * @param file_name Le chemin vers le fichier
 * @param printed La chaine de caractères à ajouter dans le fichier
 */
void fprintString(const char* file_name, const char* printed);

/**
 * @brief Permet d'ajouter une chaine de caractères à un fichier. Si le fichier existe, tout sera ajouté à la fin (fonction non utilisée)
 * @param file_name Le chemin vers le fichier
 * @param printed La chaine de caractères à ajouter
 */
void fappendString(const char* file_name, const char* printed);

/**
 * @brief Crée un fichier contenant toutes les informations d'une grille
 * @param file_name Le chemin vers le fichier
 * @param g La grille a parser
 */
void createGridFile(const char* file_name, struct Grid g);

/**
 * @brief Permet de mettre tous les noms de fichier d'un dossier dans un tableau
 * @param dirname Le chemin vers le dossier
 * @param names Un tableau contenant des strings
 * @param size_names Une variable qui contiendra la taille du tableau
 */
void listFolder(const char* dirname, char** names, int* size_names);

/**
 * @brief Permet d'afficher tous les fichiers présents dans un dossier
 * @param dirname Le chemin vers le dossier
 * @return Un tableau dynamiqe contenant tous les noms de fichiers (penser à le free)
 */
char** printFolder(const char* dirname);
#endif
