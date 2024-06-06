#include <stdio.h>
#include <string.h>

int main()
{
    int n, t, i, j;
    char temp;

    scanf("%d %d", &n, &t);
    getchar();

    char str[n];

    gets(str);

    for (i = 0; i < t; i++) {
        for (j = 0; j < n - 1; j++) {
            if ((str[j] == 'B') && (str[j + 1] == 'G')) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                j++;
            }
        }
    }

    puts(str);

    return 0;
}