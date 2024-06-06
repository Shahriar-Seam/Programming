#include <stdio.h>
int main()
{
    int t, a, b, c, l;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        if (a >= b && a >= c) {
            l = a;

            if (a == b || a == c) {
                printf("%d %d %d\n", (l - a + 1), (l - b + 1), (l - c + 1));
            }
            else {
                printf("%d %d %d\n", (l - a), (l - b + 1), (l - c + 1));
            }
        }

        else if (b >= a && b >= c) {
            l = b;

            if (b == a || b == c) {
                printf("%d %d %d\n", (l - a + 1), (l - b + 1), (l - c + 1));
            }
            else {
                printf("%d %d %d\n", (l - a + 1), (l - b), (l - c + 1));
            }
        }

        else {
            l = c;

            if (c == a || c == b) {
                printf("%d %d %d\n", (l - a + 1), (l - b + 1), (l - c + 1));
            }
            else {
                printf("%d %d %d\n", (l - a + 1), (l - b + 1), (l - c));
            }
        }
    }

    return 0;
}