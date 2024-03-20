#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int a, b, c, ans;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b) {
        swap(&a, &b);
    }
    if (b > c) {
        swap(&b, &c);
    }
    if (a > b) {
        swap(&a, &b);
    }

    printf("%d\n", min(a - b * c, a - b - c));

    return 0;
}