#include <stdio.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void solve()
{
    long long n, m, v, sum = 0, cake1 = 0, cake2 = 0;
    int i, j;

    scanf("%lld %lld %lld", &n, &m, &v);

    long long arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    for (i = 0, j = m; i < n; i++) {
        sum += arr[i];

        if (sum >= v) {
            sum = 0;
            j--;
        }

        if (j == 0) {
            i++;
            break;
        }
    }
    
    sum = 0;

    if (j > 0) {
        sum = -1;
    }
    else {
        for (i; i < n; i++) {
            sum += arr[i];
        }
    }

    cake1 = sum;

    // ulta
    for (i = n - 1, j = m; i >= 0; i--) {
        sum += arr[i];

        if (sum >= v) {
            sum = 0;
            j--;
        }

        if (j == 0) {
            i--;
            break;
        }
    }
    
    sum = 0;

    if (j > 0) {
        sum = -1;
    }
    else {
        for (i; i >= 0; i--) {
            sum += arr[i];
        }
    }

    cake2 = sum;

    printf("%lld\n", max(cake1, cake2));
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