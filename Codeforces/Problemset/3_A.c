#include <stdio.h>
#include <string.h>

int main()
{
    char s[3], t[3];
    int count = 0, i;
    char m[4];
    char moves[500][4] = {};

    scanf("%s %s", s, t);

    while (s[0] != t[0] || s[1] != t[1]) {
        if (s[0] > t[0] && s[1] > t[1]) {
            strcpy(m, "LD\n");

            s[0]--;
            s[1]--;
        }
        else if (s[0] > t[0] && s[1] < t[1]) {
            strcpy(m, "LU\n");

            s[0]--;
            s[1]++;
        }
        else if (s[0] < t[0] && s[1] < t[1]) {
            strcpy(m, "RU\n");

            s[0]++;
            s[1]++;
        }
        else if (s[0] < t[0] && s[1] > t[1]) {
            strcpy(m, "RD\n");

            s[0]++;
            s[1]--;
        }
        else if (s[0] < t[0]) {
            strcpy(m, "R\n");

            s[0]++;
        }
        else if (s[0] > t[0]) {
            strcpy(m, "L\n");

            s[0]--;
        }
        else if (s[1] > t[1]) {
            strcpy(m, "D\n");

            s[1]--;
        }
        else if (s[1] < t[1]) {
            strcpy(m, "U\n");

            s[1]++;
        }
        
        strcpy(moves[count], m);

        count++;
    }

    printf("%d\n", count);

    for (i = 0; i < count; i++) {
        printf("%s", moves[i]);
    }

    return 0;
}