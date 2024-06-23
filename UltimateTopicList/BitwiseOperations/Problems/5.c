#include <stdio.h>

int main()
{
    int q, i, n;

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        scanf("%d", &n);

        unsigned int bleh = ~n;

        printf("%u\n", bleh);
    }

    return 0;
}