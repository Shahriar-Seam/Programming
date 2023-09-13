#include <stdio.h>

int main()
{
    int n, vowels = 0, v, consonants = 0, letters, digits = 0, punctuations = 0, special = 0;
    char ch;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf(" %c", &ch);

        v = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

        if (v) {
            vowels += 1;
        }

        else if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && !v) {
            consonants += 1;
        }

        else if (ch >= '0' && ch <= '9') {
            digits += 1;
        }

        else if (ch == '!' || ch == '"' || ch == ',' || ch == '.' || ch == '?' || ch == ':' || ch == ';') {
            punctuations += 1;
        }

        else {
            special += 1;
        }

        letters = vowels + consonants;
    }

    printf("Vowels = %d\nConsonants = %d\nTotal Letters = %d\nDigits = %d\nPunctuations = %d\nSpecial Characters = %d\n", vowels, consonants, letters, digits, punctuations, special);

    return 0;
}