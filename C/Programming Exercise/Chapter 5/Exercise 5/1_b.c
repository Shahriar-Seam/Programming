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
    int i, count = 0, length;

    gets(str);
    length = string_length(str);

    for (i = 0; i < length; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            count++;
        }
    }

    printf("Total english letters: %d\n", count);

    return 0;
}