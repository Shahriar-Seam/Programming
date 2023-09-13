#include <stdio.h>
#include <string.h>

void decrypt(char msg[])
{
    int i, n;

    n = strlen(msg);

    for (i = 0; i < n; i++) {
        if ((msg[i] > 'a' && msg[i] <= 'z') || (msg[i] > 'A' && msg[i] <= 'Z')) {
            msg[i]--;
        }

        else if (msg[i] == 'a') {
            msg[i] = 'z';
        }
        else if (msg[i] == 'A') {
            msg[i] = 'Z';
        }
    }
}

int main()
{
    char msg[100];

    scanf("%s", msg);

    decrypt(msg);

    printf("%s", msg);

    return 0;
}