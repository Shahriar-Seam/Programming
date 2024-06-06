#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, a, b, c, x, y;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

        x -= a;
        y -= b;

        if (x < 0) {
            x = 0;
        }
        if (y < 0) {
            y = 0;
        }

        if (x + y <= c) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}