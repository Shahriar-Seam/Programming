#include <stdio.h>

int main()
{
    int a = 3267, i = 0;

    while (a > 0) {
        int b = a % 10;

        printf("\n");

        for (i = 0; i < b; i += 2) {
            printf(" %d ", i * 2 + 1);
        }

        a = a / 10;
    }

    return 0;
}

/*

 1  5  9  13
 1  5  9
 1
 1  5
*/