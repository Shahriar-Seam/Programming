#include <stdio.h>

int main()
{
    char str[100];
    int i;

    gets(str);

    for (i = 0; str[i] != '\0'; i++);

    printf("Length: %d\n", i);

    return 0;
}