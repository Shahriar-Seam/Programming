#include <stdio.h>

int string_length(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++);

    return i;
}

int main()
{
    char str[100];
    int i, length;

    gets(str);
    length = string_length(str);

    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}