#include <stdio.h>

int main()
{
    int i;

    for (i = 32; i <= 255; i++) {
        printf("%d %c\n\n", i, i);
    }

    // printf("%d%d%d%d%d", 'A', 'B', 'C', 'D', 'E');

    return 0;
}