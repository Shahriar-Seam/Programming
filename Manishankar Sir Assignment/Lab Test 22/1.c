#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void print_words(char str[], int size, char words[100][100]);
void count_vowels(char words[100][100], int size);
void count_distinct(char words[100][100], int size);
bool is_present(char words[100][100], char s[100], int index);
void print_asterisks(int n);

int main()
{
    int size, f = 0, i = 0, j = 0;
    char str[10000], words[100][100], ch;

    while (scanf("%c", &ch) && ch != '\n') {
        if (isalpha(ch)) {
            words[i][j++] = ch;

            f = 0;
        }
        else if (!f) {
            i++;
            j = 0;

            f = 1;
        }
    }

    size = i + 1;

    printf("\n\nAll the words:\n");
    printf("-----------------------------\n");

    print_words(str, size, words);
    
    printf("-----------------------------\n");

    printf("\n\nVowel Count:\n");
    printf("-----------------------------\n");

    count_vowels(words, size);
    
    printf("-----------------------------\n");

    printf("\n\nDistinct Words:\n");
    printf("-----------------------------\n");

    count_distinct(words, size);
    
    printf("-----------------------------\n");

    return 0;
}

void print_words(char str[], int size, char words[100][100])
{
    int i;

    for (i = 0; i < size; i++) {
        puts(words[i]);
    }
}

void count_vowels(char words[100][100], int size)
{
    int i, j, len, count = 0;
    char ch;

    for (i = 0; i < size; i++) {
        len = strlen(words[i]);
        count = 0;

        for (j = 0; j < len; j++) {
            ch = words[i][j] | 32;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }

        printf("%s, vowel count = %d\n", words[i], count);
    }
}

void count_distinct(char words[100][100], int size)
{
    int i, j, count;
    char s[100];

    for (i = 0; i < size; i++) {
        strcpy(s, words[i]);

        if (is_present(words, s, i) == false) {
            count = 1;

            for (j = i + 1; j < size; j++) {
                if (strcmp(s, words[j]) == 0) {
                    count++;
                }
            }

            printf("%20s:", s);
            print_asterisks(count);

            printf("\n");
        }
    }
}

bool is_present(char words[100][100], char s[100], int index)
{
    int i = 0;

    for (i = 0; i < index; i++) {
        if (strcmp(words[i], s) == 0) {
            return true;
        }
    }

    return false;
}

void print_asterisks(int n)
{
    while (n--) {
        putchar('*');
    }
}