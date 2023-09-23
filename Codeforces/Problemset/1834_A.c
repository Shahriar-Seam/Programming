#include <stdio.h>
#include <math.h>

int main()
{
    int t, n, i, m, p;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];
        p = 0;
        m = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            if (arr[i] == -1) {
                m++;
            }
            else {
                p++;
            }
        }

        if (n >= m * 2) {
            printf("%d\n", (m % 2 == 1));
        }
        else {
            printf("%d\n", m - (n / 2) + ((n / 2) % 2 == 1));
        }
    }

    return 0;
}