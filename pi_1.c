#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#define SCALAR float
#define WART_PRECYZJI 1.e-17
#define DOKLADNOSC 0.001

// PI liczone metoda Laibniz'a
int main (void)
{
	
	int max_liczba_wyrazow;
	puts ("Podajze maxymalna liczbe wyrazow : ");
	scanf ("%d", &max_liczba_wyrazow);
	
    SCALAR dokladnosc;
    puts ("Podaj dokladnosc obliczenia przyblizenia PI - float : ");
    if (sizeof(SCALAR) == 4){ 
      scanf ("%f", &dokladnosc);
    }
    else{
      scanf ("%lf", &dokladnosc);
    }
	
	if (dokladnosc >= DOKLADNOSC){ 
		dokladnosc = DOKLADNOSC;
    }
	printf("Dokladnosc: %17.15lf\n\n", dokladnosc);
	
	SCALAR suma_plus = 0.0;
	SCALAR suma_minus = 0.0;
	int i = 0, j = 1;
	
   	for (i = 0; i < ceil(max_liczba_wyrazow / 2.0); ++i){
		j = 1 + 4 * i;
		suma_plus += 1.0 /j;
		suma_minus += 1.0 /(j + 2.0);
		
		printf("PI obliczone: %20.15lf, aktualna poprawka: %20.15lf\n",4 * (suma_plus - suma_minus), 4.0 /j - 4.0 /(j + 2.0));
		
		if (i >= ceil (max_liczba_wyrazow / 2.0)) {
			printf("\nPrzekroczona maksymalna liczba wyrazĂłw %d", max_liczba_wyrazow);
			printf(" przed osiagnieciem zalozonej dokladnosci - break\n");
			break;
		}
    }	
    printf("\nPI obliczone: %17.15lf; \nPI z biblioteki matematycznej: %17.15lf\n", 4 * (suma_plus - suma_minus), M_PI);
    printf("Zalozona dokladnosc: %17.15lf, rzeczywisty blad: %17.15lf\n", dokladnosc, fabs( 4 * (suma_plus - suma_minus) - M_PI) );
	
	suma_plus = 0.0;
	suma_minus = 0.0;
	i = 0, j = 1;
	do{
		j = 1 + 4 * i;
		suma_plus += 1.0 /j;
		suma_minus += 1.0 /(j + 2.0);
		++i;
		
		if (sizeof (SCALAR) == 4){
			SCALAR temp_PI = 4 * (suma_plus - suma_minus);
			SCALAR temp_poprawka = (4.0 /j - 4.0 /(j + 2.0));
			
			if ((temp_PI + temp_poprawka) - temp_PI < WART_PRECYZJI){
				printf("\nDodatkowe wyrazy przestaja zmieniac wynik! Przerwanie obliczen!\n");
				break;
			}

		}
	} while (i < ceil (max_liczba_wyrazow / 2.0));
    printf("\nPI obliczone: %17.15lf; \nPI z biblioteki matematycznej: %17.15lf\n", 4 * (suma_plus - suma_minus), M_PI);
    printf("Zalozona dokladnosc: %17.15lf, rzeczywisty blad: %17.15lf\n", dokladnosc, fabs (4 * (suma_plus - suma_minus) - M_PI));
	
	suma_plus = 0.0;
	suma_minus = 0.0;
	i = 0, j = 1;
	while (( 4.0 /j - 4.0 /(j + 2.0)) > dokladnosc){
		suma_plus += 1.0 /j;
		suma_minus += 1.0 /(j + 2.0);
		j += 4;
		i = (j - 1) /4;
	}
    printf("\nPI obliczone: %17.15lf; \nPI z biblioteki matematycznej: %17.15lf\n", 4 * (suma_plus - suma_minus), M_PI);
    printf("Zalozona dokladnosc: %17.15lf, rzeczywisty blad: %17.15lf\n\n\n", dokladnosc, fabs( 4 * (suma_plus - suma_minus) - M_PI) );
	
	
	return EXIT_SUCCESS;
}