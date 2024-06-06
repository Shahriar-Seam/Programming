#include <stdio.h>
#include <string.h>

int main()
{
    int n, t1 = 0, t2 = 0, f = 0;
    char str[20], str1[20], str2[20];

    scanf("%d", &n);
    getchar();

    gets(str1);
    t1++;
    n--;

    while (n--) {
        gets(str);

        if (!f && strcmp(str, str1) != 0) {
            strcpy(str2, str);
            f = 1;
        }

        if (strcmp(str, str1) == 0) {
            t1++;
        }
        else {
            t2++;
        }
    }

    puts((t1 > t2) ? str1 : str2);

    return 0;
}