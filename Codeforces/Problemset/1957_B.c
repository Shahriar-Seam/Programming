#include <stdio.h>
#include <math.h>

void solve()
{
    int n, k, i;

    scanf("%d %d", &n, &k);

    if (n == 1) {
        printf("%d\n", k);

        return;
    }

    if ((k & (k - 1)) == 0) {
        printf("%d ", k - 1);

        k = 1;
    }
    else if (((k + 1) & k) == 0) {
        printf("%d ", k);

        k = 0;
    }
    else {
        int l = log2(k);

        l = (1 << l);

        printf("%d ", l - 1);

        k = k - (l - 1);
    }

    printf("%d ", k);

    for (i = 2; i < n; i++) {
        printf("0 ");
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