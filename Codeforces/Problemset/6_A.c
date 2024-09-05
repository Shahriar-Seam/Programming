#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int main()
{
    int arr[4];
    int i;

    for (i = 0; i < 4; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, 4, sizeof(int), compare);

    if (arr[0] + arr[1] > arr[2] || arr[1] + arr[2] > arr[3]) {
        printf("TRIANGLE");
    }
    else if (arr[0] + arr[1] < arr[2] && arr[1] + arr[2] < arr[3]) {
        printf("IMPOSSIBLE");
    }
    else {
        printf("SEGMENT");
    }

    return 0;
}