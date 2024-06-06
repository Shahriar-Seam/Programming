#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    *a ^= *b ^= *a ^= *b;
}

int str_compare(char *s1, char *s2, int *index) {
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            *index = i;

            return 1;
        }
        else if (s1[i] < s2[i]) {
            *index = i;

            return -1;
        }
    }

    *index = -1;

    return 0;
}

void solve()
{
    char s1[105], s2[105];
    int i, compare, index;

    scanf(" %s %s", s1, s2);

    compare = str_compare(s1, s2, &index);

    if (compare == 1) {
        for (i = index + 1; s1[i] != '\0'; i++) {
            if (s1[i] > s2[i]) {
                swap(s1 + i, s2 + i);
            }
        }
    }
    else if (compare == -1) {
        for (i = index + 1; s1[i] != '\0'; i++) {
            if (s1[i] < s2[i]) {
                swap(s1 + i, s2 + i);
            }
        }
    }

    puts(s1);
    puts(s2);
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