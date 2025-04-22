#include <bits/stdc++.h>

using namespace std;

int _cost(string s, int n)
{
    int i, cost = 0;

    if (s[0] == '1') {
        cost += 2;
    }
    else {
        cost++;
    }

    for (i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            cost += 2;
        }
        else {
            cost++;
        }
    }

    return cost;
}

void solve()
{
    int n, i, cost = 0, temp;
    string s;

    cin >> n >> s;

    if (count(s.begin(), s.end(), '0') == 0 || count(s.begin(), s.end(), '1') == 0) {
        cout << _cost(s, n) << "\n";

        return;
    }

    if (s[0] == '1') {
        for (i = 0; i < n; i++) {
            if (s[i] == '0') {
                while (i < n && s[i] == '0') {
                    i++;
                }

                reverse(s.begin(), s.begin() + i);

                cout << _cost(s, n) << "\n";

                return;
            }
        }
    }
    else {
        if (count(s.begin() + 1, s.end(), '0') == 0) {
            cout << _cost(s, n) << "\n";
    
            return;
        }

        for (i = 0; i < n; i++) {
            if (s[i] == '1') {
                temp = i;

                while (i < n && s[i] == '1') {
                    i++;
                }

                if (i < n && s[i] == '0') {
                    while (i < n && s[i] == '0') {
                        i++;
                    }
                }

                reverse(s.begin() + temp, s.begin() + i);

                cout << _cost(s, n) << "\n";

                return;
            }
        }
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