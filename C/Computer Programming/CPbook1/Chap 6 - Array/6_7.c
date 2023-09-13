#include <stdio.h>

int main()
{
    int num[5] = {6, 7, 4, 6, 9};

    printf("%d\n%d\n%d\n", num[-1], num[5], num[100]);

    return 0;
}

// Garbage