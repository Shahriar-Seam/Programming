#include <stdio.h>

int len(int n, int *f)
{
    int l = 0;

    while (n > 0) {
        *f = n;
        l++;
        n /= 10;
    }

    return l;
}

int main()
{
    int n, next, l, f;

    scanf("%d", &n);

    if (n < 10) {
        printf("%d\n", 1);

        return 0;
    }

    l = len(n, &f);

    next = f + 1;

    while (len(next, &f) < l) {
        next *= 10;
    }

    if (next < n) {
        next *= 10;
    }

    printf("%d\n", next - n);

    return 0;
}