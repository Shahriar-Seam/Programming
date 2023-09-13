#include <stdio.h>

int main()
{
    char small_c, cap_c;

    scanf("%c", &small_c);

    cap_c = small_c - 'a' + 'A';

    printf("%c\n", cap_c);

    return 0;
}