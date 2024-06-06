#include <stdio.h>
#include <math.h>

int main()
{
    char c[101][101];
    float x[101], y[101];
    int i, j;

    for (i= 0; i <= 100; i++) {
        for (j = 0; j <= 100; j++) {
            c[i][j] = '.';
            c[50][j] = '_';
        }
        c[i][50] = '|';
    }
    c[50][50] = '|';

    for (i = 0; i <= 100; i++) {
        x[i] = 0.1 * i;
        
        y[i] = 50 + 50 * sin(x[i]);

        c[i][(int) y[i]] = 220;
    }
    for (i = 0; i <= 100; i++) {
        x[i] = 0.1 * i;
        
        y[i] = 50 + 50 * cos(x[i]);

        c[i][(int) y[i]] = 240;
    }

    printf("\t\t\t\t\t\tsin(x)\t\t\t\t\t\tcos(x)\n");

    for (i =0; i <= 100; i++) {
        for (j = 0; j <= 100; j++) {
            printf("%c", c[i][j]);
            if (i == 50 && j == 100) {
                printf(" X axis");
            }
        }
        
        printf("\n");
    }

    printf("\t\t\t\t\t\tY axis\n");

    return 0;
}