#include <stdio.h>

int main()
{
    int i, j;

    for (i = 4; i > 0; i--) {
        for (j = i; j > 0; j--) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}