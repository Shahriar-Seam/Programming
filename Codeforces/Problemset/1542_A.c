#include <stdio.h>

int count(int arr[], int n)
{
    int count_even = 0, count_odd = 0, i;

    for (i = 0; i < n; i++) {
        (arr[i] % 2 == 0) ? count_even++ : count_odd++;
    }

    if (count_even == count_odd) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int num = 2 * n;

        int arr[num];

        for (i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }

        if (count(arr, num)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}