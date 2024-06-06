#include <stdio.h>

int main()
{
    int i;

    for (i = 2; i <= 200; i+=2) {
        printf("%d\n", i * 7);
    }

    return 0;
}