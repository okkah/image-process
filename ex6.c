#include <stdio.h>
#include <stdlib.h>

void image_read(unsigned char *image, FILE *fp, int x, y, z, cv);
void image_write(unsigned char *image, FILE *fp, int x, y, z, cv);

int main()
{	
	unsigned char *image = calloc(300*200*3, sizeof(unsigned char));;
	FILE *fp;
	int x,y,z,cv;

	image_read(image, fp, x, y, z, cv);	
	image_write(image, fp, x, y, z, cv);

	free(image);

	return 0;
}

void image_read(unsigned char *image, FILE *fp, int x, y, z, cv)
{
	fp = fopen("ex1.ppm","r");	

	for(y=0; y<200; y++)
	{
		for(x=0; x<300; x++)
		{
			for(z=0; z<3; z++)
			{
				fscanf(fp," %3d", &image[(y*300+x)*3+z]); 
			}
		}
	}
	fclose(fp);
}

void image_write(unsigned char *image, FILE *fp, int x, y, z, cv)
{
	fp = fopen("ex6.ppm","w");

	fprintf(fp,"P3\n300 200\n255\n");

	for(y=0; y<66; y++)
	{
		for(x=0; x<300; x++)
		{
			image[(y*300+x)*3+0] = image[(y*300+x)*3+1] = image[(y*300+x)*3+2] = 200;
			fprintf(fp,"%3u %3u %3u ",image[(y*300+x)*3+0],image[(y*300+x)*3+1],image[(y*300+x)*3+2]);
		}	
		fputc((int)'\n',fp);
	}

	for(y=66; y<132; y++)
	{
		for(x=0; x<300; x++)
		{
			image[(y*300+x)*3+0] = image[(y*300+x)*3+1] = image[(y*300+x)*3+2] = 100;
			fprintf(fp,"%3u %3u %3u ",image[(y*300+x)*3+0],image[(y*300+x)*3+1],image[(y*300+x)*3+2]);
		}
		fputc((int)'\n',fp);
	}
	
	fclose(fp);
}
