#include <stdio.h>
#include <string.h>

void sort(char *str)
{
    int i, j, len = strlen(str);
    char temp;

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    int t;
    char str[55];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        sort(str);

        puts(str);
    }

    return 0;
}