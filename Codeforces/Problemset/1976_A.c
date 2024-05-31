#include <stdio.h>
#include <ctype.h>

void solve()
{
    int n, i, f = 0, is_it = 1;

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 1; s[i] != '\0'; i++) {
        if (f == 0 && isalpha(s[i])) {
            f = 1;
        }
        if (s[i] < s[i - 1]) {
            is_it = 0;

            break;
        }
        if (f == 1 && isalpha(s[i]) == 0) {
            is_it = 0;

            break;
        }
    }

    puts(is_it ? "YES" : "NO");
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