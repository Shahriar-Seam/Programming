#include <stdio.h>

#define size 25

int main()
{
    int i, j, k, l = 2, m, n, o = 1, p;

    for (i = 0; i < size / 2; i++) {
        for (j = 0; j < size - i - o; j++) {
            printf(" ");
        }

        if (i > size / 8) {
            l = 1;
            o -= 2;
        }

        for (k = 0; k < l; k++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}