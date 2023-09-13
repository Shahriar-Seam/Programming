#include <stdio.h>

int main()
{
    int x, y;
    char c;

    printf("Enter initial position: ");
    scanf("%d %d", &x, &y);

    while (1) {
        scanf("%c", &c);

        if (c == 'S') {
            break;
        }
        if (c == 'U') {
            x--;
        }
        if (c == 'D') {
            x++;
        }
        if (c == 'L') {
            y--;
        }
        if (c == 'R') {
            y++;
        }
    }

    printf("Final position: %d %d", x, y);

    return 0;    
}