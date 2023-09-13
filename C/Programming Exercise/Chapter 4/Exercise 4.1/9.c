#include <stdio.h>

void sort(int arr[], int n)
{
    int i, j, temp;

    for (j = n - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

double median_of_array(int arr[], int n)
{
    double median;

    if (n % 2 == 0) {
        median = (double) (arr[n / 2] + arr[(n / 2) - 1]) / 2;
    }

    else {
        median = arr[n / 2];
    }

    return median;
}

int main()
{
    int n, i;
    double median;

    scanf("%d", &n);

    int data[n];

    // for (i = 0; i < n; i++) {
    //     scanf("%d", &data[i]);
    // }

    for (i = 0; i < 1000; i++) {
        data[i] = i + 1;
    }

    sort(data, n);

    median = median_of_array(data, n);

    printf("Median = %g", median);

    return 0;
}