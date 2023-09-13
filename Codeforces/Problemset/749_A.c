#include <stdio.h>

int main()
{
    int n, i, count = 0, d;

    scanf("%d", &n);

    if (n % 2 == 1) {
        n = n - 3;
        count++;

        d = n / 2;

        count += d;

        printf("%d\n3 ", count);

        for (i = 0; i < d; i++) {
            printf("2 ");
        }
    }
    else {
        d = n / 2;

        count += d;

        printf("%d\n", count);

        for (i = 0; i < d; i++) {
            printf("2 ");
        }
    }

    return 0;
}