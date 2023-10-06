#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int i, len;
    char str[102];

    gets(str);

    len = strlen(str);

    if (len < 7) {
        no;

        return 0;
    }

    for (i = 0; i <= len - 7; i++) {
        if (str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '1' && str[i + 3] == '1' && str[i + 4] == '1' && str[i + 5] == '1' && str[i + 6] == '1') {
            yes;
            return 0;
        }
        if (str[i] == '0' && str[i + 1] == '0' && str[i + 2] == '0' && str[i + 3] == '0' && str[i + 4] == '0' && str[i + 5] == '0' && str[i + 6] == '0') {
            yes;
            return 0;
        }
    }

    no;

    return 0;
}