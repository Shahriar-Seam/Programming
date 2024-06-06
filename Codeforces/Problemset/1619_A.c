#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, len, i, f;
    char str[102];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        len = strlen(str);
        f = 1;

        if (len % 2 == 0) {
            for (i = 0; i < len / 2; i++) {
                if (str[i] != str[len / 2 + i]) {
                    f = 0;
                    no;
                    break;
                }
            }

            if (f) yes;
        }
        else no;
    }

    return 0;
}