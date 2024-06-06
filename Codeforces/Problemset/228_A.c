#include <stdio.h>
#include <stdbool.h>

void sort(int arr[])
{
    int i, j, temp;
    bool swapped;

    for (i = 0; i < 3; i++) {
        swapped = false;

        for (j = 0; j < 3 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int _count(int arr[])
{
    int i, count = 0;

    for (i = 0; i < 3; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        }
    }

    return count;
}

int main()
{
    int i, arr[4];

    for (i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr);

    printf("%d", _count(arr));

    return 0;
}