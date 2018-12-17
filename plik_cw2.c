#include <stdio.h>
#include <math.h>

int main(void)
{
	const int dimx = 510;
	const int dimy = 510;
	int i,j;
	FILE * fp = fopen ("new3.ppm", "wb");
	
	fprintf (fp, "P6\n%d %d\n255\n", dimx, dimy);
	
	for( j = 0; j < dimy; ++j){
		for( i = 0; i < dimx; ++i){
			static unsigned char color[3];
			color[0] = cos (i % 255); // red
			color[1] = sin (j % 255); // green
			color[2] = cosh ((i * j) % 255); //blue
			fwrite (color, 1, 3, fp);
		}
	}
	fclose (fp);
	return 0;
}