#include <stdio.h>

int find(int *arr, int n, int i, int num)
{
    if (i == n) {
        return -1;
    }
    else if (arr[i] == num) {
        return i;
    }

    find(arr, n, i + 1, num);
}

int main()
{
    int n, arr[100], i, t, num, f;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &num);

    f = find(arr, n, 0, num);

    f >= 0 ? printf("%d\n", f) : printf("Not Found\n");

    return 0;
}