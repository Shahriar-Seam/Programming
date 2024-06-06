#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Weeks = %d", n / 7);

    return 0;
}