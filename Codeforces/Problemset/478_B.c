#include <stdio.h>

int main()
{
    long long int n, m, max, min, temp;

    scanf("%lld %lld", &n, &m);

    temp = n - m;

    max = ((temp + 1) * (temp)) / 2;

    temp = n / m;

    min = m * ((temp) * (temp - 1)) / 2;

    min += temp * (n % m);

    printf("%lld %lld\n", min, max);

    return 0;
}