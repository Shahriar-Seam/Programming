#include <stdio.h>
#include <stdlib.h>

int xor(int *arr, int n, int index)
{
    int i, x;

    if (index == 0) {
        x = arr[1];

        for (i = 2; i < n; i++) {
            x = x ^ arr[i];
        }
    }
    
    else {
        x = arr[0];

        for (i = 1; i < n; i++) {
            if (i != index) {
                x = x ^ arr[i];
            }
        }
    }

    return x;
}

int main()
{
    int t, n, *arr, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n; i++) {
            if (arr[i] == xor(arr, n, i)) {
                printf("%d\n", arr[i]);
                break;
            }
        }

        free(arr);
    }

    return 0;
}