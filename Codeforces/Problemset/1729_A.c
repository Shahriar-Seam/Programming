#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, a, b, c, s1, s2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        s1 = a - 1;
        s2 = abs(b - c) + abs(c - 1);

        if (s1 < s2) {
            printf("1\n");
        }
        else if (s2 < s1) {
            printf("2\n");
        }
        else {
            printf("3\n");
        }
    }

    return 0;
}