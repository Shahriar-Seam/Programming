#include <stdio.h>
#include <math.h>

void solve()
{
    int n, l, k, i;

    scanf("%d", &n);

    l = floor(log2(n));

    k = (1 << l);

    if (k == n) {
        k /= 2;
    }

    if (n == 2) {
        printf("0 1\n");

        return;
    }

    for (i = 1; i < n; i++) {
        if (i != k) {
            printf("%d ", i);
        }
        else {
            printf("%d %d ", 0, k);
        }
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