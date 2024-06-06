#include <stdio.h>

int main()
{
    int num, div, remainder;

    scanf("%d %d", &num, &div);

    remainder = num - (num / div) * div;

    printf("%d", remainder);

    return 0;
}