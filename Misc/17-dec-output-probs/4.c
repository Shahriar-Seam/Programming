#include <stdio.h>

void func(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i, j, arr[] = {1, 8, 2, 4, 3, 5, 9, 7, 6};

    for (i = 0; i < 8; i++) {
        if (arr[i] < arr[i + 1]) {
            func(arr + i, arr + i + 1);
        }
    }

    for (i = 0; i < 9; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\n-------------------------------\n");

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (arr[i] > arr[j]) {
                func(arr + i, arr + j);
            }
        }
    }
    
    for (i = 0; i < 9; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}