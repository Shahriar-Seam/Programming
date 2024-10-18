#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, i, a_win = 0, draw = 0, b_win = 0;

    scanf("%d %d", &a, &b);

    for (i = 1; i <= 6; i++) {
        if (abs(a - i) < abs(b - i)) {
            a_win++;
        }
        else if (abs(a - i) > abs(b - i)) {
            b_win++;
        }
        else {
            draw++;
        }
    }

    printf("%d %d %d\n", a_win, draw, b_win);

    return 0;
}