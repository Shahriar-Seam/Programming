#include <stdio.h>

void solve()
{
    int n, a, b, i, j;
    int x = 0, y = 0, f = 0;
    char s[50], c;

    scanf("%d %d %d %s", &n, &a, &b, s);

    for (i = 0, j = 0; j < 5000; i = (i + 1) % n, j++) {
        c = s[i];

        switch (c)
        {
        case 'N':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        }

        if (a == x && b == y) {
            f = 1;
            break;
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