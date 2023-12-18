#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], word[100];

    gets(str);

    int len = strlen(str);

    str[len] = ' ';

    int i, j = 0, space = 0;

    for (i = 0; i <= len; i++) {
        if (!space && str[i] == ' ') {
            space = 1;
            j = 0;
            if (strlen(word) >= 5) {
                printf("%s\n", word);
            }
        }
        else if (str[i] != ' ') {
            word[j++] = str[i];
            space = 0;
        }
    }

    return 0;
}