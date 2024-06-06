#include <stdio.h>

int main()
{
    int arr[6];
    int i, count = 0;

    printf("Enter amount: \n");

    for (i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] >= 1000000) {
            count++;
        }
    }

    printf("Number of millionaires: %d\n", count);

    return 0;
}