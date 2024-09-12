#include <stdio.h>

int len(int n)
{
    int l = 0;

    while (n > 0) {
        l++;
        n /= 10;
    }

    return l;
}

int main()
{
    int n, next, l;

    scanf("%d", &n);

    next = n + 1;

    l = len(next);

    return 0;
}