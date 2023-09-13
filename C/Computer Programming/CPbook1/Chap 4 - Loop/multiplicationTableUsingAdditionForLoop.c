#include <stdio.h>

int main()
{
    int m = 0, n, i = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i; i <= 10; i++) {
        m = m + n;
        printf("%d * %d = %d\n", n, i, m);
    }

    return 0;
}