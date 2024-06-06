#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t, n, i, cs, cm;
    char *str;
    int *letters;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        str = (char *) malloc(sizeof(char) * (n + 1));
        letters = (int *) calloc(256, sizeof(int));

        cs = 0;
        cm = 0;

        gets(str);

        for (i = 0; i < n; i++) {
            letters[str[i]]++;
        }

        for (i = 63; i < 92; i++) {
            if (letters[i] != 0) {
                cs++;
                cm += letters[i];
            }
        }

        printf("%d\n", cs + cm);

        free(str);
        free(letters);
    }

    return 0;
}