#include <stdio.h>

int main()
{
    int t;
    int a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        ((a + b) == c) ? printf("+\n") : printf("-\n");
    }

    return 0;
}