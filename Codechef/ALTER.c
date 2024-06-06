#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int a, b, p, q, bla;

    scanf("%d %d %d %d", &a, &b, &p, &q);

    bla = (p / a) - (q / b);

    if (p % a == 0 && q % b == 0) {
        if (bla == 0 || bla == 1 || bla == -1) {
            puts("YES");
        }
        else {
            puts("NO");
        }
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

    return 0;
}