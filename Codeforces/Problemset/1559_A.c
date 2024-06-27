#include <stdio.h>
#include <limits.h>

void solve()
{
    int n, min_max_val = INT_MAX, temp;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);

        min_max_val &= temp;
    }

    printf("%d\n", min_max_val);
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