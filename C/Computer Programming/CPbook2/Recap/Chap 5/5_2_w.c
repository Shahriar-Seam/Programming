#include <stdio.h>

int main()
{
    int n, x, m;

    while(1) {
        printf("Enter a number (Enter 0 to exit): ");
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        printf("How many bits do you want to shift right? ");
        scanf("%d", &x);

        m = n >> x;

        printf("Result is %d\n\n", m);
    }

    return 0;
}