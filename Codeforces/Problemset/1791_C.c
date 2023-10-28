#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t, n, i, j, c;
    char *str;

    scanf("%d",&t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        str = (char *) malloc(sizeof(char) * (n + 1));
        c = 0;

        gets(str);

        for (i = 0, j = n - 1; i < n / 2; i++, j--) {
            if (str[i] != str[j]) {
                c++;
            }
            else {
                break;
            }
        }

        printf("%d\n", n - 2 * c);

        free(str);
    }

    return 0;
}