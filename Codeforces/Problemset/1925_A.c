#include <stdio.h>

void solve()
{
    int n, k, i;

    scanf("%d %d", &n, &k);

    char s[n * k + 1];

    for (i = 0; i < n * k; i++) {
        s[i] = 'a' + i % k;
    }

    s[i] = '\0';

    puts(s);
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