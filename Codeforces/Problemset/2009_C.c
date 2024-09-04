#include <stdio.h>
#include <math.h>

void solve()
{
    int x, y, k;

    scanf("%d %d %d", &x, &y, &k);

    x = ceil(x * 1.0 / k);
    y = ceil(y * 1.0 / k);

    if (y >= x) {
        printf("%d\n", 2 * y);
    }
    else {
        printf("%d\n", 2 * x - 1);
    }
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