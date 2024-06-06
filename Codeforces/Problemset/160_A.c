#include <stdio.h>

int find_sum(int arr[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int _max(int arr[], int n)
{
    int i, max = 0, index;

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    arr[index] = 0;

    return max;
}

int main()
{
    int n, i, sum = 0, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        sum += _max(arr, n);
        
        count++;

        if (sum > find_sum(arr, n)) {
            break;
        }
    }

    printf("%d", count);

    return 0;
}