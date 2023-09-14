#include <stdio.h>

int main()
{
    int a, b, i, sum = 0;

    scanf("%d %d", &a, &b);

    for (i = a; i <= b; i++) {
        if ((i % 35 == 0) && (i % 2 != 0)) {
            sum += i;
        }
    }

    printf("Sum = %d\n", sum);

    return 0;
}