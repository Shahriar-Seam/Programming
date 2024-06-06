/**
 *    author:  Anonymous_HF
 *    created: 19/05/2024 11:38:14
**/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

void solve()
{
    int n, i, j, n_index;

    scanf("%d", &n);

    int arr[n + 1];
    int qrr[n];
    int indices[n + 1];
    int odd[n / 2];
    int even[n / 2];

    for (i = 0; i < n; i++) {
        qrr[i] = 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        indices[arr[i]] = i;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == n) {
            n_index = i;

            break;
        }
    }

    if (n_index % 2 == 1) {
        for (i = 1, j = 0; i < n; i += 2) {
            odd[j++] = arr[i];
        }

        qsort(odd, n / 2, sizeof(int), compare);

        for (i = 0; i < n / 2; i++) {
            qrr[indices[odd[i]]] = n - i;
        }

        for (i = 0, j = 0; i < n; i += 2) {
            even[j++] = arr[i];
        }

        qsort(even, n / 2, sizeof(int), compare);

        for (i = 0; i < n / 2; i++) {
            qrr[indices[even[i]]] = n / 2 - i;
        }
    }
    else {
        for (i = 0, j = 0; i < n; i += 2) {
            even[j++] = arr[i];
        }

        qsort(even, n / 2, sizeof(int), compare);

        for (i = 0; i < n / 2; i++) {
            qrr[indices[even[i]]] = n - i;
        }

        for (i = 1, j = 0; i < n; i += 2) {
            odd[j++] = arr[i];
        }

        qsort(odd, n / 2, sizeof(int), compare);

        for (i = 0; i < n / 2; i++) {
            qrr[indices[odd[i]]] = n / 2 - i;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", qrr[i]);
    }

    printf("\n");
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