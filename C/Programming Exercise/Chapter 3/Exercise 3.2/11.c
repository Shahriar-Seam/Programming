#include <stdio.h>

int main()
{
    int n, num, count = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);

        if (num % 3 == 0) {
            count += 1;
        }
    }

    printf("Number of numbers divisible by 3 is %d.\n", count);

    return 0;
}