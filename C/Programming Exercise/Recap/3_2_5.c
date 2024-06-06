#include <stdio.h>

int main()
{
    int n;

    printf("Enter numbers 1 by 1 (Enter 0 to exit): ");

    while (1) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        else if (n % 6 == 0) {
            printf("Yes.\n");
        }
        else {
            printf("No.\n");
        }
    }

    return 0;
}