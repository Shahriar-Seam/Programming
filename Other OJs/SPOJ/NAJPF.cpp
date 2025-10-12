#include <bits/stdc++.h>

using namespace std;

#define int long long

const int x = 998244353;
const int mod = 1e9 + 7;
const int inv_x = 4924091;

int bin_exp(int b, int p, int m = mod)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

int _hash(string s)
{
    int h = 0, i, xx = 1;

    for (i = 0; i < s.size(); i++) {
        h = (h + s[i] * xx) % mod;

        xx = (xx * x) % mod;
    }

    return h;
}

void solve()
{
    string s, t;
    int i, h_s, h_t, xx;
    vector <int> v;

    cin >> s >> t;

    h_s = _hash(s.substr(0, t.size()));
    h_t = _hash(t);
    xx = bin_exp(x, t.size() - 1);

    if (h_s == h_t) {
        v.push_back(1);
    }

    for (i = t.size(); i < s.size(); i++) {
        h_s -= s[i - t.size()];
        h_s = (h_s * inv_x) % mod;
        h_s = (h_s + s[i] * xx) % mod;

        if (h_s == h_t) {
            v.push_back(i - t.size() + 2);
        }
    }

    if (v.empty()) {
        cout << "Not Found\n";
    }
    else {
        cout << v.size() << "\n";

        for (auto &it : v) {
            cout << it << " ";
        }

        cout << "\n";
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