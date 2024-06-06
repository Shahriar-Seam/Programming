#include <stdio.h>

int main()
{
    int a, b, c, d;
    int sum;

    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a == 0 && b == 0 && c == 0 && d == 0) {
            break;
        }

        sum = 0;

        sum += (40 + a - b) % 40;
        sum += (40 + c - b) % 40;
        sum += (40 + c - d) % 40;

        sum *= 9;
        sum += 1080;

        printf("%d\n", sum);
    }

    return 0;
}