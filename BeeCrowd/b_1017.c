#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%0.3lf\n", a * b / 12.0);

    return 0;
}