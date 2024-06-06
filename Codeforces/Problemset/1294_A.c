#include <stdio.h>

int main()
{
    int t;
    int a, b, c, n, sum, max, i, temp, diff;

    scanf("%d", &t);

    while (t--) {
        max = 0;

        scanf("%d %d %d %d", &a, &b, &c, &n);

        if (a > b) {
            temp = b;
            b = a;
            a = temp;
        }
        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }
        if (a > b) {
            temp = b;
            b = a;
            a = temp;
        }

        diff = (c - a) + (c - b);

        sum = a + b + c + n;

        if ((sum % 3 == 0) && (diff <= n)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}