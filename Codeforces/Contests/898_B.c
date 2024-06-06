#include <stdio.h>

int find_max_product(int arr[], int n)
{
    int i, min = arr[0], m_index = 0, product = 1;

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            m_index = i;
        }
    }

    arr[m_index]++;

    for (i = 0; i < n; i++) {
        product *= arr[i];
    }

    return product;
}

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", find_max_product(arr, n));
    }

    return 0;
}