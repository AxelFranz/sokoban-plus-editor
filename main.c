#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
}

