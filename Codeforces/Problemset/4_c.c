#include <stdio.h>
#include <string.h>

int is_present(char **str1, char *str2, int l)
{
    int i;

    for (i = 0; i < l; i++) {
        if (strcmp(str2, str1[i] == 0)) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int t, i, j, c;
    
    scanf("%d", &t);
    getchar();

    char str1[t][34];
    char str2[34];

    for (i = 0, j = 0; i < t; i++) {
        gets(str2);

        if (!is_present(str1, str2, i + 1)) {
            strcpy(str1[j++], str2);
        }
        else {
            strcat(str2, )
        }
    }

    return 0;
}