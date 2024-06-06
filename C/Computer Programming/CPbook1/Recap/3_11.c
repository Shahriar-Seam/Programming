#include <stdio.h>

int main()
{
    char ch;

    ch = getchar();

    if (ch >= 'a' && ch <= 'z') {
        printf("%c is lower case.", ch);
    }
    else if (ch >= 'A' && ch <= 'Z') {
        printf("%c is upper case.", ch);
    }

    return 0;
}