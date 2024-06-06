#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    while (n != 1) {
        printf("%d ", n);

        n = (n % 2 == 0) ? n / 2 : (3 * n) + 1;
    }

    puts("1");

    return 0;
}