#include <bits/stdc++.h>

using namespace std;

bool valid(string &s)
{
    int i, cnt = 0;

    for (i = 1; i < s.size(); i++) {
        if (s[i] == '0' && s[i - 1] == '0') {
            return true;
        }
        else if (s[i] == '0') {
            cnt++;
        }
    }

    return cnt % 2 == 0;
}

void solve()
{
    int n, i, f = 0;
    string s;

    cin >> n >> s;

    vector <int> zero;
    vector <string> chunks;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero.push_back(i);
        }
    }

    if (zero.size() == 0) {
        cout << "YES\n";

        return;
    }
    else if (zero.size() == 1) {
        if (zero[0] == 0 || zero[0] == n - 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        return;
    }
    else if (zero.size() == 2) {
        if (zero[1] - zero[0] <= 2 || (zero[0] == 0 && zero[1] == n - 1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        return;
    }
    else {
        string t;
        int cnt = 0;
        i = 0;

        if (s[0] == '1') {
            while (i < n && s[i] == '1') {
                i++;
            }

            t = "1";
        }

        for (i; i < n; ) {
            if (s[i] == '0') {
                cnt = 0;

                while (i < n && s[i] == '0') {
                    i++;

                    cnt++;
                }

                if (cnt > 1) {
                    t += "00";
                }
                else {
                    t += "0";
                }
            }
            else {
                cnt = 0;

                while (i < n && s[i] == '1') {
                    i++;

                    cnt++;
                }

                if (cnt > 1) {
                    t += "1";

                    chunks.push_back(t);

                    t = "1";
                }
                else {
                    t += "1";
                }
            }
        }

        chunks.push_back(t);

        for (i = 0; i < chunks.size() - 1; i++) {
            if (chunks[i][0] == '1') {
                if (!valid(chunks[i])) {
                    cout << "NO\n";

                    return;
                }
            }
        }

        if (chunks.back().back() == '1' && chunks.back().front() == '1') {
            if (!valid(chunks[chunks.size() - 1])) {
                cout << "NO\n";

                return;
            }
        }

        cout << "YES\n";
    }
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