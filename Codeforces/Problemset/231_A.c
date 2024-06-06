#include <stdio.h>

int main()
{
    int n, a, b, c, i, count = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);

        if ((a && b) || (a && c) || (b && c)) {
            count++;
        }
    }

    printf("%d", count);
}