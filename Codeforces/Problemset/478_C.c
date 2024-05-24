#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

typedef long long int lli;

long long int min(long long int a, long long int b)
{
  return a < b ? a : b;
}

long long int max(long long int a, long long int b)
{
  return a > b ? a : b;
}

long long int _max(int count, ...)
{
    long long int i, max_value = INT_MIN;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        max_value = max(max_value, va_arg(ptr, long long int));
    }

    va_end(ptr);

    return max_value;
}

int main()
{
    long long int a, b, c;
    long long int sum;

    scanf("%lld %lld %lld", &a, &b, &c);

    sum = 1LL * (a + b + c);

    printf("%lld\n", min(sum / 3, sum - _max(3, a, b, c)));

    return 0;
}