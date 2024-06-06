#include <stdio.h>

int main()
{
    int arr[] = {
        1, 4, 6, 8, 9, 11, 14, 15, 20, 25, 33, 83, 87, 97, 99, 100
    };
    int low_index = 0, high_index = 15, mid_index;
    int num;

    scanf("%d", &num);

    while (low_index <= high_index) {
        mid_index = (low_index + high_index) / 2;

        if (num == arr[mid_index]) {
            break;
        }

        if (num < arr[mid_index]) {
            high_index = mid_index - 1;
        }

        else {
            low_index = mid_index + 1;
        }
    }
        
    if (low_index > high_index) {
        printf("%d is not in the array.\n", num);
    }

    else {
    printf("%d is found in the array.\nIt is %dth element of the array.\n", arr[mid_index], mid_index);
    }

    return 0;    
}