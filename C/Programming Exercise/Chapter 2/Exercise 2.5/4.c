#include <stdio.h>

int main()
{
    int row, column;
    char ch;

    printf("Enter position (row column): ");
    scanf("%d %d", &row, &column);
    printf("Enter a character (u/d/r/l): ");
    scanf(" %c", &ch); //Thanks ChatGPT

    if (ch == 'u') {
        row = row - 1;
    }
    if (ch == 'd') {
        row = row + 1;
    }
    if (ch == 'r') {
        column = column + 1;
    }
    if (ch == 'l') {
        column = column - 1;
    }

    printf("\nNew position %d, %d\n", row, column);

    return 0;
}