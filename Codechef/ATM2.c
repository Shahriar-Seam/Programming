#include <stdio.h>

void solve()
{
    int n, k, temp, i;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        if (temp <= k) {
            printf("1");

            k -= temp;
        }
        else {
            printf("0");
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