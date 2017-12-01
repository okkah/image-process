#include <stdio.h>

int main()
{
	unsigned char image[300][200][3];
	int x,y,i;
	FILE *fp;
	if((fp = fopen("ex1.ppm","rb"))==NULL)
	{
		printf("ファイルが開けません\n");
	}
	
	fscanf(fp,"P6\n300 200\n255\n");
	fread(image,sizeof(char),300*200*3,fp);
	fclose(fp);

	fp = fopen("ex3.ppm","wb");
	fprintf(fp,"P6\n300 200\n255\n");
	fwrite(image,sizeof(char),300*200*3,fp);
	fclose(fp);

	return 0; 
}
