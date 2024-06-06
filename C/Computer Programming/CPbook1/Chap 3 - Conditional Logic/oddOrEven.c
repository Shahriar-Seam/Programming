#include <stdio.h>

int main()
{
    int n, r;

    printf("Enter a number: ");
    scanf("%d", &n);

    r = n % 2;

    if (r == 0) {
        printf("The number is an even number.\n");
    }
    else if (r == 1) {
        printf("The number is an odd number.\n");
    }

    return 0;
}