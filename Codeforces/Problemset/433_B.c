#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int main()
{
    int n, m, i, type, l, r;

    scanf("%d", &n);

    int arr1[n];
    int arr2[n];
    long long int arr3[n + 1];
    long long int arr4[n + 1];

    for (i = 0; i < n; i++) {
        arr3[i] = arr4[i] = 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", arr1 + i);

        arr2[i] = arr1[i];
    }

    qsort(arr2, n, sizeof(int), compare);

    for (i = 1; i <= n; i++) {
        arr3[i] = arr1[i - 1] + arr3[i - 1];
        arr4[i] = arr2[i - 1] + arr4[i - 1];
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &type, &l, &r);

        if (type == 1) {
            printf("%lld\n", arr3[r] - arr3[l - 1]);
        }
        else {
            printf("%lld\n", arr4[r] - arr4[l - 1]);
        }
    }

    return 0;
}