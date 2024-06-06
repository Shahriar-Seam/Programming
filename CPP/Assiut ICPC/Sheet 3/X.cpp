#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, x, y, i, f = 1;

    cin >> n >> m;
    getchar();

    char str[n][m + 1];

    for (i = 0; i < n; i++) {
        gets(str[i]);
    }

    cin >> x >> y;

    x--; y--;

    if (x > 0 && y > 0) {
        if (str[x - 1][y - 1] != 'x' || str[x - 1][y] != 'x' || str[x - 1][y + 1] != 'x') {
            f = 0;
        }
        else if (str[x][y - 1] != 'x' || str[x][y + 1] != 'x') {
            f = 0;
        }
        else if (str[x + 1][y - 1] != 'x' || str[x + 1][y] != 'x' || str[x + 1][y + 1] != 'x') {
            f = 0;
        }
    }
    else if (x == 0 && y == 0) {
        if (str[x + 1][y] != 'x' || str[x][y + 1] != 'x' || str[x + 1][y + 1] != 'x') {
            f = 0;
        }
    }
    else if (x == 0) {
        if (str[x][y - 1] != 'x' || str[x][y + 1] != 'x') {
            f = 0;
        }
        else if (str[x + 1][y - 1] != 'x' || str[x + 1][y] != 'x' || str[x + 1][y + 1] != 'x') {
            f = 0;
        }
    }
    else if (y == 0) {
        if (str[x - 1][y] != 'x' || str[x - 1][y + 1] != 'x') {
            f = 0;
        }
        else if (str[x][y + 1] != 'x') {
            f = 0;
        }
        else if (str[x + 1][y] != 'x' || str[x + 1][y + 1] != 'x') {
            f = 0;
        }
    }

    f ? cout << "yes" : cout << "no";

    return 0;
}