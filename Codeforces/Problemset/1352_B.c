#include <stdio.h>

void solve()
{
    int n, k, i, sum, temp;

    scanf("%d %d", &n, &k);

    temp = n - (k - 1);

    if (temp > 0 && temp % 2 == 1) {
        printf("YES\n");

        for (i = 1; i < k; i++) {
            printf("1 ");
        }

        printf("%d\n", temp);

        return;
    }

    temp = n - 2 * (k - 1);

    if (temp > 0 && temp % 2 == 0) {
        printf("YES\n");

        for (i = 1; i < k; i++) {
            printf("2 ");
        }

        printf("%d\n", temp);

        return;
    }
    
    printf("NO\n");
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