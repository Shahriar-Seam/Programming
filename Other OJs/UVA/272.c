#include <stdio.h>
#include <string.h>

int main()
{
    char ch;
    int found = 0;

    while (scanf("%c", &ch) != EOF) {
        if (!found && ch == '"') {
            printf("``");

            found = 1;
        }
        else if (found && ch == '"') {
            printf("''");

            found = 0;
        }
        else {
            putchar(ch);
        }
    }

    return 0;
}