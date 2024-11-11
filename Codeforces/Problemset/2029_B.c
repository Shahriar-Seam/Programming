#include <stdio.h>

void solve()
{
    int n, i, zero = 0, one = 0, f = 1;

    scanf("%d", &n);

    char s[n + 1], r[n];

    scanf(" %s %s", s, r);

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
        }
        else {
            one++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        if (!one || !zero) {
            f = 0;
            break;
        }

        if (r[i] == '0') {
            one--;
        }
        else {
            zero--;
        }
    }

    puts(f ? "YES" : "NO");
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