#include <bits/stdc++.h>

using namespace std;

void solve(int tc)
{
    int n, i, ps = 0, is_s = 0, is_p = 0;
    string s;

    cin >> n >> s;

    // cout << tc << "\n";

    // pppp || ssss
    for (i = 0; i < n; i++) {
        if (s[i] == 'p' || s[i] == '.') {
            is_p++;
        }
        if (s[i] == 's' || s[i] == '.') {
            is_s++;
        }
    }

    if (is_s == n || is_p == n) {
        cout << "YES\n";

        return;
    }

    i = 0;

    while (s[i++] == '.');

    i--;

    if (s[i] == 's') {
        // sssp or sppp
        if (i == 0) {
            for (i = 1; i < n; i++) {
                // sssp
                if (s[i] == 's') {
                    for (i = i + 1; i < n - 1; i++) {
                        if (s[i] == 'p') {
                            cout << "NO\n";

                            return;
                        }
                    }

                    cout << "YES\n";

                    return;
                }
                // sppp
                else if (s[i] == 'p') {
                    for (i = i + 1; i < n; i++) {
                        if (s[i] == 's') {
                            cout << "NO\n";

                            return;
                        }
                    }

                    cout << "YES\n";

                    return;
                }
            }
        }
        // sssp
        else {
            for (i = i + 1; i < n - 1; i++) {
                if (s[i] == 'p') {
                    cout << "NO\n";

                    return;
                }
            }

            cout << "YES\n";
        }
    }
    // pppp
    else {
        for (i = i + 1; i < n; i++) {
            if (s[i] == 's') {
                cout << "NO\n";

                return;
            }
        }

        cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}