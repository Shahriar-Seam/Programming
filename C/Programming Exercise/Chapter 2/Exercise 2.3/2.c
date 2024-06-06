#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (1 <= n && n <= 6) {
            if (n % 2 == 0) {
            printf("Even.\n");
        }
        else {
            printf("Odd\n");
        }
    }
    else {
        printf("Not a number between 1 and 6.\n");
    }

    return 0;
}