#include <stdio.h>
#include <string.h>

int main()
{
    char word[80], reverse_word[80];
    int i, len;

    scanf("%s", word);

    len = strlen(word);

    for (i = 0; i < len; i++) {
        reverse_word[i] = word[len - i - 1];
    }

    reverse_word[i] = '\0';
    puts(reverse_word);

    if (0 == strcmp(word, reverse_word)) {
        printf("%s is a palindrome.\n", word);
    }
    else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}