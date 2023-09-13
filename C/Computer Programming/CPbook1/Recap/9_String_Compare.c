#include <stdio.h>
#include <string.h>

int string_compare(char str1[], char str2[])
{
    int i;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] > str2[i]) {
            return 1;
        }
        if (str1[i] < str2[i]) {
            return -1;
        }
    }

    if (strlen(str1) == strlen(str2)) {
        return 0;
    }
    if (strlen(str1) > strlen(str2)) {
        return 1;
    }
    if (strlen(str1) < strlen(str2)) {
        return -1;
    }
}

int main()
{
    char str1[100], str2[100];
    int str_cmp;

    gets(str1);
    gets(str2);

    str_cmp = string_compare(str1, str2);

    if (str_cmp == 0) {
        printf("The strings are equal.\n");
    }
    else if (str_cmp == 1) {
        printf("%s is greater than %s\n", str1, str2);
    }
    else if (str_cmp == -1) {
        printf("%s is greater than %s\n", str2, str1);
    }

    return 0;
}