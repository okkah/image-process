#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

int main(int argc, char *argv[])
{
    int size_x, size_y, x, y, z, cv;
    char scaler = (char)argv[3];
    char theta = (char)argv[4];
    char s[3];
    FILE *fp, *fpa;

    //printf("%d\n", argc-1);
    if(argc < 5)
    {
        printf("Error: Specify the input image, output image, enlargement ratio, rotation angle in order after the command.\n");
        exit(1);
    }

    fp = fopen(argv[1],"r");

    if(fp == NULL)
    {
        printf("Error: Failed to open file\n");
        exit(1);
    }

    fscanf(fp,"%s\n %d %d\n %d\n", s, &size_x, &size_y, &cv);
    
    int asize_x, asize_y, cx, cy, sx, sy, X, Y;
    double  ax, ay, dx, dy;
    int image[size_y][size_x][3];
    int aimage[asize_y][asize_x][3];

    double rad = theta * PI / 180;
    
    asize_x = (int)(fabs(size_x * cos(rad)) + fabs(size_y * sin(rad)) + 0.5);
    asize_y = (int)(fabs(size_x * sin(rad)) + fabs(size_y * cos(rad)) + 0.5);

    //printf("%d\n%d\n%d\n%d\n", size_x, size_y, asize_x, asize_y);

    cx = size_x / 2;
    cy = size_y / 2;

    sx = asize_x / 2;
    sy = asize_y / 2;

    for(y=0; y<size_y; y++)
    {
        for(x=0; x<size_x; x++)
        {
            for(z=0; z<3; z++)
            {
                fscanf(fp," %3d", &image[y][x][z]); 
            }
        }
    }
    fclose(fp);

    fpa = fopen(argv[2],"w");
    
    if(fpa == NULL)
    {
        printf("Error: Failed to export file\n");
        exit(1);
    }
    
    asize_x *= scaler;
    asize_y *= scaler;
    fprintf(fpa,"%s\n %d %d\n %d\n", s, asize_x, asize_y, cv);

    for(y=0; y<asize_y; y++)
    {
        for(x=0; x<asize_x; x++)
        {
            for(z=0; z<3; z++)
            {
                ax = (x - sx) * cos(rad) + (y - sy) * sin(rad);
                ay = -(x - sx) * sin(rad) + (y - sy) * cos(rad);
                
                ax /= scaler;
                ay /= scaler;

                ax += cx;
                ay += cy;

                X = (int)ax;
                Y = (int)ay;

                dx = ax - X;
                dy = ay - Y;
                
                //printf("dx=%f, dy=%f, ", dx, dy);
                
                if(X>=0 && X<size_x && Y>=0 && Y<size_y)
                {
                    aimage[y][x][z] = (1-dy) * (image[Y][X][z] * (1-dx) + image[Y+1][X][z] * dy) + dx * (image[Y][X+1][z] * (1-dy) + image[Y+1][X+1][z] * dy);
                }

                fprintf(fpa," %3d", aimage[y][x][z]);
                
            }
        }
    }

    fclose(fpa);

    return 0;
}
