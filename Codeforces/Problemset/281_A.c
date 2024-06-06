#include <stdio.h>

int main()
{
    char str[1001];

    gets(str);

    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }

    puts(str);

    return 0;
}