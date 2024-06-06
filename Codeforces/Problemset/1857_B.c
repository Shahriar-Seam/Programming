#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *meh(char *x)
{
    int i, index = -1, f = 0;

    for (i = 0; x[i] != '\0'; i++) {
        if (x[i] - '0' >= 5) {
            index = i;

            f = 1;

            break;
        }
    }

    if (f == 0) {
        return x;
    }

    if (index == 0) {
        x[0] = '1';

        for (i = 1; x[i] != '\0'; i++) {
            x[i] = '0';
        }

        x[i++] = '0';
        x[i] = '\0';

        return x;
    }

    for (i = index - 1; i >= 0; i--) {
        x[i] = x[i] + 1;

        if (x[i] - '0' < 5) {
            index = i + 1;

            break;
        }
    }

    for (i = index; x[i] != '\0'; i++) {
        x[i] = '0';
    }
    
    return x;
}

void solve()
{
    char *x;

    x = (char *) malloc(sizeof(char) * 200005);

    scanf(" %s", x);

    x = meh(x);
    x = meh(x);

    puts(x);

    free(x);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}