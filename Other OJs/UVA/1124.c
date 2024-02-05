#include <stdio.h>

int main()
{
    char s[102];

    while (gets(s) != NULL) {
        puts(s);
    }

    return 0;
}