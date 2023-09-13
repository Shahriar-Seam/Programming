#include <stdio.h>

int main()
{
    char ch;

    ch = getchar();

    if ('a' <= ch && ch <= 'z') {
        printf("%c is a small letter.\n", ch);
    }
    else if ('A' <= ch && ch <= 'Z') {
        printf("%c is a capital letter.\n", ch);
    }
    else if ('0' <= ch && ch <= '9') {
        printf("%c is a digit.\n", ch);
    }
    else {
        printf("%c is a symbol.\n");
    }

    return 0;
}