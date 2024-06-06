#include <stdio.h>

double FindOddAverage(int *arr)
{
    int i, sum = 0, count = 0;

    for (i = 0; i < 10; i++) {
        if (arr[i] % 2 == 1) {
            sum += arr[i];
            count++;
        }
    }

    return (double) sum / count;
}

int main()
{
    int arr[1000] = {0};
    int i;
    
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%g\n", FindOddAverage(arr));

    return 0;
}