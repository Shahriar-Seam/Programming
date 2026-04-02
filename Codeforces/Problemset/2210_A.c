#include <stdio.h>
#include <stdint.h>

void solve()
{
    int n, i;

    scanf("%d", &n);

    for (i = n; i > 0; i--) {
        printf("%d ", i);
    }

    printf("\n");
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}