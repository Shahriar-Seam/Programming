#include <stdio.h>

int x = 1;

void my_fnc(int y)
{
    y = y * 2;
    x = x + 10;
    printf("my_fnc, x = %d, y = %d\n", x, y);
}

int main()
{
    int y = 5;

    x = 10;

    my_fnc(y);

    printf("main, x = %d, y = %d\n", x, y);

    return 0;
}