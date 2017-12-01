#include <stdio.h>

int main()
{
	FILE *fp;
	char *ppm_format = "P3";
	int i, j;
	int width = 300;
	int height = 200;
	int tone = 255;
	
	fp = fopen("ex1.ppm", "w");

	fprintf(fp, "%s\n%d %d\n%d\n", ppm_format, width, height, tone);
	for(i=0; i<=height/3; i++)
	{
		for(j=0; j<width; j++)
		{
				fprintf(fp, "0 0 0 ");
		}                                                                                                              
	}

	for(i=0; i<=height/3; i++)
	{   
		for(j=0; j<width; j++)
		{   
				fprintf(fp, "255 0 0 ");
		}                                   
	}

    for(i=0; i<=height/3; i++)
	{   
		for(j=0; j<width; j++)
		{   
				fprintf(fp, "255 255 0 ");
		}                                   
	}   
 
	fclose(fp);
	
	return 0;
}