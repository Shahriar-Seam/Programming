#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, f;

    cin >> t;

    while (t--) {
        cin >> n;

        string s[n];
        f = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') {
                    if (s[i][j + 1] == '1' && s[i + 1][j] == '1' && s[i + 1][j + 1] == '1') {
                        puts("SQUARE");
                    }
                    else {
                        puts("TRIANGLE");
                    }

                    f = 1;

                    break;
                }
            }

            if (f == 1) {
                break;
            }
        }
    }

    return 0;
}