#include <stdio.h>

int main()
{
    char c;
    int s = 0;
    while (scanf("%c", &c) && c != '\n') {
        s += c - '0';
    }

    if (s % 3 == 0) {
        printf("Yes.\n");
    }
    else {
        printf("No.\n");
    }

    return 0;
}