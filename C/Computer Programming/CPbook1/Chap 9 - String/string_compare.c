#include <stdio.h>

int string_length(char a[])
{
    int i;

    for (i = 0; a[i] != '\0'; i++) {
        i++;
    }

    return i;
}

int string_compare(char a[], char b[])
{
    int i;

    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] > b[i]) {
            return 1;
        }
        if (a[i] < b[i]) {
            return -1;
        }
    }

    if (string_length(a) == string_length(b)) {
        return 0;
    }
    if (string_length(a) > string_length(b)) {
        return 1;
    }
    if (string_length(a) < string_length(b)) {
        return -1;
    }
}

int main()
{
    char str1[100], str2[100];

    gets(str1);
    gets(str2);

    int comp = string_compare(str1, str2);

    if (comp == 0) {
        printf("The strings are equal.\n");
    }
    if (comp == 1) {
        printf("%s is greater than %s\n", str1, str2);
    }
    if (comp == -1) {
        printf("%s is greater than %s\n", str2, str1);
    }

    return 0;
}