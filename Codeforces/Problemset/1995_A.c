#include <stdio.h>

void solve()
{
    int n, k, count = 0;

    scanf("%d %d", &n, &k);

    if (k == 0) {
        printf("0\n");

        return;
    }

    k -= n;
    count++;

    while (k > 0) {
        count++;

        n--;

        k -= n;

        if (k > 0) {
            count++;
            k -= n;
        }
    }

    printf("%d\n", count);
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