#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int x1, y1, x2, y2, time;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 == x2 || y1 == y2) {
        time = abs(x1 - x2) + abs(y1 - y2);
    }
    else {
        time = abs(x1 - x2) + abs(y1 - y2) + 2;
    }

    printf("%d\n", time);
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