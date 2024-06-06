#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t, i, j, pre_i, post_i, sum;
    char str[27], str1[52];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);
        gets(str1);

        sum = 0;

        for (i = 0; i < 26; i++) {
            if (str[i] == str1[0]) {
                pre_i = i;
                break;
            }
        }

        for (i = 0; i < strlen(str1); i++) {
            for (j = 0; j < 26; j++) {
                if (str1[i] == str[j]) {
                    post_i = j;
                    break;
                }
            }

            sum += abs(post_i - pre_i);
            pre_i = post_i;
        }

        printf("%d\n", sum);
    }

    return 0;
}