#include <stdio.h>

int main()
{
    int n, t, count = 0, h, r;

    scanf("%d %d", &n, &t);

    if (n != t) {
        count = n;

        while (n >= t) {
            h = n / t;
            count += h;
            r = n % t;
            n = h + r;
        }
    }
    else {
        count = n + 1;
    }

    printf("%d\n", count);

    return 0;
}