#include <stdio.h>
#include <string.h>

void MTrim(char *str);
void shift(char *str, int finish, int dist);
void LTrim(char *str);
void RTrim(char *str);

int main()
{
    char str[100];

    gets (str);

    LTrim(str);
    RTrim(str);
    MTrim(str);

    puts(str);

    return 0;
}

void shift(char *str, int finish, int dist)
{
    int i, len = strlen(str);

    for (i = finish - dist; i < len; i++) {
        str[i] = str[i + dist];
    }
}

void MTrim(char *str)
{
    int i, spaces = 0, index = 0, flag = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            spaces++;

            flag = 1;
        }
        else if (flag) {
            index = i;

            shift(str, index, spaces);

            i -= spaces;

            spaces = 0;
        }
    }
}

void LTrim(char *str)
{
    int i, len = strlen(str), index = 0;

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            index = i;
            break;
        }
    }

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[index + i];
    }
}

void RTrim(char *str)
{
    int i, len = strlen(str);

    for (i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            break;
        }
    }
}