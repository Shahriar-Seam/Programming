#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;
const int sz = 2e5 + 5;
vector <int> fact(sz, 1);

void fill()
{
    int i;

    for (i = 2; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

void solve()
{
    string s;
    int n, i, j, k = 0, count, diff_ops = 1;

    cin >> s;

    n = s.size();

    for (i = 0; i < n; ) {
        j = i;
        count = 0;

        while (j < n && s[j] == s[i]) {
            count++;

            j++;
        }

        diff_ops = (diff_ops * count) % mod;

        i = j;
        k++;
    }

    cout << n - k << " " << (diff_ops * fact[n - k]) % mod << "\n";
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