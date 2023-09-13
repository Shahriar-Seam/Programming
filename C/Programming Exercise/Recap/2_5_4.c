#include <stdio.h>

int main()
{
    int x, y;
    char c;

    printf("Enter initial position: ");
    scanf("%d %d", &x, &y);

    printf("Enter command (u/d/r/l): ");
    scanf(" %c", &c);

    if (c == 'u') {
        x--;
    }
    if (c == 'd') {
        x++;
    }
    if (c == 'r') {
        y++;
    }
    if (c == 'l') {
        y--;
    }

    printf("Final position: %d %d\n", x, y);

    return 0;
}