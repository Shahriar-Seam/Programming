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
    int i, length, count = 0;

    gets(str);
    length = string_length(str);

    for (i = 0; i < length / 2; i++) {
        if (str[i] == str[length - i - 1]) {
            count++;
        }
    }

    if (count == length / 2) {
        printf("The string is a palindrome.\n");
    }
    else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}