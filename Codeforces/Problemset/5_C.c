#include <stdio.h>

int main()
{
    int i = 0, cnt = 0, len = -1, max_len = 0, count = 0;
    char s[1000005];

    gets(s);

    // max len
    while (s[i] == ')' && s[i] != '\0') {
        i++;
    }

    for (i; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            cnt++;
            len++;
        }
        else {
            cnt--;
            len++;
        }

        if (cnt < 0) {
            if (max_len < len) {
                max_len = len;
            }

            cnt = 0;
            len = -1;
        }
    }
    
    if (max_len < len) {
        max_len = len + 1;
    }

    // count
    i = 0;

    while (s[i] == ')' && s[i] != '\0') {
        i++;
    }

    cnt = 0;
    len = -1;

    for (i; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            cnt++;
            len++;
        }
        else {
            cnt--;
            len++;
        }

        if (cnt < 0) {
            if (max_len == len) {
                count++;
            }

            cnt = 0;
            len = -1;
        }
    }

    if (max_len == len + 1) {
        count++;
    }

    if (count == 0) {
        max_len = 0;
        count = 1;
    }

    printf("%d %d\n", max_len, count);

    return 0;
}