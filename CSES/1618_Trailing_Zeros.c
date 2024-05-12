#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, max, count = 0;

    scanf("%d", &n);

    max = ceil(log(n) / log(5));

    for (i = 1; i <= max; i++) {
        count += n / pow(5, i);
    }

    printf("%d\n", count);

    return 0;
}