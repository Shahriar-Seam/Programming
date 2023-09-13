#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (n % 3 == 0) {
        printf("It's a multiple of 3.\n");
    }
    if (n % 5 == 0) {
        printf("It's a multiple of 5.\n");
    }

    return 0;
}