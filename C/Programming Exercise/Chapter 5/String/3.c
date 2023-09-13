#include <stdio.h>
#include <string.h>

int main()
{
    char key[27], msg[100];

    gets(key);

    while (gets(msg) != 0) {
        int len = strlen(msg);

        for (int i = 0; i < len; i++) {
            char c = msg[i];
            if (c >= 'a' && c <= 'z') {
                msg[i] = key[c - 'a'];
            }
            else if (c >= 'A' && c <= 'Z') {
                msg[i] = key[c - 'A'] + 'A' - 'a';
            }
        }

        puts(msg);
    }

    return 0;
}