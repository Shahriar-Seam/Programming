#include <stdio.h>
#include <math.h>

void solve()
{
    int l, r;

    scanf("%d %d", &l, &r);

    printf("%d\n", (int) log2(r));
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