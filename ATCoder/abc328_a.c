#include <stdio.h>

int main()
{
    int n, x, sum = 0, num;

    scanf("%d %d", &n, &x);

    while (n--) {
        scanf("%d", &num);

        if (num <= x) {
            sum += num;
        }
    }

    printf("%d", sum);

    return 0;
}