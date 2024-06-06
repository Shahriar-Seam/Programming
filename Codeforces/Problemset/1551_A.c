#include <stdio.h>

int main()
{
    int t, n, c1, c2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 3 == 0) {
            c1 = c2 = n / 3;
        }
        else if (n % 3 == 1) {
            c2 = n / 3;
            c1 = c2 + 1;
        }
        else {
            c1 = n / 3;
            c2 = c1 + 1;
        }

        printf("%d %d\n", c1, c2);
    }

    return 0;
}