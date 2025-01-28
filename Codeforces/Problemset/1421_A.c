#include <stdio.h>

void solve()
{
    int a, b, x = 0, i;

    scanf("%d %d", &a, &b);

    for (i = 0; i < 31; i++) {
        if ((a & (1 << i)) && (b & (1 << i))) {
            x |= (1 << i);
        }
    }

    printf("%d\n", (a ^ x) + (b ^ x));
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