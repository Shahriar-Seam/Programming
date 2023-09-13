#include <stdio.h>

int main()
{
    int i, n, sum = 0;
    float average;

    printf("Enter age of 10 people:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &n);
        sum += n;
    }

    average = sum / 10.0;

    printf("Their average age is: %.2f", average);

    return 0;
}