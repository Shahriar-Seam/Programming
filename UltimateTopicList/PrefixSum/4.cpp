#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q, i;
    int l, r, k;
    long long sum;

    cin >> n >> q;

    vector <long long> v(n), prefix(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    while (q--) {
        cin >> l >> r >> k;

        sum = prefix[n] - (prefix[r] - prefix[l - 1]) + k * (r - l + 1);

        cout << (sum & 1 ? "YES\n" : "NO\n");
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