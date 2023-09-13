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
    int i, count_vowel = 0, count_consonant = 0, length;

    gets(str);
    length = string_length(str);

    for (i = 0; i < length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count_vowel++;
        }

        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            count_consonant++;
        }
    }

    printf("Vowel: %d\nConsonant: %d\n", count_vowel, count_consonant);

    return 0;
}