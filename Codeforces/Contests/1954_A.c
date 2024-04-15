#include <stdio.h>

#define yes puts("YES")
#define no puts("NO")

void solve()
{
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    if (n == 1 || m == 1) {
        no;
    }
    else if (k >= n) {
        no;
    }
    else {
        yes;
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