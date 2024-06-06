#include <stdio.h>
#include <string.h>

int main()
{
    char key[27], msg[100], reverse_key[27];
    int i;

    gets(key);

    for (i = 0; i < 26; i++) {
        reverse_key[key[i] - 'a'] = i + 'a';
    }

    while (gets(msg) != 0) {
        int len = strlen(msg);

        for (int i = 0; i < len; i++) {
            char c = msg[i];
            if (c >= 'a' && c <= 'z') {
                msg[i] = reverse_key[c - 'a'];
            }
            else if (c >= 'A' && c <= 'Z') {
                msg[i] = reverse_key[c - 'A'] + 'A' - 'a';
            }
        }

        puts(msg);
    }

    return 0;
}