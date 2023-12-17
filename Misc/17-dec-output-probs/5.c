#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = {0};

    gets(s);

    printf("%s\n", strcat(s, "bla"));
    printf("%d\n", strcmp("seam", "SEAM"));
    printf("%s\n", strcpy(s, "Durjay pocha sjd"));
    printf("%s\n", strstr(s, "po"));

    return 0;
}