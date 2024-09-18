#include <stdio.h>

int main()
{
    int n, k, i, j;

    scanf("%d %d", &n, &k);

    char s[n + 1];

    scanf(" %s", s);

    if (n == 1 && k == 1) {
        puts("0");
    }
    else {
        if (k > 0 && s[0] != '1') {
            s[0] = '1';


            k--;
        }

        for (i = 1, j = 0; i < n && j < k; i++) {
            if (s[i] != '0') {
                s[i] = '0';
                j++;
            }
        }

        puts(s);
    }

    return 0;
}