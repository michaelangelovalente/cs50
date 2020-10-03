#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  DIGITS 2 //maximum number digits
#define BUFSIZ (DIGITS) + 3 //accounts for sign character, newline, and 0 terminator.




int main(int argc, char **argv){


	int h = 0;

	while( h <= 0 || h > 8  ){
		printf("height:");
		scanf("%d", &h);
	}
	
	//pyramid
	for(int x = 0; x < h; x++ ){
		for (int y1 =x+1; y1 <h;y1++ ){
			printf(" ");
		}
		for(int y2 = h-(x+1); y2 < h; y2++ ){
			printf("#");
		}
		printf(" ");
		
		for(int y2 = h-x; y2 <= h; y2++ ){
			printf("#");
		}
		printf("\n");
	}
	return 0;

}
