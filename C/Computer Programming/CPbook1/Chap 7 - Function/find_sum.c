#include <stdio.h>

int find_sum(int arr[], int n)
{
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {
        12, 456, 654, 123, 987, 485, 4, 231, 45
    };
    int n = 9;

    printf("%d\n", arr[8]);
    int s = find_sum(arr, n);

    printf("%d\n", s);

    return 0;
}