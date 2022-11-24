/**
 * @file player.c
 * Fichier contenant les différentes fonctions définies dans player.h
 * @author Axel FRANZ
 */

#include "player.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

Position getPlayerPos(Player a){
    return a.pos;
}


Position posDir(Position pos, enum Direction d){
    Position new_pos = pos;
    switch(d){
       case Top:
           new_pos.y--;
           break;

        case Left:
            new_pos.x--;
            break;

        case Right:
            new_pos.x++;
            break;

        case Bottom:
            new_pos.y++;
            break;
    }
    return new_pos;
}

void move_player(Grid* a, enum Direction d){
	Position pos = getPlayerPos(a->player);
    Position new_pos = posDir(pos, d);
    if(checkCase(*a,new_pos) == ' '){
        switchCase(a,pos,new_pos);
        a->player.pos=new_pos;
    } else if(checkCase(*a,new_pos) == '$'){
        Position test = posDir(new_pos, d);
        if(checkCase(*a,test) == ' '){
            switchCase(a,new_pos, test);
            switchCase(a, new_pos, pos);
             a->player.pos=new_pos;
        }
    }
         

    // A FINIR D'ECRIRE
    // LE SWITCH CASE ET IMPLEMENTATION FINIE
	display(a);
}

