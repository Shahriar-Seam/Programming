#include <stdio.h>
#include <string.h>

void remove_spaces(char *str, char *f_str)
{
    int i, j = 0;
    int len = strlen(str);
    int space = 0;

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            f_str[j] = str[i];
            j++;
            space = 0;
        }
        else {
            if (!space) {
                f_str[j] = ' ';
                j++;
                space = 1;
            }
        }
    }

    f_str[j] = '\0';

    if (f_str[0] == ' ') {
        for (i = 1; i < strlen(f_str); i++) {
            f_str[i - 1] = f_str[i];
        }

        f_str[i - 1] = '\0';
    }
}

void clean(char *str, char *og_str)
{
    int i, j = 0, len = strlen(str);

    for (i = 0; i < len; i++) {
        if ((str[i] == 'W') && (str[i + 1] == 'U') && (str[i + 2] == 'B')) {
            i += 2;
            og_str[j] = ' ';
            j++;
        }
        else {
            og_str[j] = str[i];
            j++;
        }
    }

    og_str[j] = '\0';
}

int main()
{
    char str[202];
    char og_str[202];
    char f_str[102];

    gets(str);

    clean(str, og_str);
    remove_spaces(og_str, f_str);

    puts(f_str);

    return 0;
}