#include <stdio.h>

int main()
{
    int a = 9, b = 10, c = 30, d = 0;

    c = a / (b * 1) + (a + 5.7) / b + (++c) / 4;

    printf("%d", c);

    return 0;
}

/*

    a = 9, b = 10, c = 30;
    a / (b * 1) = 9 / 10 = 0;

    (a + 5.7) / b = (9 + 5.7) / 10 = 14.7 / 10 = 1.47 = 1 (as it is being assigned to a integer)

    (++c) / 4 = 31 / 4 = 7;

    a / (b * 1) + (a + 5.7) / b + (++c) / 4
    = 0 + 1 + 7
    = 8 (ans.)

*/