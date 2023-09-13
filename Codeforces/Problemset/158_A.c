#include <stdio.h>

int main()
{
    int n, k, a, i, count = 0;

    scanf("%d %d", &n, &k);

    if (n >= k && 1 <= k && 1 <= n && k <= 50 && n <= 50) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a);

            if (a > k) {
                count++;
            }
        }

        printf("%d", count);
    }

    return 0;
}