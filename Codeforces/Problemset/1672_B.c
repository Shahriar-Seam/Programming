#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, a, b, f, len, i;
    char str[200005];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        a = b = f = 0;
        len = strlen(str);

        if ((str[0] == 'A') && (str[strlen(str) - 1] == 'B')) {
            for (i = 0; i < len; i++) {
                if (str[i] == 'A') {
                    a++;
                }
                else {
                    b++;
                }

                if (a < b) {
                    f = 1;
                }
            }

            f ? no : yes;
        }
        else {
            no;
        }
    }

    return 0;
}