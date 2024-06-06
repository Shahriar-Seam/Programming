#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    char str1[n], str2[n], str3[n], str4[n];

    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);

    for (i = 0; i < n; i++) {
        printf("%c", str1[i]);
    }
}