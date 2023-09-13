#include <stdio.h>

int main()
{
    int n, h, a, khamba = 0, picchi = 0, min_wid;

    scanf("%d %d", &n, &h);

    while (n--) {
        scanf("%d", &a);

        (a > h) ? khamba++ : picchi++ ;
    }

    min_wid = khamba * 2 + picchi;

    printf("%d", min_wid);

    return 0;
}