#include <stdio.h>

void solve()
{
    int i, cut = 1, f = 0;
    char s[502];

    scanf(" %s", s);

    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[i - 1]) {
            cut++;
        }

        if (s[i - 1] == '0' && s[i] == '1') {
            f = 1;
        }
    }

    cut -= (f == 1);

    printf("%d\n", cut);
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