#include <stdio.h>
#include <assert.h>

// generowanie histogramu

int main(void)  // program zliczania cyfr i innych znakow we wczytywanym napisie
{
  int i, j, nwhite = 0, nother = 0;
  int nalnum[16] = {0};

  int c;
  
  while ((c = getchar()) != EOF) {  // wczytywanie kolejnych znakow az do EOF
    if (48 <= c && c < 58) {
        assert(c);
        ++nalnum [c - '0'];
  		}
	else if (97 <= c && c < 103) {
		assert(c);
	    ++nalnum [c - 'a' + 10];
	    }
    else if (c == 32 || c == 10 || c == 11){  // znaki traktowane jako "white space"
		++nwhite;
  	}
    else{
		++nother;
    	}
  }
  
  printf ("\n\nHistogram :\n\n");
  for (i = 0; i < 16; ++i){
	  if (i > 9){
	  	  printf ("'%c' = %d", i + 87, nalnum[i]);
		  goto x;
	  }
	  printf ("'%d' = %d", i, nalnum[i]);
	  x:
	  for (j = 0; j < nalnum[i]; ++j){  // histogram
		  printf("*");
	  }
	  printf("\n");
  }
  printf ("\nwhite space = %d\nother = %d\n", nwhite, nother);
  
  return 0;
}