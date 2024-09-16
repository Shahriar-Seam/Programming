#include <stdio.h>

int main()
{
    int a, b, r;

    scanf("%d %d %d", &a, &b, &r);

    puts((2 * r > a || 2 * r > b) ? "Second" : "First");

    return 0;
}