#include <stdio.h>

int main()
{
    int t, n, x, y, a, b, c, d;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        a = b = c = d = 0;

        while (n--) {
            scanf("%d %d", &x, &y);

            if (x > 0) {
                a = 1;
            }
            if (x < 0) {
                b = 1;
            }
            if (y > 0) {
                c = 1;
            }
            if (y < 0) {
                d = 1;
            }
        }

        if (a + b + c + d < 4) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}