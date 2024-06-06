#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solve()
{
    int a, b, c, tents = 0;

    scanf("%d %d %d", &a, &b, &c);

    tents += a;

    if ((b % 3 != 0) && c < (3 - (b % 3))) {
        puts("-1");

        return;
    }

    tents += ceil((b + c) / 3.0);

    printf("%d\n", tents);
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