# Sokoban
Vous trouverez ici les fichiers du TP noté concernant le jeu du Sokoban par [**Axel FRANZ**](https://git.unistra.fr/a.franz).

Si jamais vous téléchargez l'archive depuis moodle. Il faut mettre le dossier SDL2/ à la racine du projet. (Pas besoin de rajouter sdl2.h et sdl2.c, ils sont déjà là)

[Le code souce peut être trouvé ici](https://git.unistra.fr/a.franz/techdev-sokoban-franz)

Les consignes et l'énoncé se trouve à cette adresse : [TP Sokoban](https://techdevprintemps2022.pages.unistra.fr/TP_TechDevEnonce/)

```
Liste des règles makefile :
    * compilSDL : Permet de compiler et installer SDL2
	* main : Permet de compiler le main
	* archive : Permet de créer l'archive à rendre
	* doc : Permet de compiler la documentation qui sera dans doc/
	* clean : Permet de supprimer tous les fichiers indésirables
    * all : Compile tout ce qui n'existe pas (doc + SDL + executable)
```
Les fuites de mémoires présentes dans la version graphique viennent de SDL2 et non pas de mon programme. On peut voir qu'il n'y aucune fuite de mon côté en testant la version console.
```
Options de lancement :
    * --sdl2 : Pour jouer en mode graphique
    * --console : Pour jouer en mode console
    * --editor : Lance l'editeur de niveaux (en mode graphique)
    * Sans argument : Mode console par défaut
```
<br/>
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
