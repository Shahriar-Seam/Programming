#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, i, count = 1, cost = 0, big = 0;
        
        scanf("%d", &n);

        char s[n + 1];

        scanf(" %s", s);

        cost = 2;
        count = 1;

        for (i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            }
            else {
                cost = max(cost, count + 1);
                count = 1;
            }
        }

        cost = max(cost, count + 1);

        printf("%d\n", cost);
    }

    return 0;
}