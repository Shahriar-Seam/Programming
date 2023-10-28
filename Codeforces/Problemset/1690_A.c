#include <stdio.h>

int main()
{
    int t, n, i;
    int a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n == 7) {
            a = 4;
            b = 2;
            c = 1;
        }
        else if (n % 3 == 0) {
            a = (n / 3) + 1;
            b = n / 3;
            c = (n / 3) - 1;
        }
        else if (n % 3 == 1) {
            a = (n / 3) + 2;
            b = (n / 3) + 1;
            c = (n / 3) - 2;
        }
        else {
            a = (n / 3) + 2;
            b = (n / 3) + 1;
            c = (n / 3) - 1;
        }

        printf("%d %d %d\n", b, a, c);
    }

    return 0;
}