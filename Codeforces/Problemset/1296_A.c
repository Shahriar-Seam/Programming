#include <stdio.h>

int _count(int arr[], int n)
{
    int i, count_odd = 0, count_even = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count_even++;
        }
        else {
            count_odd++;
        }

        if (count_even && count_odd) {
            break;
        }
    }

    if (count_even && count_odd) {
        return 1;
    }
    else {
        return 0;
    }
}

int _sum(int arr[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int t, i, sum, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        sum = _sum(arr, n);

        if (sum % 2 == 1) {
            printf("YES\n");
        }
        else if (_count(arr, n)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}