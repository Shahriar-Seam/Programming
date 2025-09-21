#include <bits/stdc++.h>

using namespace std;

bool valid(vector <int> &v, string &s, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i == 0) {
                if (v[i] < v[i + 1] && v[i] == 1) {
                    return false;
                }

                continue;
            }

            if (i == n - 1 && v[i] == n) {
                if (v[i - 1] < v[i]) {
                    return false;
                }

                continue;
            }

            if (v[i - 1] < v[i] && v[i] < v[i + 1]) {
                if (v[i] == i + 1) {
                    return false;
                }
            }
        }
        else {
            if (i == 0) {
                if (v[i] != 1) {
                    return false;
                }

                continue;
            }

            if (i == n - 1) {
                if (v[i] != n) {
                    return false;
                }

                continue;
            }

            if (v[i - 1] > v[i] || v[i] > v[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int n, i, l, r;
    string s;
    set <int> ss;

    cin >> n >> s;

    vector <int> v(n, 0);

    for (i = 1; i <= n; i++) {
        ss.insert(i);
    }

    l = 1;
    r = n;

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i > 0 && v[i - 1] == 0) {
                v[i - 1] = l;

                ss.erase(l);

                l++;
            }

            v[i] = i + 1;

            l = i + 2;

            ss.erase(i + 1);

            if (i < n - 1 && s[i + 1] == '0') {
                v[i + 1] = 0;

                // ss.erase(r);

                // r--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            v[i] = *ss.begin();

            ss.erase(ss.begin());
        }
    }

    for (i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '0') {
            if (v[i] > v[i - 1]) {
                swap(v[i], v[i - 1]);

                i++;
            }
        }
    }

    if (s[n - 1] == '0' && v[n - 1] == n) {
        swap(v[n - 1], v[n - 2]);
    }
    
    if (valid(v, s, n)) {
        cout << "YES\n";

        for (auto &it : v) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
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