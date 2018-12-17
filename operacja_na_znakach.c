/*  Created by Krzysztof Jarek on 1.11.2018.
	Copyright © 2018 Krzysztof Jarek. All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main (int argc, char * argv[])
{
	int znak;
	
	if( argc > 2){
		printf("Blad! Poprawne otwarcie : %s <nazwa pliku>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if( argc == 2){
		FILE * fp;
		
		fp = fopen (argv[1], "r");
		if (!fp) {
			puts("Blad otwarcia pliku.\n");
			exit(EXIT_FAILURE);
		}
		
		while ( (znak = fgetc(fp)) != EOF) {
	    	if( islower(znak) ) {
    			znak = toupper(znak);
    		} 
			else 
			if (isupper(znak)) {
				znak = tolower(znak);
			}
    		putchar(znak);
		}
		fclose(fp);
	}
	
	if ( argc < 2){
		puts("Prosze wprowadzic kolejne znaki do zamiany :");
		while ( (znak = getchar()) != EOF) {
	    	if( islower(znak) ) {
	    		znak = toupper(znak);
	    	} 
			else if (isupper(znak)) {
				znak = tolower(znak);
			}
	    putchar(znak);
		}
	}	
  
	return EXIT_SUCCESS;
}