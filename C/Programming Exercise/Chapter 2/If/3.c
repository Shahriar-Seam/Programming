#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a == b) {
        printf("The pin codes are equal.\n");
    }
    if (a != b) {
        printf("The pin codes are not equal.\n");
    }

    return 0;
}