#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 2e5 + 5;
const int mod = 998244353;
vector <int> fib(sz);

void fill()
{
    int i;

    for (i = 2, fib[1] = 1; i < sz; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
}

void solve()
{
    int n, q, x, single = 0, two = 0, i, a, b, score;

    cin >> n;

    vector <int> v(n);
    vector <pair <int, int> > h;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n - 1; i++) {
        single = max(single, v[i] + v[i + 1]);
    }

    for (i = 0; i < n - 1; i++) {
        h.push_back({max(v[i], v[i + 1]), min(v[i], v[i + 1])});
    }

    sort(h.begin(), h.end(), greater <> ());

    cin >> q;

    for (auto &it : h) {
        cout << it.first << " " << it.second << "\n";
    }

    while (q--) {
        cin >> x;

        if (x == 1) {
            cout << (single) % mod << " ";
        }
        else {
            score = 0;
            
            for (i = 0; i < min((int) h.size(), 50LL); i++) {
                a = h[i].first;
                b = h[i].second;

                score = max(score, ((((fib[x + 3] - 2) * a) % mod + ((fib[x + 2] - 1) * b) % mod) % mod + mod) % mod);
            }
            
            cout << score << " ";
        }
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}