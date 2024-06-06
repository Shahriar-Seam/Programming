#include <stdio.h>

int digit_sum(int n)
{
    int sum = 0;

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int t, x, k, y;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &x, &k);

        for (y = x; ; y++) {
            if (digit_sum(y) % k == 0) {
                break;
            }
        }

        printf("%d\n", y);
    }

    return 0;
}