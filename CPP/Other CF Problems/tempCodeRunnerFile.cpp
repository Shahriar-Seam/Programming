#include <bits/stdc++.h>

using namespace std;

const int sz = 2e5 + 5;
vector <vector <int> > divisors(sz, vector <int> ());

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve()
{
    int n, count = 1, i, g;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &k : divisors[n]) {
        set <int> s;
        g = 0;

        for (i = 0; i + k < n; i++) {
            s.insert(abs(v[i] - v[i + k]));
        }

        for (auto it : s) {
            g = gcd(g, it);
        }

        count += ((g > 1) || (g == 0 && !s.empty()));
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}