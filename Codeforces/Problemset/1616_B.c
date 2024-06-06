#include <stdio.h>
#include <string.h>

void solve()
{
    int n, i, j;

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 0; i < n - 1; i++) {
        if (s[i] <= s[i + 1]) {
            break;
        }
    }

    j = i + 1;

    for (i; i >= 0; i--) {
        s[j++] = s[i];
    }

    s[j] = '\0';

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