#include <stdio.h>

int main()
{
    int n;

    while (1) {
        printf("Enter a number (Enter 0 to exit): ");
        scanf("%d", &n);

        if (n == 0) {
            break;
        }
        
        printf("Quotient after dividing by 6 = %d\n", n % 6);
    }

    return 0;
}