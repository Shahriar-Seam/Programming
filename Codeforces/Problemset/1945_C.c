#include <stdio.h>
#include <math.h>

void solve()
{
    int n, i, zero = 0;

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 0; s[i] != 0; i++) {
        if (s[i] == '0') {
            zero++;
        }

        if (ceil(i / 2.0) <= zero) {
            printf("%d\n", zero);
            return;
        }
    }
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