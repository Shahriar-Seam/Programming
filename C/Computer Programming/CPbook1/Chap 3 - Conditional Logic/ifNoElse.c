#include <stdio.h>

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n > 10) {
        printf("The number is greater than Ten!\n");
    }

    return 0;
}