#include <stdio.h>

void solve()
{
    int n, i, count = 0;

    scanf("%d", &n);

    char s[2][n + 1];

    scanf(" %s %s", s[0], s[1]);

    for (i = 1; i < n - 1; i++) {
        if (s[0][i - 1] == '.' && s[0][i] == '.' && s[0][i + 1] == '.') {
            if (s[1][i - 1] == 'x' && s[1][i] == '.' && s[1][i + 1] == 'x') {
                count++;
            }
        }
        if (s[0][i - 1] == 'x' && s[0][i] == '.' && s[0][i + 1] == 'x') {
            if (s[1][i - 1] == '.' && s[1][i] == '.' && s[1][i + 1] == '.') {
                count++;
            }
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