#include <stdio.h>

int main()
{
    int n, c, pre, cur, count = 0;

    scanf("%d %d %d", &n, &c, &pre);

    n--;

    while (n--) {
        scanf("%d", &cur);

        if (cur - pre > c) {
            count = 0;
        }
        else {
            count++;
        }

        pre = cur;
    }

    printf("%d\n", count + 1);

    return 0;
}