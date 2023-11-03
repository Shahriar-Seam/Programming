#include <stdio.h>

int main()
{
    long long int t, a, b, k, ans;

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &k);

        ans = (k / 2) * (a - b);

        if (k % 2 == 1) {
            ans += a;
        }

        printf("%lld\n", ans);
    }

    return 0;
}