#include <stdio.h>

int main()
{
    int i, n = 0;

    for (i = 0; i < 10; i++) {
        n += i & 1;
    }

    printf("%d\n", n);

    return 0;
}