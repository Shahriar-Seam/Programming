#include <stdio.h>

int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    char ch;

    printf("Enter a character: ");
    ch = getchar();

    if (is_digit(ch)) {
        printf("%c is a digit.\n", ch);
    }
    else {
        printf("%c is not a digit.\n", ch);
    }

    return 0;
}