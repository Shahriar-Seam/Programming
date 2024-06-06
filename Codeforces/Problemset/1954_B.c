#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, i, temp, first, last, count = INT_MAX, cnt = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        
        if (i == 0) {
            first = temp;
        }
        if (i == n - 1) {
            last = temp;
        }

        if (temp == first) {
            cnt++;
        }
        else {
            count = min(count, cnt);

            cnt = 0;
        }
    }

    count = min(count, cnt);

    if (first != last || count == n) {
        printf("-1\n");
    }
    else {
        printf("%d\n", count);
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