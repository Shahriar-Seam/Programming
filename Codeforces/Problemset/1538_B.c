#include <stdio.h>

void solve()
{
    int n, i, sum = 0, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        sum += arr[i];
    }

    if (sum % n == 0) {
        for (i = 0; i < n; i++) {
            if (arr[i] > sum / n) {
                count++;
            }
        }
    }
    else {
        count = -1;
    }

    printf("%d\n", count);
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