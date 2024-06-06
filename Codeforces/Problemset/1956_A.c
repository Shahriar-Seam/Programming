#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int k, q, i, temp, a, n;

    scanf("%d %d", &k, &q);

    scanf("%d", &a);

    a--;

    for (i = 1; i < k; i++) {
        scanf("%d", &temp);
    }

    for (i = 0; i < q; i++) {
        scanf("%d", &n);

        printf("%d ", min(a, n));
    }

    printf("\n");
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