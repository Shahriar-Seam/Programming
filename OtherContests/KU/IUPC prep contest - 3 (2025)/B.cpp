#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int AND(vector <int> &counter, int x)
{
    int sum = 0, i;

    for (i = 0; i < counter.size(); i++) {
        if (counter[i] > 0) {
            sum = (sum + (counter[i] * ((x & (1LL << i)) % mod)) % mod) % mod;
        }
    }

    return sum;
}

int OR(vector <int> &counter, int x, int n)
{
    int sum = 0, i;

    for (i = 0; i < counter.size(); i++) {
        if (counter[i] > 0) {
            if (x & (1LL << i)) {
                sum = (sum + (n * ((1LL << i) % mod)) % mod) % mod;
            }
            else {
                sum = (sum + ((counter[i] * ((1LL << i) % mod)) % mod)) % mod;
            }
        }
    }

    return sum;
}

void solve()
{
    int n, i, j, k, sum = 0;

    cin >> n;

    vector <int> v(n), counter(62, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 60; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if ((1LL << i) & v[j]) {
                counter[i]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        sum = (sum + (AND(counter, v[i]) * OR(counter, v[i], n)) % mod) % mod;
    }

    cout << sum << "\n";
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