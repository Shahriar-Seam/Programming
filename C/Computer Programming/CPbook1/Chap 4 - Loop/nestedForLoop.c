#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= 10; i++) {
            printf("%d * %d = %d\n", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}