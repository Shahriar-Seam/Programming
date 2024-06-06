#include <stdio.h>

int main()
{
    int t, h, m, rem_m;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &h, &m);

        rem_m = 1440 - ((h * 60) + m);

        printf("%d\n", rem_m);
    }

    return 0;
}