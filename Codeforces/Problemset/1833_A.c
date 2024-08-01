#include <stdio.h>
#include <string.h>

int is_present(char set[55][3], char *s, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(set[i], s) == 0) {
            return 1;
        }
    }

    return 0;
}

void get_sub(char *t, char *s, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        t[i] = s[i];
    }
}

void solve()
{
    int n, i, size = 0;
    char s[55], temp[3];
    char set[55][3];

    scanf("%d %s", &n, s);

    for (i = 0; i < n - 1; i++) {
        get_sub(temp, s + i, 2);

        if (!is_present(set, temp, size)) {
            strcpy(set[size], temp);
            size++;
        }
    }

    printf("%d\n", size);
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