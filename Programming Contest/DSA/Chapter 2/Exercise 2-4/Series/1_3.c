#include <stdio.h>

long long int power(long long int n, long long int i)
{
    long long int j, num = 1;

    for (j = 0; j < i; j++) {
        num *= n;
    }

    return num;
}

int main()
{
    long long int n, i, sum = 0;

    scanf("%lld", &n);

    for (i = 1; i <= n; i++) {
        sum += power(i, i);
    }

    printf("%lld\n", sum);

    return 0;
}