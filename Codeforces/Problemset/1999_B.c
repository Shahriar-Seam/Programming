#include <stdio.h>

int play(int a, int b)
{
    return a > b ? 1 : (a == b ? 0 : -1);
}

void solve()
{
    int a1, a2, b1, b2;
    int win = 0;

    scanf("%d %d %d %d", &a1, &a2, &b1, &b2);

    win += (play(a1, b1) + play(a2, b2) > 0);
    win += (play(a1, b2) + play(a2, b1) > 0);
    win += (play(a2, b1) + play(a1, b2) > 0);
    win += (play(a2, b2) + play(a1, b1) > 0);

    printf("%d\n", win);
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