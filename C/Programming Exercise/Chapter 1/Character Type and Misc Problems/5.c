#include <stdio.h>

int main()
{
    char ch;

    ch = getchar();

    printf("%c", (int) ch - 32);

    return 0;
}