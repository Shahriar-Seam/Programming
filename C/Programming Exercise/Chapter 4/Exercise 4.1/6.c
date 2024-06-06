#include <stdio.h>

int main()
{
    int arr[10];
    int i, sum1 = 0, sum10 = 0, sum100 = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        sum1 += arr[i] % 10;
    }
    for (i = 0; i < 10; i++) {
        sum10 += (arr[i] / 10) % 10;
    }
    for (i = 0; i < 10; i++) {
        sum100 += (arr[i] / 100) % 10;
    }

    printf("\nEkok: %d\nDoshok: %d\nShotok: %d\n", sum1, sum10, sum100);

    return 0;
}