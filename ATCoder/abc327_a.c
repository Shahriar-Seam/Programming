#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char str[102];

    scanf("%d", &n);
    getchar();
    gets(str);

    if ((strstr(str, "ab") != 0) || (strstr(str, "ba") != 0)) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}