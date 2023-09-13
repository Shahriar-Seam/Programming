#include <stdio.h>

int main()
{
    char c;

    scanf("%c", &c);

    if (c >= 'a' && c <= 'z') {
        printf("Small letter.\n");
    }
    else if (c >= 'A' && c <= 'Z') {
        printf("Capital letter.\n");
    }
    else if (c >= '0' && c <= '9') {
        printf("Digit.\n");
    }
    else {
        printf("Other character.\n");
    }

    return 0;
}