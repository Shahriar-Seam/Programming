#include <stdio.h>

int main()
{
    int t;
    int n, i, flag;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];
        int arr2[n + 1];
        flag = 0;

        for (i = 0; i <= n; i++) {
            arr2[i] = 0;
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            arr2[arr[i]]++;
        }

        for (i = 0; i <= n; i++) {
            if (arr2[i] >= 3) {
                printf("%d\n", i);
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("-1\n");
        }
    }

    return 0;
}