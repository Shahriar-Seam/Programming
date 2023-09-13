#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Summation of 1st %d odd numbers is %d.", n, n * n);

    return 0;
}