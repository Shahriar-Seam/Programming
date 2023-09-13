#include <stdio.h>

int main()
{
    int n, i, sum = 0, count;

    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        sum += i * (i + 1) / 2;

        if (sum > n) {
            count = i - 1;
            break;
        }
        else if (sum == n) {
            count = i;
            break;
        }
    }

    if (n == 1) {
        printf("1");
    }
    else {
        printf("%d", count);
    }

    return 0;
}