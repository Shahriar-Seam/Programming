#include <stdio.h>

int main()
{
    int t, s, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &s);

        b = (s % 9 == 0) ? (int) (s / 0.9) - 1 : (int) (s / 0.9);

        printf("%d\n", b);
    }

    return 0;
}