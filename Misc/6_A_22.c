#include <stdio.h>

int _sum(int *arr, int i, int n)
{
    if (i == n) {
        return 0;
    }
    else if (arr[i] % 7 == 0) {
        return arr[i] + _sum(arr, i + 1, n);
    }
    else {
        return _sum(arr, i + 1, n);
    }
}

int main()
{
    int arr[1000];
    int i, sum;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    sum = _sum(arr, 0, 10);

    printf("%d\n", sum);

    return 0;
}