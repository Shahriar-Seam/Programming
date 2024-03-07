#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if ((a + b + c) % 9 != 0) {
        puts("NO");
    }
    else if (min(a, min(b, c)) < (a + b + c) / 9) {
        puts("NO");
    }
    else {
        puts("YES");
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