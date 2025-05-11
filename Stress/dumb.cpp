#include <bits/stdc++.h>

using namespace std;

int count(string s)
{
    vector <int> counter(26, 0);

    for (auto c : s) {
        counter[c - 'a']++;
    }

    for (auto it : counter) {
        if (it > (s.size() / 2)) {
            return 1;
        }
    }

    return 0;
}

int substrings(string s)
{
    int n = s.size(), i, j;

    for (i = 0; i < n; i++) {
        for (j = 3; i + j < n; j++) {
            if (count(s.substr(i, j))) {
                return 1;
            }
        }
    }

    return 0;
}

void solve()
{
    int n, q;
    string s;

    cin >> n >> q >> s;

    while (q--) {
        int l, r;

        cin >> l >> r;

        if (substrings(s.substr(l - 1, r - l + 1))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}