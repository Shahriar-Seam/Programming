#include <stdio.h>

int main()
{
    char c;
    int s = 0;

    while (scanf(" %c", &c) && c != '0') {
        s += c - '0';
    }
    
    if (s % 6 == 0) {
        printf("The number is divisible by 6.\n");
    }
    else {
        printf("The number is not divisible by 6.\n");
    }

    return 0;
}