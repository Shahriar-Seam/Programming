#include <stdio.h>

int main()
{
    long long l, r, a, b, c;

    scanf("%lld %lld", &l, &r);

    if (l % 2 == 0) {
        a = l;
        b = a + 1;
        c = b + 1;
    }
    else {
        a = l + 1;
        b = a + 1;
        c = b + 1;
    }

    if (c <= r) {
        printf("%lld %lld %lld\n", a, b, c);
    }
    else {
        printf("-1\n");
    }

    return 0;
}