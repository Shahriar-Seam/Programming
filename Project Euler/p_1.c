#include <stdio.h>

int main()
{
    int i, sum = 0;

    for (i = 1; i < 16; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}