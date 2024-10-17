#include <stdio.h>

int main()
{
    int n, i, j, count = 0, f = 1;

    scanf("%d", &n);

    char board[n][n + 1];

    for (i = 0; i < n; i++) {
        scanf(" %s", board[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            count = 0;

            if (i - 1 >= 0) {
                count += (board[i - 1][j] == 'o');
            }
            if (j - 1 >= 0) {
                count += (board[i][j - 1] == 'o');
            }
            if (i + 1 < n) {
                count += (board[i + 1][j] == 'o');
            }
            if (j + 1 < n) {
                count += (board[i][j + 1] == 'o');
            }

            if (count % 2 == 1) {
                f = 0;

                break;
            }
        }
    }

    puts(f == 1 ? "YES" : "NO");

    return 0;
}