#include <stdio.h>
#include <string.h>

int main()
{
    int n, counter[100005], count = 0, i, j, f;
    char str[100005][35], s[35];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf(" %s", s);

        f = 0;

        for (j = 0; j < count; j++) {
            if (strcmp(s, str[j]) == 0) {
                f = 1;
                break;
            }
        }

        if (f == 1) {
            printf("%s%d\n", s, ++counter[j]);
        }
        else {
            printf("OK\n");
            strcpy(str[count++], s);
            counter[count] = 0;
        }
    }

    return 0;
}