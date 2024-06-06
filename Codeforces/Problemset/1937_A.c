#include <stdio.h>
#include <math.h>

#define _ __(a, n, i, m, a, t, e)
#define __(n, e, u, t, r, a, l) t##r##u##e

_()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        printf("%d\n", 1 << (int) (log2(n)));
    }
}