#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    int n, k, i, found;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        arr = (int *) malloc(sizeof(int) * n);
        found = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n; i++) {
            if (arr[i] == k) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

        free(arr);
    }

    return 0;
}