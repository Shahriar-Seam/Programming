#include <stdio.h>

int main()
{
    int t, x;
    int a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &x);

        a = 1;
        b = x - 1;

        printf("%d %d\n", a, b);
    }

    return 0;
}