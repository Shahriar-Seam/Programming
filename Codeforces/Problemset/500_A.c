#include <stdio.h>

int main()
{
    int n, t, i, sum = 1, f = 0;

    scanf("%d %d", &n, &t);

    int arr[n + 1];

    for (i = 1; i < n; i++) {
        scanf("%d", arr + i);
    }

    while (1) {
        sum += arr[sum];

        if (sum == t) {
            f = 1;

            break;
        }
        if (sum > n) {
            f = 0;
            
            break;
        }
    }

    puts(f ? "YES" : "NO");

    return 0;
}