#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, len, i, j, f;
    char *str, letters[30];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &len);
        getchar();

        str = (char *) malloc(sizeof(char) * len);
        f = 0;

        gets(str);

        for (i = 0; i < len; i++) {
            for (j = i + 1; j < len; j++) {
                if (str[i] != str[i + 1] && str[i] == str[j]) {
                    f++;
                    break;
                }
            }
        }

        free(str);

        f ? no: yes;
    }

    return 0;
}