#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int arr[], int low, int high)
{
    int i, j, val;

    for (i = low + 1; i < high + 1; i++) {
        val = arr[i];

        j = i;

        while (j > low && arr[j - 1] > val) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = val;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i, j;

    for (i = j = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(arr + i, arr + j);

            j++;
        }
    }

    swap(arr + i, arr + j);

    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

void hybrid_quick_sort(int arr[], int low, int high)
{
    while (low < high) {
        if (high - low + 1 < 4) {
            insertion_sort(arr, low, high);

            break;
        }
        else {
            int pivot = partition(arr, low, high);

            if (pivot - low < high - pivot) {
                hybrid_quick_sort(arr, low, pivot - 1);

                low = pivot + 1;
            }
            else {
                hybrid_quick_sort(arr, pivot + 1, high);

                high = pivot - 1;
            }
        }
    }
}

int32_t main()
{
    int n, i, count = 0;
 
    scanf("%d", &n);
 
    int arr[n], temp[n];
 
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
 
    // merge_sort(arr, temp, 0, n - 1);
    
    hybrid_quick_sort(arr, 0, n - 1);
 
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
 
    printf("%d\n", count + 1);

    return 0;
}