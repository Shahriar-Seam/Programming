#include <stdio.h>

void solve()
{
    int n, i, temp, counter[55] = {}, count = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        counter[temp]++;
    }

    for (i = 0; i < 55; i++) {
        count += (counter[i] % 2);
    }

    puts((count > 0) ? "YES" : "NO");
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