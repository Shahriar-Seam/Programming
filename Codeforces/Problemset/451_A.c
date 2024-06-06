#include <stdio.h>

int main()
{
    int a, b, small;

    scanf("%d %d", &a, &b);

    (a < b) ? (small = a) : (small = b);

    (small % 2 == 0) ? printf("Malvika") : printf("Akshat");

    return 0;
}