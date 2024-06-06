#include <stdio.h>

void solve()
{
    int u, v, a, s;

    scanf("%d %d %d %d", &u, &v, &a, &s);

    if (u <= v) {
        printf("YES\n");
    }
    else {
        if ((double)(u * u - v * v) / (2.0 * a) <= s) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
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