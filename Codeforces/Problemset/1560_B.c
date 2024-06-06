#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, a, b, c, diff, max;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        diff = abs(a - b);

        max = 2 * diff;

        if (a > max || b > max || c > max) {
            printf("-1\n");
        }
        else {
            if (c - diff > 0) {
                printf("%d\n", c - diff);
            }
            else {
                printf("%d\n", c + diff);
            }
        }
    }

    return 0;
}