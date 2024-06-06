#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *distinct(char *s, int n)
{
    int i, j;
    int *counter = (int *) calloc(26, sizeof(int));
    char *dist = (char *) malloc(sizeof(char) * (n + 1));

    for (i = 0; i < n; i++) {
        counter[s[i] - 'a']++;
    }

    for (i = 0, j = 0; i < 26; i++) {
        if (counter[i] > 0) {
            dist[j++] = 'a' + i;
        }
    }

    for (i = 0; i < j; i++) {
        counter[dist[i] - 'a'] = dist[j - i - 1] - 'a';
    }

    return counter;
}

void solve()
{
    int n, i;
    int *dist;
    
    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    dist = distinct(s, n);

    for (i = 0; i < n; i++) {
        s[i] = 'a' + dist[s[i] - 'a'];
    }

    puts(s);
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