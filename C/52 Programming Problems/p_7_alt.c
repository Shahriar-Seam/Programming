#include <stdio.h>
#include <string.h>

int main()
{
    int t, is_num, count, i;
    char str[1002];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        is_num = 0;
        count = 0;

        for (i = 0; i < strlen(str); i++) {
            if (!is_num && (str[i] >= '0' && str[i] <= '9')) {
                is_num = 1;
                count++;
            }
            else if (str[i] == ' ') {
                is_num = 0;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}