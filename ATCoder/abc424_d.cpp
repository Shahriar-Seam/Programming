#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int h, w, i, j, count = 0;

    cin >> h >> w;

    vector <string> s(h);

    for (auto &it : s) {
        cin >> it;
    }

    for (i = 1; i < h - 1; i++) {
        for (j = 1; j < w - 1; j++) {
            if (s[i][j] == '#') {
                if (s[i][j + 1] == '.' ||
                    s[i][j - 1] == '.' ||
                    s[i + 1][j] == '.' ||
                    s[i - 1][j] == '.') {
                    continue;
                }
                else if ((s[i - 1][j - 1] == '.' && s[i - 1][j + 1] == '.') ||
                    (s[i + 1][j - 1] == '.' && s[i + 1][j + 1] == '.') ||
                    (s[i - 1][j - 1] == '.' && s[i + 1][j - 1] == '.') ||
                    (s[i - 1][j + 1] == '.' && s[i + 1][j + 1] == '.')) {
                    continue;
                }
                else {
                    s[i][j] = '.';

                    count++;
                }
            }
        }
    }

    for (i = 0; i < h - 1; i++) {
        for (j = 0; j < w - 1; j++) {
            if (s[i][j] == '#' &&
                s[i][j + 1] == '#' &&
                s[i + 1][j] == '#' &&
                s[i + 1][j + 1] == '#') {
                s[i + 1][j + 1] = '.';

                count++;
            }
        }
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}