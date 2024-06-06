#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, temp;

    for (i = 0; i < 5; i++) {
        temp = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = temp;
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}