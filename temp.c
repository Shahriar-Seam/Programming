#include <stdio.h>

int main() 
{
    unsigned long long int i, t, n, f;

    scanf("%llu", &t);

    while (t--) {
        scanf("%llu", &n);

        f = 1;

        for (i = 2; i <= n; i++) {
            f *= i;
        }

        printf("%llu\n", f);
    }

    return 0;
}
