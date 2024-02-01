#include <stdio.h>
#include <math.h>

void solve()
{
    int a, b, sum_or = 0;

    scanf("%d %d", &a, &b);

    if ((int) ceil(log2((double) a)) != (int) ceil(log2((double) b))) {
        sum_or = 1 << (int) ceil(log2((double) b));

        printf("%d\n", sum_or - 1);
    }
    else {
        puts("NO");
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }
}