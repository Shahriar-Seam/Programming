#include <stdio.h>

int main()
{
    int n, r, count = 0;

    scanf("%d", &n);

    while (n != 0) {
        r = n % 10;
        n = n / 10;

        if ((r == 2) || (r == 3) || (r == 5) || (r == 7)) {
            count++;
        }
    }

    printf("Number of primes = %d\n", count);

    return 0;
}