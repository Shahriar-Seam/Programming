#include <stdio.h>

int main()
{
    int n, i, j, k;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                for (k = 0; k < n; k++) {
                    if (k != j && k != i) {
                        if (arr[i] == arr[j] + arr[k]) {
                            printf("%d %d %d\n", i + 1, j + 1, k + 1);

                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("-1");

    return 0;
}