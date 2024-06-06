#include <stdio.h>
#include <string.h>

int clean(char *str1, char *str2)
{
    int i, len = strlen(str1);

    for (i = 0; i < 6; i++) {
        str2[i] = '0';
    }

    for (i = 0; i < len; i++) {
        if (str1[i] == 'T') {
            str2[0] = 'T';
        }
        else if (str1[i] == 'i') {
            str2[1] = 'i';
        }
        else if (str1[i] == 'm') {
            str2[2] = 'm';
        }
        else if (str1[i] == 'u') {
            str2[3] = 'u';
        }
        else if (str1[i] == 'r') {
            str2[4] = 'r';
        }
    }

    str2[5] = '\0';
}

int main()
{
    int t, n;
    char str[12], str2[6];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        scanf(" %s", str);

        clean(str, str2);
        
        if ((str2[0] == 'T' && str2[1] == 'i' && str2[2] == 'm' && str2[3] == 'u' && str2[4] == 'r') && (n == 5)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}