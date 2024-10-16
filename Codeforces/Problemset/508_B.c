#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    *a ^= *b ^= *a ^= *b;
}

int to_int(char c) {
    return c - '0';
}

int main()
{
    char s[(int) 1e5 + 5];
    int last, len, last_even_index = -1, smaller_index = -1;
    int even = 0, i;

    scanf("%s", s);

    len = strlen(s);

    last = to_int(s[len - 1]);

    for (i = 0; i < len; i++) {
        if (to_int(s[i]) % 2 == 0) {
            even++;

            last_even_index = i;
        }
    }

    if (!even) {
        printf("-1\n");

        return 0;
    }

    for (i = 0; i < len - 1; i++) {
        if ((to_int(s[i]) % 2 == 0) && to_int(s[i]) < last) {
            smaller_index = i;

            break;
        }
    }

    if (smaller_index != -1) {
        swap(s + smaller_index, s + len - 1);
    }
    else {
        swap(s + last_even_index, s + len - 1);
    }

    puts(s);

    return 0;
}