#include <stdio.h>

int main()
{
    for (int i = 1; i <= 1001; i++) {
        printf("%4d\t", i);
        if (i % 7 == 0) {
            printf("\n");
        }
    }

    return 0;
}