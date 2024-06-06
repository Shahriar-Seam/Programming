#include <stdio.h>

void solve()
{
    long long int x, y, i;

    scanf("%lld %lld", &x, &y);

    if (x - y == 1) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
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