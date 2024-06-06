#include <stdio.h>

int main()
{
    char c;
    int s = 0;

    printf("Enter a number: ");

    while (scanf("%c", &c) && c != '\n') {
        s += c - '0';
    }

    printf("Sum of its digits is: %d\n", s);
    
    return 0;
}