#include <stdio.h>

#define int long long

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

int main()
{
    int n, d, i, count = 0, temp;

    scanf("%lld %lld", &n, &d);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    for (i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            temp = ceil_div(arr[i - 1] + 1 - arr[i], d);

            arr[i] += temp * d;

            count += temp;
        }
    }

    printf("%lld\n", count);

    return 0;
}