#include <stdio.h>

int main()
{
    int t;
    int l, r;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &l, &r);

        if ((l * 2 <= r)) {
            printf("%d %d\n", l, 2 * l);
        }
        else {
            printf("-1 -1\n");
        }
    }
    

    return 0;
}