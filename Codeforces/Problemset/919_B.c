#include <stdio.h>

int digit_sum(int n)
{
    int sum = 0;

    while (n > 0) {
        sum += n % 10;

        n /= 10;
    }

    return sum;
}

int main()
{
    int n, i = 0, p = 0;

    scanf("%d", &n);

    while (i != n) {
        p++;

        if (digit_sum(p) == 10) {
            i++;
        }
    }

    printf("%d", p);

    return 0;
}