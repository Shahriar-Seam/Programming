#include <stdio.h>

int main()
{
    int i = 0, n, sum = 0;

    while (i < 10) {
        scanf("%d", &n);

        sum = sum + n;

        i++;
    }

    printf("The sum of these numbers is: %d\n", sum);

    return 0;
}