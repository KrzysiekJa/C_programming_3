/*  Created by Krzysztof Jarek on 1.11.2018.
	Copyright © 2018 Krzysztof Jarek. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	FILE * fp;
	FILE * fp2;
	int c;
	
	if (argc < 2){  // gdy nie podano 2 plikow
		printf ("Poprawne uzycie: %s <nazwa pliku> <nazwa pliku>\n", argv[0]);
		exit(1);
	}
	
	fp = fopen (argv[1], "r");
	if (!fp){
		fprintf (stderr, "Blad otwarcia pliku %s\n", argv[1]);
		exit(1);
	}
	
	fp2 = fopen (argv[2], "w");
	if (!fp2){   // gdy nie podano drugiego pliku
		fp2 = fopen ( "kopia_pliku.txt", "w");
	}
	if (!fp2){
		fprintf (stderr, "Blad otwarcia pliku %s\n", argv[2]);
		exit(1);
	}
	
	while ( (c = fgetc(fp)) != EOF){  // proces kopiowania znak po znaku
		fputc (c, stdout);
		fputc (c, fp2);
	}
	
	fclose(fp);
	fclose(fp2);
	fp = NULL;
	fp2 = NULL;
	
	return EXIT_SUCCESS;
}