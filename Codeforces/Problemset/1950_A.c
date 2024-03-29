#include <stdio.h>

int main()
{
    int t, a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        if (a < b && b < c) {
            puts("STAIR");
        }
        else if (a < b && b > c) {
            puts("PEAK");
        }
        else {
            puts("NONE");
        }
    }

    return 0;
}