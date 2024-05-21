#include <stdio.h>
#include <math.h>

void solve()
{
    int x, y, screens = 0, remaining = 0;

    scanf("%d %d", &x, &y);

    screens = ceil(y / 2.0);

    if (y == 0) {
        remaining = 0;

        screens = ceil(x / 15.0);

        x = 0;
    }
    else if (y % 2 == 0) {
        remaining = screens * 7;
    }
    else {
        remaining = screens * 7 + 4;
    }

    if (x > remaining) {
        x -= remaining;

        screens += ceil(x / 15.0);
    }

    printf("%d\n", screens);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}