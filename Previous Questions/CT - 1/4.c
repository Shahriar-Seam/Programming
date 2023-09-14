#include <stdio.h>

int main()
{
    int i, j, s;

    for (i = 1; i <= 3; i++) {
        for (j = i; j <= 5; j += 1) {
            s = i + j;

            if (s % 2 == 0) {
                printf("\n%d and %d make an even number", i, j);
            }
        }
    }

    return 0;
}