#include <stdio.h>

int main()
{
    int t, x, k, n1, n2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &x, &k);

        if (x % k != 0) {
            printf("1\n");
            printf("%d\n", x);
        }
        else {
            n1 = x - k + 1;
            n2 = x - n1;

            printf("%d\n", 2);
            printf("%d %d\n", n1, n2);
        }
    }

    return 0;
}