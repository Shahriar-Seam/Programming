#include <stdio.h>

int main()
{
    int taka, total = 0, i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &taka);
        total = total + taka;
    }

    printf("%d\n", total);

    return 0;
}