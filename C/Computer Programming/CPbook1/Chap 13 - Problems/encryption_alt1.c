#include <stdio.h>
#include <string.h>

void encrypt(char msg[])
{
    int i, len;

    len = strlen(msg);

    for (i = 0; i < len; i++) {
        if ((msg[i] >= 'a' && msg[i] < 'z') || (msg[i] >= 'A' && msg[i] < 'Z')) {
            msg[i]++;
        }

        else if (msg[i] == 'z') {
            msg[i] = 'a';
        }
        else if (msg[i] == 'Z') {
            msg[i] = 'A';
        }
    }
}

int main()
{
    char msg[100];

    scanf("%s", msg);

    encrypt(msg);

    printf("%s", msg);

    return 0;
}