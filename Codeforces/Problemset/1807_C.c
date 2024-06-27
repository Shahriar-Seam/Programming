#include <stdio.h>

int solve()
{
    int n, i, j;

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i + 1; s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                if ((j - i) & 1) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        puts(solve() ? "YES" : "NO");
    }

    return 0;
}