#include <stdio.h>

int main()
{
    int arr1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr2[10];
    int i;

    for (i = 0; i < 10; i++) {
        arr2[i] = arr1[9 - i];
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr2[i]);
    }

    return 0;
}