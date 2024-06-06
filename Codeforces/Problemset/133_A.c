#include <stdio.h>
#include <string.h>

int main()
{
    char str[102];
    int i, len, y = 0;

    gets(str);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9') {
            y = 1;
            break;
        }
    }

    y ? printf("YES") : printf("NO");

    return 0;
}