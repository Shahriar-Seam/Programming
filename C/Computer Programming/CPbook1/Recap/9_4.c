#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    gets(str);

    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }

    puts(str);

    return 0;
}