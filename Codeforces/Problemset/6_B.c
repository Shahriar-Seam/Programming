#include <stdio.h>

int main()
{
    int n, m, i, j, count = 0;
    char c;
    char counter[26] = {};

    scanf("%d %d %c", &n, &m, &c);

    char s[n][m + 1];

    for (i = 0; i < n; i++) {
        scanf(" %s", s[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == c) {
                if (i > 0 && s[i - 1][j] != '.' && s[i - 1][j] != c) {
                    counter[s[i - 1][j] - 'A']++;
                }
                if (i < n - 1 && s[i + 1][j] != '.' &&  s[i + 1][j] != c) {
                    counter[s[i + 1][j] - 'A']++;
                }
                if (j > 0 && s[i][j - 1] != '.' && s[i][j - 1] != c) {
                    counter[s[i][j - 1] - 'A']++;
                }
                if (j < m - 1 && s[i][j + 1] != '.' && s[i][j + 1] != c) {
                    counter[s[i][j + 1] - 'A']++;
                }
            }
        }
    }

    for (i = 0; i < 26; i++) {
        count += (counter[i] > 0);
    }

    printf("%d\n", count);

    return 0;
}