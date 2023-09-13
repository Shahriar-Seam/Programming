#include <stdio.h>

int main()
{
    int n;
    int i, j, temp;

    printf("Enter number of numbers: ");
    scanf("%d", &n);

    int numbers[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (j = n - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (numbers[i] > numbers[i + 1]) {
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}