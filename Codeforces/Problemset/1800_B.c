#include <stdio.h>
#include <stdlib.h>

int _min(int a, int b)
{
  return a < b ? a : b;
}

int _max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, k, i, min, max, burles = 0, temp;
    int small[26] = {}, capital[26] = {};

    scanf("%d %d", &n, &k);

    char *str = (char *) malloc(sizeof(char) * (n + 1));

    scanf(" %s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            small[str[i] - 'a']++;
        }
        else {
            capital[str[i] - 'A']++;
        }
    }

    for (i = 0; i < 26; i++) {
        min = _min(small[i], capital[i]);
        max = _max(small[i], capital[i]);

        burles += min;

        if (k > 0) {
            temp = _min(k, (max - min) / 2);

            burles += temp;

            k -= temp;
        }
    }

    printf("%d\n", burles);

    free(str);
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