#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    char str[3];
    char str1[5][3];
    int i, f = 0;

    scanf("%s", str);

    for (i = 0; i < 5; i++) {
        scanf(" %s", str1[i]);
    }

    for (i = 0; i < 5; i++) {
        if ((str[0] == str1[i][0]) || (str[1] == str1[i][1])) {
            f = 1;
            break;
        }
    }

    f ? yes : no;

    return 0;
}