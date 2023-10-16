#include <stdio.h>

int main()
{
    int t, a, b, s;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &a, &b);

        if (a == 0) {
            printf("1\n");
            continue;
        }
        else {
            s = a + 2 * b + 1;

            printf("%d\n", s);
        }
    }

    return 0;
}