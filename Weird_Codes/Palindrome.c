#include <stdio.h>
#include <string.h>

int is_palindrome(char *str)
{
    int len = strlen(str), i;

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[50], temp[50];
    int i, j, k, m, len, count = 0;

    printf("Enter a number:\n");
    gets(str);

    len = strlen(str);

    printf("Below are the palindrome parts of the number: \n");

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            m = 0;

            for (k = i; k <= j; k++) {
                temp[m++] = str[k];
            }

            temp[m] = '\0';

            if (is_palindrome(temp)) {
                printf("%s\n", temp);
                count++;
            }
        }
    }

    printf("Total palindromes: %d\n", count);

    return 0;
}
