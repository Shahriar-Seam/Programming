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
    int i, length, count_digits = 0;

    gets(str);
    length = string_length(str);

    for (i = 0; i < length; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count_digits++;
        }
    }

    printf("Number of digits: %d\n", count_digits);

    return 0;
}