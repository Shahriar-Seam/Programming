#include <stdio.h>

int check(char ch)
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

    (check(ch)) ? printf("%c is a digit\n", ch) : printf("%c is not a digit\n", ch);

    return 0;
}