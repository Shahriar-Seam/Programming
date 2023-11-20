#include <stdio.h>

int main()
{
    int arr[1000];
    int i, count = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] >= 100 && arr[i] < 1000) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}