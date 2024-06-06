#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[102];
    char sen[102];

    ch = getchar();

    scanf(" %s", s);
    scanf(" %[^\n]", sen);

    putchar(ch);
    puts("");
    puts(s);
    puts(sen);

    return 0;
}