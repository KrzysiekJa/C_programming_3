#include <stdio.h>


int main(void) // program zliczania cyfr i innych znakow we wczytywanym napisie
{
  int i, nwhite = 0, nother = 0;
  int ndigit[10] = {0};

  int c;
  
  while ( (c = getchar()) != EOF) { // wczytywanie kolejnych znakow az do EOF
    if (48 <= c && c < 58) {
      ++ndigit[c-'0']; 
      printf("%c, %d,  %d\n", c, c-'0', ndigit[c-'0']);
  		}
    else if(c == 32 || c == 10 || c == 11){ // znaki traktowane jako "white space"
		++nwhite;
  	}
    else{
		++nother;
    	}
  }
  
  printf("\ndigits:\n");  
  for (i = 0; i < 10; ++i){
	  printf ("'%d' = %d\n", i, ndigit[i]);
  }
  printf ("white space = %d\nother =  %d\n", nwhite, nother);
  
  return 0;
}