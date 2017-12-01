#include <stdio.h>

int main()
{
	int size_x,size_y,x,y,z,cv;
	char s[3];
	FILE *fp;

	fp = fopen("ex1.ppm","r");

	fscanf(fp,"%s\n %u %u\n %u\n",s,&size_x,&size_y,&cv);
	
	int image[size_y][size_x][3];

	for(y=0; y<size_y; y++)
	{
		for(x=0; x<size_x; x++)
		{
			for(z=0; z<3; z++)
			{
				fscanf(fp," %3d",&image[y][x][z]); 
			}
		}
	}
	fclose(fp);

	fp = fopen("ex2.ppm","w");

	fprintf(fp,"%s\n%u %u\n%u\n",s,size_x,size_y,cv);

	for(y=0; y<size_y/3; y++)
	{
		for(x=0; x<size_x; x++)
		{
			image[y][x][0] = image[y][x][1] = image[y][x][2] = 200;
			fprintf(fp,"%3u %3u %3u ",image[y][x][0],image[y][x][1],image[y][x][2]);
		}	
		fputc((int)'\n',fp);
	}

	for(y=size_y/3; y<size_y; y++)
	{
		for(x=0; x<size_x; x++)
		{
			fprintf(fp,"%3u %3u %3u ",image[y][x][0],image[y][x][1],image[y][x][2]);
		}
		fputc((int)'\n',fp);
	}
	 
	fclose(fp);

	return 0;
}