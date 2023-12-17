#include <stdio.h>
#include <string.h>

int main()
{
    char ch = 'A', ch1 = 'a';

    printf("%c\n%c\n", ch ^ 32, ch1 ^ 32);

    return 0;
}