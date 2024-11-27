#include <stdio.h>
#include <string.h>

void solve()
{
    char s[100005], p[10];
    int i, f = 0, n;

    scanf(" %s", s);

    n = strlen(s);

    for (i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            f = 1;

            p[0] = s[i];
            p[1] = s[i + 1];
            p[2] = '\0';

            break;
        }
    }

    if (!f) {
        for (i = 1; i < n - 1; i++) {
            if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]) {
                f = 1;

                p[0] = s[i - 1];
                p[1] = s[i];
                p[2] = s[i + 1];
                p[3] = '\0';

                break;
            }
        }
    }

    puts(f ? p : "-1");
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