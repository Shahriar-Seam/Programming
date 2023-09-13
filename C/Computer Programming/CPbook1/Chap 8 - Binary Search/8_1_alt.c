#include <stdio.h>

int b_search(int arr[], int low, int high, int key)
{
    int mid, found = 0;
    while (low <= high) {
        mid = (low + high) / 2;

        if (key == arr[mid]) {
            found = 1;
            break;
        }

        if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return found;    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int low_index = 0, high_index = 9;
    int num;

    scanf("%d", &num);

    int found = b_search(arr, low_index, high_index, num);

    if (found) {
        printf("The number is in the array.\n");
    }
    else {
        printf("The number is not in the array.\n");
    }

    return 0;
}