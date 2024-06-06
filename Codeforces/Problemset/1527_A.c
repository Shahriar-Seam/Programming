#include <stdio.h>

void sieve(int *arr)
{
    int size = 32, i;

    for (i = 0; i < size; i++) {
        arr[i] = (1 << i) - 1;
    }
}

int main()
{
    int t, n, k, i;
    int arr[32];

    sieve(arr);

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n == 1) {
            printf("0\n");
            continue;
        }

        else if (n == 2) {
            printf("1\n");
            continue;
        }

        for (i = 0; i < n; i++) {
            if (arr[i] >= n) {
                k = arr[i - 1];
                break;
            }
        }

        printf("%d\n", k);
    }

    return 0;
}