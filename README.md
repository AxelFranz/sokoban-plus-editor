# Sokoban
Vous trouverez ici les fichiers du TP noté concernant le jeu du Sokoban par [**Axel FRANZ**](https://github.com/AxelFranz).

Les consignes et l'énoncé du travail de base (sans l'éditeur se trouve à cette adresse : [TP Sokoban](https://techdevprintemps2022.pages.unistra.fr/TP_TechDevEnonce/)

```
Liste des règles makefile :
    * compilSDL : Permet de compiler et installer SDL2
	* main : Permet de compiler le main
	* archive : Permet de créer l'archive à rendre
	* doc : Permet de compiler la documentation qui sera dans doc/
	* clean : Permet de supprimer tous les fichiers indésirables
    * all : Compile tout ce qui n'existe pas (doc + SDL + executable)

Options de lancement :
    * --sdl2 : Pour jouer en mode graphique
    * --console : Pour jouer en mode console
    * --editor : Lance l'editeur de niveaux (en mode graphique)
    * Sans argument : Mode console par défaut
```
Dépendances :
* [SDL2](https://github.com/libsdl-org/SDL) 

```
Commandes : 
    * En mode jeu (non-editeur) 
        - (hjkl) : (Gauche,Bas,Haut,Droite)
    * En mode editeur
        - Clic souris : Changer la case
        - w : Sauvegarder le niveau (interaction dans le terminal)
    * Communes : 
        - q : Quitter le jeu
```
<br/>
Utilisation du jeu : 
    - Faire juste `make` ou `make all` pour tout compiler (SDL + doc + executable)
    - Lancer ./main avec les options données ci-dessus

Fait et compilé avec GCC 12.2.0 avec le standard C11
