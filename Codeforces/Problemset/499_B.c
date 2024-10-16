#include <stdio.h>
#include <string.h>

char *get(char dict[][2][12], char *s, int m) {
    int i;

    for (i = 0; i < m; i++) {
        if (strcmp(dict[i][0], s) == 0) {
            return dict[i][1];
        }
    }

    return NULL;
}

int main()
{
    int n, m, i;
    char s1[12], s2[12];

    scanf("%d %d", &n, &m);

    char dict[m][2][12];

    for (i = 0; i < m; i++) {
        scanf(" %s %s", s1, s2);

        strcpy(dict[i][0], s1);

        if (strlen(s1) <= strlen(s2)) {
            strcpy(dict[i][1], s1);
        }
        else {
            strcpy(dict[i][1], s2);
        }
    }

    for (i = 0; i < n; i++) {
        scanf(" %s", s1);

        printf("%s ", get(dict, s1, m));
    }

    return 0;
}