#include <stdio.h>
#include <string.h>

#define yes puts("YES")
#define no puts("NO")

int main()
{
    int n, t, r, b, i, f;
    char s[100005];

    scanf("%d", &t);

    while (t--) {
        scanf("%d %s", &n, s);

        char *token = strtok(s, "W");

        f = 1;

        while (token != NULL) {
            r = b = 0;
            f = 1;

            for (i = 0; token[i] != 0; i++) {
                r += token[i] == 'R';
                b += token[i] == 'B';
            }

            if (r == 0 || b == 0) {
                f = 0;
                break;
            }

            token = strtok(NULL, "W");
        }

        f == 1 ? yes : no;
    }

    return 0;
}