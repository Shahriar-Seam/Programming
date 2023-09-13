#include <stdio.h>

double find_average(int arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (double) arr[i];
    }

    double average = sum / n;

    return average;
}

int main()
{
    int arr[] = {
        45, 54, 654, 432, 132, 547, 87, 78, 98, 23, 514, 125, 721 
    };
    int n = 13;

    double average = find_average(arr, n);

    printf("Average = %.2lf\n", average);

    return 0;
}