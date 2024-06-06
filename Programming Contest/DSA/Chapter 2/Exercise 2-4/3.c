#include <stdio.h>

long long int rev(long long int n)
{
    int r = 0;

    while (n != 0) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }

    return r;
}

int main()
{
    long long int n, r, i, count = 0;

    scanf("%lld", &n);

    for (i = 1; ; i++) {
        r = rev(i);

        if (r == i) {
            count++;
        }

        if (count == n) {
            break;
        }
    }

    printf("%d\n", r);

    return 0;
}