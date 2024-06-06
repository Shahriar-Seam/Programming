#include <stdio.h>

void solve()
{
    char s[50], c;
    int i, f = 0;

    scanf(" %s %c", s, &c);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            if ((i % 2) == 0) {
                f = 1;
                break;
            }
        }
    }

    puts(f == 1 ? "YES" : "NO");
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