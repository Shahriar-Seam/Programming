#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char s[1005];
    int k, i, sum = 0, max_w = 0;
    int alpha[26];

    scanf("%s", s);
    scanf("%d", &k);

    for (i = 0; i < 26; i++) {
        scanf("%d", alpha + i);
    }

    for (i = 0; i < 26; i++) {
        max_w = max(max_w, alpha[i]);
    }

    for (i = 0; s[i] != '\0'; i++) {
        sum += (alpha[s[i] - 'a'] * (i + 1));
    }

    i++;

    while (k--) {
        sum += max_w * i++;
    }

    printf("%d\n", sum);

    return 0;
}