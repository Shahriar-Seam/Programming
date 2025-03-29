#include <bits/stdc++.h>

using namespace std;

bool insert(string &s, char c, vector <int> &v)
{
    int i;

    if (c == 'L') {
        for (i = 0; i < s.size() - 1; i++) {
            if ((s[i] == 'I' && s[i + 1] == 'T') || s[i] == 'T' && s[i + 1] == 'I') {
                s.insert(s.begin() + i + 1, 'L');

                v.push_back(i);

                return true;
            }
        }
    }
    else if (c == 'I') {
        for (i = 0; i < s.size() - 1; i++) {
            if ((s[i] == 'L' && s[i + 1] == 'T') || s[i] == 'T' && s[i + 1] == 'L') {
                s.insert(s.begin() + i + 1, 'I');

                v.push_back(i);

                return true;
            }
        }
    }
    else if (c == 'T') {
        for (i = 0; i < s.size() - 1; i++) {
            if ((s[i] == 'L' && s[i + 1] == 'I') || s[i] == 'I' && s[i + 1] == 'L') {
                s.insert(s.begin() + i + 1, 'T');

                v.push_back(i);

                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n, i, a, b, c;
    string s;
    map <char, int> mp;
    vector <int> v;

    cin >> n >> s;

    for (auto c : s) {
        mp[c]++;
    }

    if (mp.size() == 1) {
        cout << -1 << "\n";

        return;
    }

    a = mp['L'];
    b = mp['I'];
    c = mp['T'];

    if (a == b && b == c) {
        cout << 0 << "\n";

        return;
    }

    if (max({a, b, c}) == a) {
        while (a - b > 0) {
            if (!insert(s, 'I', v)) {
                cout << -1 << "\n";

                return;
            }

            b++;
        }

        while (a - c > 0) {
            if (!insert(s, 'T', v)) {
                cout << -1 << "\n";

                return;
            }

            c++;
        }
    }
    else if (max({a, b, c}) == b) {
        while (b - a > 0) {
            if (!insert(s, 'L', v)) {
                cout << -1 << "\n";

                return;
            }

            a++;
        }

        while (b - c > 0) {
            if (!insert(s, 'T', v)) {
                cout << -1 << "\n";

                return;
            }

            c++;
        }
    }
    else if (max({a, b, c}) == c) {
        while (c - a > 0) {
            if (!insert(s, 'L', v)) {
                cout << -1 << "\n";

                return;
            }

            a++;
        }

        while (c - b > 0) {
            if (!insert(s, 'I', v)) {
                cout << -1 << "\n";

                return;
            }

            b++;
        }
    }

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << it + 1 << " ";
    }

    cout << "\n";

    cout << s << "\n";
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