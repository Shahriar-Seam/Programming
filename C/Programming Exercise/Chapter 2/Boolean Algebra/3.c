#include <stdio.h>

int main()
{
    int a, b, c, s;

    scanf("%d %d %d", &a, &b, &c);

    s = a && (b || c);

    printf("A . (B + C) = %d", s);

    return 0;
}