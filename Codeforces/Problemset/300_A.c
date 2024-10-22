#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j = 0, k = 0, l = 0;
    int temp, f = 0;

    scanf("%d", &n);

    int a[1], b[n], c[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        if (temp < 0 && j == 0) {
            a[j++] = temp;
        }
        else if (temp <= 0) {
            c[l++] = temp;
        }
        else {
            b[k++] = temp;
        }
    }

    if (k == 0) {
        f = 2;

        for (i = 0; k < 2 && i < l; i++) {
            if (c[i] < 0) {
                b[k++] = c[i];

                c[i] = INT_MAX;
            }
        }
    }

    printf("%d ", j);
    for (i = 0; i < j; i++) {
        printf("%d ", a[i]);
    }

    printf("\n%d ", k);
    for (i = 0; i < k; i++) {
        printf("%d ", b[i]);
    }

    printf("\n%d ", l - f);
    for (i = 0; i < l; i++) {
        if (c[i] != INT_MAX) {
            printf("%d ", c[i]);
        }
    }

    return 0;
}