#include <stdio.h>

int main()
{
    int n, s;

    scanf("%d", &n);

    s = ((n % 1000) / 100) + ((n % 100) / 10) + (n % 10);

    printf("%d", s);

    return 0;
}