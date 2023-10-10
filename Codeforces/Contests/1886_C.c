#include <stdio.h>
#include <string.h>

void tata_highest(char *str)
{
    int len = strlen(str), index = 0, i;
    char max = str[0];

    for (i = 1; i < len; i++) {
        if (str[i] > max) {
            max = str[i];
            index = i;
        }
    }

    for (i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }

    str[i] = '\0';
}

int main()
{
    int t, n, i;
    char str[1000005], temp[1000005], result[10005];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        getchar();
        gets(str);
        scanf("%d", &n);

        strcpy(temp, str);

        while (strlen(temp) != 0) {
            tata_highest(temp);

            strcat(str, temp);
        }

        result[i] = str[n - 1];
    }

    result[i] = '\0';

    printf("%s", result);

    return 0;
}