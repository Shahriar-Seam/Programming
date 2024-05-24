#include <stdio.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, x, l = -1, r, i, sum = 0, f = 0, temp;

    scanf("%d %d", &n, &x);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        if (temp % x != 0) {
            f = 1;

            if (l == -1) {
                l = i;
            }

            r = i;
        }

        sum += temp;
    }

    if (f == 0) {
        printf("%d\n", -1);
    }
    else if (sum % x != 0) {
        printf("%d\n", n);
    }
    else {
        printf("%d\n", _max(r, n - l - 1));
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