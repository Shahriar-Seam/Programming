#include <stdio.h>

int main()
{
    int t, a, b;

    scanf("%d", &t);

    while (t--) {
        scanf ("%d %d", &a, &b);

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        if (2 * a > b) {
            printf("%d\n", (4 * a * a));
        }
        else {
            printf("%d\n", b * b);
        }
    }

    return 0;
}