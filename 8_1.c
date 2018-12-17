#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define R 8

int main (void)
{
	int c, tab[R], i = 0;
	srand (time (NULL));
	
	puts ("Podaj kolejne wartosci tablicy :");
	while ((c = getchar ()) != EOF) {
		getchar ();
		tab[i] = c;
		putchar (c);
		printf (" = %d\n", c);
		++i;
		if (i == R){
			break;
		}
	}
	
	puts (" Losowe liczby :");
	for (i = 0; (c = 'a' + rand()%('z'-'a'+1)) != EOF; ++i){
		if (i == 2 * R){
			break;
		}
		
		printf("\tznak : jakoznak %c, jakoliczba %d\n", c, c);
	}
	return 0;
}