#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rev_str(char *str)
{
    int i, len = strlen(str);
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    int t, n, i, j;
    char *str, *str2, temp[3];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        str = (char *) malloc (sizeof(char) * n + 2);
        str2 = (char *) malloc (sizeof(char) * n + 2);

        gets (str);

        for  (i = n - 1, j = 0; i >= 0; i--) {
            if (str[i] == '0') {
                temp[0] = str[i - 2];
                temp[1] = str[i - 1];

                int s = atoi(temp);

                str2[j] = s + 96;
                
                j++;
                i -= 2;
            }
            else {
                str2[j++] = str[i] + 96 - 48;
            }
        }

        str2[j] = '\0';

        rev_str(str2);

        puts(str2);

        free(str);
        free(str2);
    }

    return 0;
}