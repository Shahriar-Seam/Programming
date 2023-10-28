#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, a, b, c, d, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        d = n % 10;
        c = (n / 10) % 10;
        b = (n / 100) % 10;
        a = n / 1000;

        count = 0;

        if (a != 0) {
            count += a;
        }
        else {
            a = 10;
            count += 10;
        }
        if (b != 0) {
            count += abs(b - a) + 1;
        }
        else {
            b = 10;
            if (b != a) {
                count += 10 - a + 1;
            }
            else {
                count++;
            }
        }
        if (c != 0) {
            count += abs(c - b) + 1;
        }
        else {
            c = 10;
            if (b != c) {
                count += 10 - b + 1;
            }
            else {
                count++;
            }
        }
        if (d != 0) {
            count += abs(d - c) + 1;
        }
        else {
            d = 10;
            if (c != d) {
                count += 10 - c + 1;
            }
            else {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}