#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    char str[10];
    int i1, i3, i;

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", str);

        for (i = 0; i < 10; i++) {
            if (str[i] == '1') {
                i1 = i;
            }
            else if (str[i] == '3') {
                i3 = i;
            }
        }

        if (i1 < i3) {
            printf("13\n");
        }
        else {
            printf("31\n");
        }
    }

    return 0;
}