#include <stdio.h>
#include <string.h>

int main()
{
    char s1[15], s2[15];
    char t1[15], t2[15];
    int n;

    scanf("%s %s", s1, s2);

    printf("%s %s\n", s1, s2);

    scanf("%d", &n);

    while (n--) {
        scanf(" %s %s", t1, t2);

        if (strcmp(s1, t1) == 0) {
            strcpy(s1, t2);
        }
        else {
            strcpy(s2, t2);
        }

        printf("%s %s\n", s1, s2);
    }

    return 0;
}