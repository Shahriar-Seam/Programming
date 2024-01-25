#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char str[3];
    int count;
} map;

int compare(const void *a, const void *b)
{
    return ((map *) b)->count - ((map *) a)->count;
}

int _count(char *s, char l, char r, int n)
{
    int i, cnt = 0;

    for (i = 0; i < n - 1; i++) {
        if (s[i] == l && s[i + 1] == r) {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n, i, count = 0, max_count = 0, index = 0;
    map *s;
    char *str, temp[3];

    scanf("%d", &n);

    s = (map *) malloc (sizeof(map) * n);
    str = (char *) malloc (sizeof(char) * (n + 1));

    strcpy(s[n - 1].str, "\0");
    s[n - 1].count = 0;

    scanf(" %s", str);

    for (i = 0; i < n - 1; i++) {
        temp[0] = str[i];
        temp[1] = str[i + 1];
        temp[2] = '\0';

        strcpy(s[i].str, temp);
        s[i].count = _count(str, temp[0], temp[1], n);
    }

    qsort(s, n, sizeof(map), compare);

    puts(s[0].str);
    
    free(s);
    free(str);

    return 0;
}