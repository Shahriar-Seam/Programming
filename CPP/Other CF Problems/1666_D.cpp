#include <bits/stdc++.h>

using namespace std;

void replace(string &s, char c)
{
    int i;

    for (i = 0; i < (int) s.size(); i++) {
        if (s[i] == c) {
            s[i] = '0';
        }
    }
}

void solve()
{
    string s, t;
    int i, j, f = 1, temp_f;

    cin >> s >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (i = 0, j = 0; i < (int) t.size(); i++) {
        temp_f = 0;

        for (j; j < (int) s.size(); j++) {
            if (t[i] == s[j]) {
                temp_f = 1;

                j++;

                break;
            }
            else if (t[i] != s[j]) {
                replace(s, s[j]);
            }
        }

        if (!temp_f) {
            f = 0;

            break;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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