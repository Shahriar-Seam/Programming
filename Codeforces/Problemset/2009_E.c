#include <stdio.h>

#define LONG_LONG_MAX 9223372036854775807ll

long long min(long long a, long long b)
{
  return a < b ? a : b;
}

long long diff(long long n)
{
    return n < 0 ? -n : n;
}

void solve()
{
    long long l, r, mid;
    long long a, b, x = LONG_LONG_MAX;
    long long sum_mid, sum_left, sum_right;

    scanf("%lld %lld", &r, &l);

    r += l - 1;

    a = (l * (l - 1)) / 2;
    b = (r * (r + 1)) / 2;

    while (l <= r) {
        mid = l + (r - l) / 2;

        sum_mid = (mid * (mid + 1)) / 2;
        sum_left = sum_mid - a;
        sum_right = b - sum_mid;

        x = min(x, diff(sum_left - sum_right));

        if (sum_left < sum_right) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    printf("%lld\n", x);
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