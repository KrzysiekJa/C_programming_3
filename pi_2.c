#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#define  PRECYZJA 0.00000005
#define  GRANICA 1.e-15


int main (void)
{
	int i;
	long double pi_k = 0, pi_g, pi = 0;
	
	//pi wg wzoru Euler'a na trzy sposoby
	for (i = 1; i < 40000; ++i){
		pi_g = pi_k;
		pi_k += 1. / (i * i);
		
		if (fabsl (pi_k - pi_g) < GRANICA){
			puts ( "Przekroczona granica dokladnosci!\n");
			break;
		}
	}
	
	pi = sqrtl (6. * pi_k);
	printf("PI uzyskane w pentli for po %i iteracjach: %20.18Lf\n\n", i, pi);
	
	float pi_kf = 0, pi2;
	i = 1;
	while ( (1. / (i * i)) > PRECYZJA){
		pi_kf += 1. / (i * i);
		++i;
	}
	
	pi2 = sqrt (6. * pi_kf);
	printf("PI uzyskane w pentli while po %i iteracjach: %20.18f\n", i, pi2);
	printf ("Zalozona dokladnosc : %20.18lf, realny blad : %20.18lf\n\n", PRECYZJA, fabs (pi2 - M_PI));
	
	double pi3 = 0;
	double pi_kf2 = 0;
	double pi_w;
	i = 1;
	do {
		pi_w = pi_kf2;
		pi_kf2 += 1. / (i * i);
		++i;
	} while (fabs (pi_kf2 - pi_w) > PRECYZJA);
	
	pi3 = sqrt (6. * pi_kf2);
	printf("PI uzyskane w pentli do-while po %i iteracjach: %20.18lf\n", i, pi3);
	printf ("Zalozona dokladnosc : %20.18lf, realny blad : %20.18lf\n\n", PRECYZJA, fabs (pi3 - M_PI));
	printf("PI w bibliotece std. : %20.18f\n\n", M_PI);
	
	double dokl;
	puts ("Podaj wartosc doskladnosci dla liczenia ln(2):");
    if (sizeof(double) == 8){ 
      scanf ("%lf", &dokl);
	  printf("Uzyskana dokladnosc : %20.18lf\n\n", dokl);
    }
    else{
      scanf ("%f", &dokl);
	  printf("Uzyskana dokladnosc : %20.18f\n\n", dokl);
    }
    if (dokl >= 0.01){ 
		dokl = 0.005;
    }
	
	// ln(2) liczony z szeregu Taylor'a
	long double ln_2 = 0, y = 0, a;
	i = 1;
	int x = 2;
	while ( fabsl (y - (a = pow(x - 1., i)/ i)) > dokl){
		if (i % 2 == 0){
			ln_2 -= a;
		}
		else {
			ln_2 += a;
		}
		++i;
		y = a;
	}
	
	printf("ln(2) uzyskany w petli while po %i iteracjach: %20.18Lf\n", i, ln_2);
	printf ("Zalozona dokladnosc : %20.18lf\n\n", dokl);
	
	return 0;
}