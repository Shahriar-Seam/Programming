#include <stdio.h>

int main()
{
    int a, b;
    float result;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);

    result = (float) a / b;

    printf("%f\n", result);

    return 0;
}