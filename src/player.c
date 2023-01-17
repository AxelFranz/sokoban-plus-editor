/**
 * @file player.c
 * Fichier contenant les différentes fonctions définies dans player.h
 * @author Axel FRANZ
 */

#include "player.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Position getPlayerPos(Player a){
    return a.pos;
}

enum Event event(){
    char entry = fgetc(stdin);
    switch(entry){
        case 'h':
            return Left;
        case 'j':
            return Bottom;
        case 'k':
            return Top;
        case 'l':
            return Right;
        case 'q':
            return Quit;
        case 'r':
            return Retry;
        default:
            return None;
    }
}


Position posDir(Position pos, enum Event d){
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
        default:
            break;
    }
    return new_pos;
}

void move_player(Grid* g, enum Event d){
	Position pos = getPlayerPos(g->player);
    Position new_pos = posDir(pos, d);
    if(checkCase(*g,new_pos) == BOX){
        Position test = posDir(new_pos, d);
        if(isNoWall(g,test)){
            switchCase(g,new_pos, test);
        }
    }
    if(isNoWall(g,new_pos)){
        switchCase(g,pos,new_pos);
        g->player.pos=new_pos;
    }
}

