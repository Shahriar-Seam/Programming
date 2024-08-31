#include <stdio.h>

int _max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    long long n, m, l, r, max = 0, temp;
    char op;

    scanf("%lld %lld", &n, &m);

    while (n--) {
        scanf("%lld", &temp);

        max = _max(max, temp);
    }

    while (m--) {
        scanf(" %c %lld %lld", &op, &l, &r);

        if (l <= max && max <= r) {
            if (op == '+') {
                max++;
            }
            else {
                max--;
            }
        }

        printf("%lld ", max);
    }

    printf("\n");
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