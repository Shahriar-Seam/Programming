#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n, i, f;
    char str[52];
    int x, y;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();
        gets(str);

        x = y = f = 0;

        for (i = 0; i < n; i++) {
            if (str[i] == 'U') {
                y++;
            }
            else if (str[i] == 'D') {
                y--;
            }
            else if (str[i] == 'L') {
                x--;
            }
            else if (str[i] == 'R') {
                x++;
            }

            if (x == 1 && y == 1) {
                f = 1;

                break;
            }
        }

        f ? yes : no;
    }

    return 0;
}