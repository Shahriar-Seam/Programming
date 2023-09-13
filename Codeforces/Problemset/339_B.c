#include <stdio.h>

int main()
{
    int n, m, i, a, previous;
    unsigned long long int count;

    scanf("%d %d %d", &n, &m, &a);

    count = a - 1;
    previous = a;

    for (i = 1; i < m; i++) {
        scanf("%d", &a);

        if (previous <= a) {
            count += a - previous;
        }
        else {
            count += n + a - previous;
        }

        previous = a;
    }

    printf("%llu", count);

    return 0;
}