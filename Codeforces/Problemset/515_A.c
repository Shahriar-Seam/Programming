#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, s;

    scanf("%d %d %d", &a, &b, &s);

    puts((abs(a) + abs(b) <= s && ((abs(a) + abs(b)) % 2) == (s % 2)) ? "YES" : "NO");

    return 0;
}