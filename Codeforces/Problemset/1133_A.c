#include <stdio.h>
#include <string.h>

int main()
{
    char t1[6], t2[6];
    int h1, h2, m1, m2, mid_h, mid_m, t;

    scanf("%s %s", t1, t2);

    sscanf(t1, "%d:%d", &h1, &m1);
    sscanf(t2, "%d:%d", &h2, &m2);

    t = (h1 * 60 + m1 + h2 * 60 + m2) / 2;

    mid_h = t / 60;
    mid_m = t % 60;

    if (mid_h < 10) {
        printf("0%d:", mid_h);
    }
    else {
        printf("%d:", mid_h);
    }

    if (mid_m < 10) {
        printf("0%d", mid_m);
    }
    else {
        printf("%d", mid_m);
    }

    return 0;
}