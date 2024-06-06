#include <stdio.h>
#include <stdlib.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int yas(int *arr, int n)
{
    int i, even = 0, odd = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even += arr[i];
        }
        else {
            odd += arr[i];
        }
    }

    if (even > odd) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int t, n, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        yas(arr, n) ? yes : no;

        free(arr);
    }

    return 0;
}