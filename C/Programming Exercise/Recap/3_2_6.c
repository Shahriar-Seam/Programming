#include <stdio.h>
#include <string.h>

void encrypt(char str[])
{
    int i, len;
    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] < 'y') {
            str[i] += 2;
        }
        else if (str[i] == 'y' || str[i] == 'z') {
            str[i] -= 24;
        }
    }

    printf("%s", str);

    return;
}

int main()
{
    char msg[100];

    gets(msg);

    encrypt(msg);

    return 0;
}