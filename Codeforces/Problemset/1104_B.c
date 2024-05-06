/**
 *    author:  Anonymous_HF
 *    created: 06/05/2024 20:35:33
**/

#include <stdio.h>

int __max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    char str[100005];
    char s[100005];
    int i, j;

    gets(str);

    s[0] = str[0];

    for (i = 1, j = 1; str[i] != '\0'; i++) {
        if (j > 0 && str[i] == s[j - 1]) {
            j = __max(0, j - 1);
        }
        else {
            s[j++] = str[i];
        }
    }

    s[j] = '\0';

    puts(((i - j) / 2) % 2 == 0 ? "NO" : "YES");

    return 0;
}