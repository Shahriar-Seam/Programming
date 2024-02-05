#include <stdio.h>

int main()
{
    int t, x, y, x1, y1;

    while (1) {
        scanf("%d", &t);

        if (t == 0) {
            break;
        }

        scanf("%d %d", &x, &y);

        while (t--) {
            scanf("%d %d", &x1, &y1);

            if (x1 == x || y1 == y) {
                puts("divisa");
            }
            else if (x1 > x && y1 > y) {
                puts("NE");
            }
            else if (x1 < x && y1 > y) {
                puts("NO");
            }
            else if (x1 < x && y1 < y) {
                puts("SO");
            }
            else {
                puts("SE");
            }
        }
    }

    return 0;
}