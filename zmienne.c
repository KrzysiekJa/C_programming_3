/*  Created by Krzysztof Jarek on 1.11.2018.
	Copyright © 2018 Krzysztof Jarek. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h> 

// proste operacje na zmiennych

#define dzielenie(x,y) ((x)/(y))

int main(void)
{
	int podkreslnik_liczba, IILiczba, k; // deklaracje
	
	podkreslnik_liczba = 1234; // inicjalizacje
	IILiczba           = 4321;
	k                  = 2/3;
	
    puts("Smiesne liczby :");
    printf("%d\n", podkreslnik_liczba);
	printf("%d\n", IILiczba);
	puts("int k = 1/3 wynosi : "); printf("%5d\n\n", k);
	
	char * napis = "abc"; // definicje
	float a  = 4.5;
	double b = 4.5;
	printf("Napis : %s \nfloat a = %20.18f; double b = %le\n\n", napis, a, b);
	
	float c = 12 + k * 12;
	float l = 2./3;
	printf("l = %14.12f\n", l);
	float d = 12 + (int)l * 12;
	a = b; // utrata precyzji
    printf("c = %12.10f\nd = %12.10f\nfloat a = %12.10\n\n", c, d, a);
	
	puts("I jak z ta precyzja?"); // precyzja
	printf("l = %14.12f <- a l to nie jedna trzecia?\n", l);
	double e = a + b;
	printf("a + b = 9.00..., nie? : e = %14.12f \n", e);
	float f  = dzielenie(a,b);
	printf("a / b = 1.00..., nie? : f = %14.12f \n\n", f);
	
	int x = f;
	int g = ++x + x++; // kolejnosc
	int h = 2 + 2 / 2 - 2;
	printf("x = %d\ng = %d\nh = %d\n\n",x, g, h);
	
	k     = 123;
	int i = k % 2;
	int j = 0;
    printf("Wartosc wyrazenia %d < %d == 0 wynosi %d\n", i, j, i < j == 0);
    printf("Wartosc wyrazenia %d =< ++%d lub 0 wynosi %d\n", i, j, i <= ++j || 0);
	
	return EXIT_SUCCESS;
}	