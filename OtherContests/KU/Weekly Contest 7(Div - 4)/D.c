#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int n, i;

    scanf("%d", &n);

    printf("%d\n", n / 2);

    if (n % 2 == 0) {
        for (i = 0; i < n / 2; i++) {
            printf("2 ");
        }
    }
    else {
        printf("3 ");

        for (i = 0; i < n / 2 - 1; i++) {
            printf("2 ");
        }
    }

    return 0;
}