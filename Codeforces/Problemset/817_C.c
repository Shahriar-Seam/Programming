#include <stdio.h>
#include <ctype.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

long long digit_sum(long long n)
{
    long long sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    long long n, s, x = __LONG_LONG_MAX__;
    long long low, high, mid;

    scanf("%lld %lld", &n, &s);

    low = 1;
    high = n;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (mid - digit_sum(mid) >= s) {
            x = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("%lld\n", max(0LL, n - x + 1));

    return 0;
}