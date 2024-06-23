#include <stdio.h>

int main()
{
    int n, i, mask, sum, f = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (mask = 0; mask < (1 << n); mask++) {
        sum = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
            else {
                sum -= arr[i];
            }
        }

        if (sum % 360 == 0) {
            f = 1;
            break;
        }
    }

    puts(f == 1 ? "YES" : "NO");

    return 0;
}