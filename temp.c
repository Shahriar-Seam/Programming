#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        while (n > 0) {
            printf("%d ", n % 10);

            n /= 10;
        }

        printf("\n");
    }

    return 0;
}