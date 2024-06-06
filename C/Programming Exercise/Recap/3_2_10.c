#include <stdio.h>

int main()
{
    int n, count = 0;

    scanf("%d", &n);

    while (1) {
        if (n == 1) {
            break;
        }

        else if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3 * n + 1;
        }

        printf("%d\n", n);

        count++;
    }

    printf("Total Cycle: %d\n", count);
    
    return 0;
}