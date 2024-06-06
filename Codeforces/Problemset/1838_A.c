#include <stdio.h>

int _max(int arr[], int n)
{
    int max = arr[0];
    int i;

    for (i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];
        int i, flag = 1, index = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            if (arr[i] < 0) {
                flag = 0;
                index = i;
            }
        }

        if (flag == 0) {
            printf("%d\n", arr[index]);
        }
        else {
            printf("%d\n", _max(arr, n));
        }
    }

    return 0;
}