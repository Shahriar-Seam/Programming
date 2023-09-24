#include <stdio.h>

int main()
{
    char str[] = "1102546";
    char str2[10];

    for (int i = 0, j = 0; i < 8; i++, j++) {
        str2[j] = str[i] - '0' + 96;
    }

    puts(str2);

    return 0;
}