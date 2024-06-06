#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, temp, i, max_cnt = 0;
    int arr[100005] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        arr[temp]++;

        max_cnt = max(max_cnt, arr[temp]);
    }

    printf("%d", max(ceil(n / 2.0), max_cnt));

    return 0;
}