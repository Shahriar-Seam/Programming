#include <stdio.h>

int main()
{
    int n, i, j, a = 1, b = 1, l = 0, r = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    if (n == 1) {
        printf("1 0\n");

        return 0;
    }

    for (i = 0, j = n - 1; a + b < n; ) {
        if (arr[i] <= arr[j]) {
            a++;
            arr[j] -= arr[i];
            i++;
        }
        else {
            b++;
            arr[i] -= arr[j];
            j--;
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}