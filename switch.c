#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  
  char c;
  for(;;){  
    printf("\nWprowadz cyfre od 1 do 5: ");  
    scanf("%c",&c);
    switch (c) {
    case '0': 
      printf("Wprowadzono: 0\n");
      break;
    case '1':
      printf("Wprowadzono: 1\n");
	  break;
    case '2':
      printf("Wprowadzono: 2\n");
      break;
    case '3':
      printf("Wprowadzono: 3\n");
      break;
    case '4':
	  printf("Wprowadzono: 4\n");
    case '5':
      printf("Wprowadzono: 5\n");
      break;
    case '6':
      printf("Wywalamy :)\n");
      exit (1);
    default:
      printf("Wprowadzono: znak spoza zakresu 0-5\n");
      break;
    }
	
	/*if (c == '0'){
		 printf("Wprowadzono: 0\n");
	}
	else if(c == '1'){
		 printf("Wprowadzono: 1\n");
	}
	else if(c == '2'){
		 printf("Wprowadzono: 2\n");
	}
	else if(c == '3'){
		 printf("Wprowadzono: 3\n");
	}
	else if(c == '4'){
		 printf("Wprowadzono: 4\n");
	}
	else if(c == '5'){
		 printf("Wprowadzono: 5\n");
	}
	else if(c == '6'){
        printf("Wywalamy :)\n");
        exit (1);
	}
	else{
		printf("Wprowadzono: znak spoza zakresu 0-5\n");
	} */
  }
}
