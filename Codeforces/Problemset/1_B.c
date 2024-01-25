#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int power(int b, int p)
{
    int i, result = 1;

    for (i = 0; i < p; i++) {
        result *= b;
    }

    return result;
}

void reverse(char *s, int len)
{
    int i;
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int main()
{
    int t, i, j, c, len, len1, temp, rem;
    char r[102], col[102], column[102], row[102];
    char s1[102], s2[102], temp_s[102];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", s1);

        len = strlen(s1);
        c = 0;

        if (s1[0] == 'R') {
            for (i = 1, j = 0; s1[i] != 'C'; i++) {
                r[j++] = s1[i];
            }
            r[j] = '\0';

            for (++i, j = 0; i < len; i++) {
                col[j++] = s1[i];
            }
            col[j] = '\0';

            c = atoi(col);
            i = 0;

            while (c > 0) {
                rem = (c - 1) % 26;
                column[i++] = 'A' + rem;

                c = (c - rem) / 26;
            }

            reverse(column, i);
            column[i] = '\0';

            printf("%s%s\n", column, r);
        }
        else {
            for (i = 0; i < len; i++) {
                if (isalpha(s1[i])) {
                    temp_s[i] = s1[i];
                }
                else {
                    temp_s[i] = '\0';

                    break;
                }
            }
            for (j = 0; i < len; i++, j++) {
                row[j] = s1[i];
            }

            row[j] = '\0';

            len1 = strlen(temp_s);

            reverse(temp_s, len1);

            for (i = len1 - 1; i >= 0; i--) {
                c += (temp_s[i] - 'A' + 1) * power(26, i);
            }

            printf("R%sC%d\n", row, c);
        }
    }

    return 0;
}