#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long long int n;
    char *str;

    scanf("%lld", &n);

    str = (char *) malloc(sizeof(char) * (n + 10));

    memset(str, 's', n + 10);

    str[0] = 'c';
    str[1] = 'o';
    str[2] = 'd';
    str[3] = 'e';
    str[4] = 'f';
    str[5] = 'o';
    str[6] = 'r';
    str[7] = 'c';
    str[8] = 'e';

    str[n + 9] = '\0';

    puts(str);

    free(str);

    return 0;
}