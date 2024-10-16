#include <stdio.h>

int main()
{
    int n, m, k, i, temp, count = 0, pop;

    scanf("%d %d %d", &n, &m, &k);

    int arr[m + 1];

    for (i = 0; i <= m; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < m; i++) {
        temp = arr[i] ^ arr[m];
        pop = 0;

        while (temp > 0) {
            pop += temp % 2;

            temp /= 2;
        }

        count += (pop <= k);
    }

    printf("%d\n", count);

    return 0;
}