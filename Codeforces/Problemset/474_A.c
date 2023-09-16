#include <stdio.h>
#include <string.h>

char og_str[102];

void fill_in_r(char str[], char ch)
{
    int i, len = strlen(str);
    static int j = 0;
    
    for (i = 0; i < len; i++) {
        if (ch == str[i]) {
            og_str[j] = str[i - 1];
            j++;
        }
    }

    og_str[j] = '\0';
}

void fill_in_l(char str[], char ch)
{
    int i, len = strlen(str);
    static int j = 0;
    
    for (i = 0; i < len; i++) {
        if (ch == str[i]) {
            og_str[j] = str[i + 1];
            j++;
        }
    }

    og_str[j] = '\0';
}

int main()
{
    char shift;
    char str[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
    int i, j;
    char ch;

    scanf("%c", &shift);
    getchar();

    if (shift == 'R') {
        for (i = 0; ch != '\n'; i++) {
            scanf("%c", &ch);

            fill_in_r(str, ch);
        }
    }

    if (shift == 'L') {
        for (i = 0; ch != '\n'; i++) {
            scanf("%c", &ch);

            fill_in_l(str, ch);
        }
    }

    printf("%s", og_str);

    return 0;
}