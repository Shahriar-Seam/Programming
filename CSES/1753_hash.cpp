#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int x = 998244353;
const int inv_x = 4924091;

int Hash(string s)
{
    int h = 0, i, n = s.size();
    int xx = x;

    for (i = 0; i < n; i++) {
        h = (h + (s[i] * xx)) % mod;

        xx = (xx * x) % mod;
    }

    return h;
}

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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int h_s, h_t;
    int i, count = 0;
    int n, m;

    cin >> s >> t;

    n = s.size();
    m = t.size();

    h_s = Hash(s.substr(0, m));
    h_t = Hash(t);

    if (h_s == h_t) {
        count++;
    }

    for (i = m; i < n; i++) {
        h_s = (h_s * inv_x) % mod;
        h_s -= s[i - m];
        h_s = (h_s + s[i] * bin_exp(x, m)) % mod;

        if (h_s == h_t) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}