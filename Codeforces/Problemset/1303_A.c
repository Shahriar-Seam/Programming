#include <stdio.h>
#include <string.h>

int _count(char *str)
{
    int i, len = strlen(str), s_index, e_index, z_count = 0;

    for (i = 0; i < len; i++) {
        if (str[i] == '1') {
            s_index = i;
            break;
        }
    }
    
    for (i = len - 1; i >= 0; i--) {
        if (str[i] == '1') {
            e_index = i;
            break;
        }
    }

    for (i = s_index; i < e_index; i++) {
        if (str[i] == '0') {
            z_count++;
        }
    }

    return z_count;
}

int main()
{
    int t;
    char str[102];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", str);

        printf("%d\n", _count(str));
    }

    return 0;
}