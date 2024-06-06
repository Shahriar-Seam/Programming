#include <stdio.h>

int main()
{
    int n, i = 0;

    scanf("%d", &n);

    for (n; n >= 1; ) {
        if (n == 1) {
            break;
        }

        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = 3 * n + 1;
        }

        printf("%d\n", n);

        i++;
    }

    printf("Cycles needed = %d\n", i);
}