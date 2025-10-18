#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int x = 998244353;
const int inv_x = 4924091;

int strto128t(string &s)
{
    int n = 0;
    
    for (auto &c : s) {
        n = n * 10;
        n += (c - '0');
    }

    return n;
}

vector <int> _hash(string &s, vector <int> &p, vector <int> &h)
{
    int i, n = s.size();
    int xx = x;

    h.assign(n, 0);

    for (i = 1, h[0] = s[0], p.emplace_back(1); i < n; i++) {
        h[i] = (((h[i - 1] + (s[i] * xx) % mod + mod) % mod) + mod) % mod;

        p.emplace_back(xx);

        xx = ((xx * x) % mod + mod) % mod;
    }

    p.emplace_back(xx);

    return h;
}

int sub_hash(vector <int> &h, int l, int r)
{
    int H;

    if (l == 0) {
        H = h[r - 1];
    }
    else {
        H = ((h[r - 1] - h[l - 1]) % mod + mod) % mod;
    }

    return H;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, j, n, f;
    vector <int> h, p, v;

    cin >> s;

    n = s.size();
    _hash(s, p, h);

    for (i = 1; i <= n; i++) {
        f = 1;

        for (j = i; j < n; j += i) {
            if (j + i <= n && (((h[i - 1] * p[j]) % mod + mod) % mod) != sub_hash(h, j, j + i)) {
                f = 0;
            }
            else if (j + i > n) {
                if ((((h[(n % i) - 1] * p[j]) % mod + mod) % mod) != sub_hash(h, j, j + (n % i))) {
                    f = 0;
                }
            }

            if (!f) {
                break;
            }
        }

        if (f) {
            v.emplace_back(i);
        }
    }
    
    for (auto &it : v) {
        cout << it << " ";
    }

    return 0;
}