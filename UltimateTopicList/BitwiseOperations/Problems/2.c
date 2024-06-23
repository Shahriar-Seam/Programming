#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int maximizingXor(int l, int r) {
    int i, j, xor = 0;

    for (i = l; i <= r; i++) {
        for (j = l; j <= r; j++) {
            xor = max(xor, i ^ j);
        }
    }

    return xor;
}

int main()
{
    int l, r;

    scanf("%d %d", &l, &r);

    printf("%d", maximizingXor(l, r));

    return 0;
}