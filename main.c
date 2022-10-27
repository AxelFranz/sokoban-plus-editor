#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	/*
	 * Test
	*/	
	bool run = true;
	struct Grid a = init_level("level1.txt");
	fprintf(stdout,"%d",a.column_number);
	/*while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}*/
}

