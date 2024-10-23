#include <stdio.h>

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, i, j, sum = 0;

        scanf("%d", &n);

        int arr[n + 1];

        for (i = 0; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[i]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (arr[i] <= 2 * arr[n] && arr[i] > arr[n]) {
                int temp = arr[i];
                arr[i] = arr[n];
                arr[n] = temp;
            }
        }

        for (i = 0; i < n; i++) {
            sum += arr[i];
        }

        printf("%d\n", sum);
    }

    return 0;
}