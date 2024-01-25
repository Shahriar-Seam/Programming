#include <stdio.h>
#include <string.h>

int main()
{
    int t, i, coins1, coins2, coins;
    char str1[100005], str2[100005], *c;

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str1);

        strcpy(str2, str1);

        coins = coins1 = coins2 = 0;

        for (i = 0; str1[i + 1] != '\0'; i++) {
            if (str1[i] == 'A' && str1[i + 1] == 'B') {
                str1[i] = 'B';
                str1[i + 1] = 'C';

                coins1++;
                i -= 2;
            }
            if (str1[i] == 'B' && str1[i + 1] == 'A') {
                str1[i] = 'C';
                str1[i + 1] = 'B';

                coins1++;
                i -= 2;
            }
        }

        for (i = 0; str2[i + 1] != '\0'; i++) {
            if (str2[i] == 'B' && str2[i + 1] == 'A') {
                str2[i] = 'C';
                str2[i + 1] = 'B';

                coins2++;
                i -= 2;
            }
            if (str2[i] == 'A' && str2[i + 1] == 'B') {
                str2[i] = 'B';
                str2[i + 1] = 'C';

                coins2++;
                i -= 2;
            }
        }

        coins = coins1 > coins2 ? coins1 : coins2;

        printf("%d\n", coins);
    }

    return 0;
}