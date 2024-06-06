#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, i;

    scanf("%d %d", &n, &m);

    for (i = ceil(n / 2.0); i <= n; i++)
    {
        if (i % m == 0) {
            printf("%d", i);

            return 0;
        }
    }

    printf("-1");

    return 0;
}