// Use of && (And) operator
// Check if a letter is small or capital
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);
    
    if (ch >= 'a' && ch <= 'z') {
        printf("Small letter.\n");
    }
    else if (ch >= 'A' && ch <= 'Z') {
        printf("Capital letter.\n");
    }

    return 0;
}