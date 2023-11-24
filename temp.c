#include <stdio.h>
#include <string.h>

int main()
{
    int n = 3, i;
    char str[5][4];
    
    while (n--) {
        for (i = 0; i < 5; i++) {
            scanf(" %s", str[i]);
        }
    }

    n = 3;
    
    while (n--) {
        for (i = 0; i < 5; i++) {
            printf(" %s", str[i]);
        }

        puts("");
    }

    return 0;
}