#include <stdio.h>
#include <string.h>

void solve()
{
    int i, n;
    char s[105];

    scanf(" %s", s);

    n = strlen(s);

    for (i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            printf("1\n");

            return;
        }
    }

    printf("%d\n", n);
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