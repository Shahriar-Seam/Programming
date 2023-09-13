#include <stdio.h>

int main()
{
    int n, i, fact = 1;

    scanf("%d", &n);

    if (n == 0) {
        printf("%d! = %d", 0, 1);
    }

    else if (n > 0) {
        for (i = 1; i <= n; i++) {
            fact *= i;
        }

        printf("%d! = %d\n", n, fact);
    }

    else {
        printf("Invalid Input.\n");
    }

    return 0;
}