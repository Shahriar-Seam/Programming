#include <stdio.h>

int main()
{
    long long n, sum = 0, i;

    scanf("%lld", &n);

    long long arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("%lld\n", sum < 0 ? -sum : sum);

    return 0;
}